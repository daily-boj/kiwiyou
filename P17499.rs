use std::fs::File;
use std::hint::unreachable_unchecked;
use std::io::{Read, Write};
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
    let mut buffer: [u8; 4_600_014] = unsafe { MaybeUninit::uninit().assume_init() };
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let len = stdin.read(&mut buffer).unsafe_unwrap();
    let s = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    let mut inputs = s.split_ascii_whitespace();
    let size = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
    let query_count = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
    let mut sequence: [i32; 200_000] = unsafe { MaybeUninit::uninit().assume_init() };
    for i in 0..size {
        sequence[i] = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
    }
    let mut offset = 0;
    for _ in 0..query_count {
        let op = inputs.next().unsafe_unwrap();
        match op.as_bytes()[0] {
            b'1' => {
                let index: usize = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
                let add: i32 = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
                sequence[(offset + index - 1) % size] += add;
            }
            b'2' => {
                let shift: usize = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
                offset += size - shift;
            }
            b'3' => {
                let shift: usize = inputs.next().unsafe_unwrap().parse().unsafe_unwrap();
                offset += shift;
            }
            _ => unsafe { unreachable_unchecked() },
        }
    }
    let mut output = String::with_capacity(10 * size);
    for i in 0..size {
        let s = sequence[(offset + i) % size].to_string();
        output.push_str(&s);
        output.push(' ');
    }
    let mut stdout = unsafe { File::from_raw_fd(1) };
    stdout.write(output.as_bytes()).unsafe_unwrap();
}
