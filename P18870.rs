use std::{os::unix::io::FromRawFd, fs::File, mem::MaybeUninit};
use std::io::{Read, Write, BufWriter};

fn uninit_vec<T>(size: usize) -> Vec<T> {
    let mut uninit = Vec::with_capacity(size);
    unsafe { uninit.set_len(size) };
    uninit
}

fn main() {
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let mut buffer = uninit_vec(7 + 1 + 12 * 1_000_000);
    let len = stdin.read(&mut buffer).unwrap();
    let input_str = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    let mut input = input_str.split_ascii_whitespace().map(|num| num.parse::<i32>().unwrap());
    let size = input.next().unwrap() as usize;
    let mut numbers: [i32; 1_000_000] = unsafe { MaybeUninit::uninit().assume_init() };
    let mut inputs: [i32; 1_000_000] = unsafe { MaybeUninit::uninit().assume_init() };
    let numbers = &mut numbers[..size];
    for (i, num) in input.enumerate() {
        numbers[i] = num;
        inputs[i] = num;
    }
    numbers.sort();
    let mut indices = uninit_vec::<usize>(1_000_000);
    indices[0] = 0;
    for i in 1..size {
        indices[i] = indices[i - 1];
        if numbers[i] != numbers[i - 1] {
            indices[i] += 1;
        }
    }
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    for i in 0..size {
        let index = indices[numbers.binary_search(&inputs[i]).unwrap()];
        let mut s = index.to_string();
        s.push(' ');
        stdout.write(s.as_bytes()).unwrap();
    }
}