use std::fs::File;
use std::io::Read;
use std::os::unix::io::FromRawFd;

#[inline(always)]
fn unwrap_option<T>(option: Option<T>) -> T {
    option.unwrap_or_else(|| unsafe { std::hint::unreachable_unchecked() })
}

#[inline(always)]
fn unwrap_result<T, E>(result: Result<T, E>) -> T {
    result.unwrap_or_else(|_| unsafe { std::hint::unreachable_unchecked() })
}

fn parse(bytes: &[u8]) -> i32 {
    if bytes[0] == b'-' {
        -bytes[1..].iter().fold(0, |res, v| res * 10 + (v - b'0') as i32)
    } else {
        bytes.iter().fold(0, |res, v| res * 10 + (v - b'0') as i32)
    }
}

fn main() {
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let mut buffer = [0u8; 24 * 100000 + 7];
    let len = unwrap_result(stdin.read(&mut buffer));
    let mut numbers = buffer[..len]
        .split(|b| *b == b' ' || *b == b'\n')
        .map(|bytes| parse(bytes));
    let numbers_count = unwrap_option(numbers.next()) as usize;
    let mut numbers = numbers.take(numbers_count << 1);
    let mut ranges_from = [0i32; 100000];
    let mut ranges_to = [0i32; 100000];
    let mut size = 1;
    ranges_from[0] = unwrap_option(numbers.next());
    ranges_to[0] = unwrap_option(numbers.next());
    while let Some(from) = numbers.next() {
        let to = unwrap_option(numbers.next());
        let last_from = ranges_from[size - 1];
        let last_to = ranges_to[size - 1];
        if last_from <= from && last_to >= from {
            if last_to < to {
                ranges_to[size - 1] = to;
            }
        } else {
            ranges_from[size] = from;
            ranges_to[size] = to;
            size += 1;
        }
    }
    let mut length = 0;
    for i in 0..size {
        length += ranges_to[i];
        length -= ranges_from[i];
    }
    println!("{}", length);
}
