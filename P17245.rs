use std::fs::File;
use std::io::{BufReader, Read};
use std::os::unix::io::FromRawFd;

fn main() {
    let stdin: File = unsafe { FromRawFd::from_raw_fd(0) };
    let mut reader = BufReader::with_capacity(65536, stdin);
    let mut full = String::with_capacity(9000000);
    reader.read_to_string(&mut full).unwrap();
    let tower: Vec<u64> =
    full.split_ascii_whitespace()
        .skip(1)
        .map(str::parse)
        .map(Result::unwrap)
        .collect();
    let sum = tower.iter().sum();
    let mut low = 0u64;
    let mut high = 5_000_001u64;
    while low < high {
        let mid = (low + high) >> 1;
        let on_pc = tower.iter().map(|n| std::cmp::min(*n, mid)).sum::<u64>() << 1;
        if on_pc < sum {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    println!("{}", low);
}
