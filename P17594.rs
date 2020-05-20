use std::fs::File;
use std::hint::unreachable_unchecked;
use std::io::Read;
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
	let mut buffer = Vec::<u8>::with_capacity(12_000_008);
	unsafe { buffer.set_len(12_000_008) };
	let mut stdin = unsafe { File::from_raw_fd(0) };
	let len = stdin.read(&mut buffer[..]).unsafe_unwrap();
	let s = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
	let mut iter = s.split_ascii_whitespace().map(str::parse::<i32>).map(Result::unsafe_unwrap);
	let count = iter.next().unsafe_unwrap() as usize;
	let mut numbers: [i32; 1000000] = unsafe { MaybeUninit::uninit().assume_init() };
	let numbers = &mut numbers[..count];
	let mut current_sum = 0i64;
	let mut max_average = 0f64;
	for (i, number) in iter.enumerate() {
		current_sum += number as i64;
		let current_average = current_sum as f64 / ((i + 1) as f64);
		if current_average > max_average {
			max_average = current_average;
		}
		numbers[i] = number;
	}
	current_sum = 0;
	for i in 0..numbers.len() {
		current_sum += numbers[numbers.len() - i - 1] as i64;
		let current_average = current_sum as f64 / ((i + 1) as f64);
		if current_average > max_average {
			max_average = current_average;
		}
	}
	println!("{:.9}", max_average);
}
