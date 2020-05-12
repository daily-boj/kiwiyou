use std::cmp::Ordering;
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

const TABLE: [u8; 25] = [
    0, 1, 0, 3, 4, 0, 5, 6, 7, 0, 2, 8, 9, 10, 12, 13, 0, 14, 15, 16, 17, 0, 18, 0, 19,
];

fn cmp(a: &&[u8], b: &&[u8]) -> Ordering {
    let a = *a;
    let b = *b;
    let mut a_i = 0;
    let mut b_i = 0;
    let a_len = a.len();
    let b_len = b.len();
    while a_i < a_len && b_i < b_len {
        let mut a_num = TABLE[(a[a_i] - b'a') as usize];
        if a_num == 10 && a.get(a_i + 1) == Some(&b'g') {
            a_num += 1;
            a_i += 1;
        }
        let mut b_num = TABLE[(b[b_i] - b'a') as usize];
        if b_num == 10 && b.get(b_i + 1) == Some(&b'g') {
            b_num += 1;
            b_i += 1;
        }
        match a_num.cmp(&b_num) {
            ord @ Ordering::Greater | ord @ Ordering::Less => return ord,
            _ => {}
        }
        a_i += 1;
        b_i += 1;
    }
    (a_len - a_i).cmp(&(b_len - b_i))
}

fn main() {
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let mut buffer: [u8; 51005] = unsafe { MaybeUninit::uninit().assume_init() };
    let len = stdin.read(&mut buffer).unsafe_unwrap();
    let mut input = buffer[..len].split(|c| *c == b'\n');
    let count = unsafe { std::str::from_utf8_unchecked(&input.next().unsafe_unwrap()) }
        .parse()
        .unsafe_unwrap();
    let mut inputs = Vec::with_capacity(count);
    let mut total_size = 0usize;
    input.take(count).for_each(|r| {
        total_size += r.len() + 1;
        inputs.push(r)
    });
    inputs.sort_unstable_by(cmp);
    let mut output = Vec::with_capacity(total_size);
    unsafe { output.set_len(total_size) };
    let mut cursor = &mut output[..];
    for input in &inputs {
        cursor[..input.len()].copy_from_slice(input);
        cursor[input.len()] = b'\n';
        cursor = &mut cursor[input.len() + 1..];
    }
    let mut stdout = unsafe { File::from_raw_fd(1) };
    stdout.write(&output);
}
