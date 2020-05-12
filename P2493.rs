use std::fs::File;
use std::hint::unreachable_unchecked;
use std::io::{BufWriter, Read, Write};
use std::mem::MaybeUninit;
use std::os::unix::io::FromRawFd;

trait UnsafeUnwrap<T> {
    fn unsafe_unwrap(self) -> T;
}

impl<T> UnsafeUnwrap<T> for Option<T> {
    fn unsafe_unwrap(self) -> T {
        self.unwrap_or_else(|| unsafe { unreachable_unchecked() })
    }
}

impl<T, E> UnsafeUnwrap<T> for Result<T, E> {
    fn unsafe_unwrap(self) -> T {
        self.unwrap_or_else(|_| unsafe { unreachable_unchecked() })
    }
}

fn main() {
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let mut buffer: [u8; 5_000_007] = unsafe { MaybeUninit::uninit().assume_init() };
    let len = stdin.read(&mut buffer).unsafe_unwrap();
    let input_str = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    let mut input = input_str
        .split_ascii_whitespace()
        .map(str::parse::<u32>)
        .map(UnsafeUnwrap::unsafe_unwrap);
    let count = input.next().unsafe_unwrap() as usize;
    let mut towers = Vec::with_capacity(count);
    input.for_each(|v| towers.push(v));
    let mut stack = Vec::with_capacity(count);
    let mut result = Vec::with_capacity(count);
    unsafe { result.set_len(count) };
    for i in (0..count).rev() {
        let height = towers[i];
        while let Some(lowest) = stack.last().copied() {
            if towers[lowest as usize] < height {
                stack.pop();
                result[lowest as usize] = (i + 1) as u32;
            } else {
                break;
            }
        }
        stack.push(i);
    }
    stack.iter().for_each(|i| result[*i as usize] = 0);
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    for i in 0..count {
        stdout.write_fmt(format_args!("{} ", result[i])).unsafe_unwrap();
    }
}
