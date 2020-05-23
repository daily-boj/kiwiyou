use std::io::{stdin, Read};

fn main() {
	let stdin = stdin();
	let mut handle = stdin.lock();
	let mut input = String::new();
	handle.read_to_string(&mut input).unwrap();
	let mut split = input.split_ascii_whitespace().map(str::parse::<u64>);
	let min = split.next().unwrap().unwrap();
	let max = split.next().unwrap().unwrap();
	let mut is_checked = [false; 1_000_001];
	let is_checked = &mut is_checked[..(max - min + 1) as usize];
	for root in 2..=((max as f64).sqrt() as u64) {
		let squared = root * root;
		let starting = (min + squared - 1) / squared;
		let range = starting..=max / squared;
		for mult in range {
			is_checked[(squared * mult - min) as usize] = true;
		}
	}
	let count = is_checked.iter().filter(|x| !**x).count();
	println!("{}", count);
}
