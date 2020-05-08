use std::{io::Read, fs::File, os::unix::io::FromRawFd};
use std::mem::{MaybeUninit, transmute};

fn main() {
    let mut buffer = {
        let uninit = [MaybeUninit::<u8>::uninit(); 2_000_001];
        unsafe { transmute::<_, [u8; 2_000_001]>(uninit) }
    };
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let len = stdin.read(&mut buffer).unwrap();
    let input = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    let mut split = input.split('\n');
    let haystack = split.next().unwrap();
    let needle = split.next().unwrap();
    if haystack.contains(needle) {
        println!("1");
    } else {
        println!("0");
    }
}
