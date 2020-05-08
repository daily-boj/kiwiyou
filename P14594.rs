use std::io::Read;
use std::fs::File;
use std::os::unix::io::FromRawFd;

fn main() {
    let mut buffer = [0u8; 1024];
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let len = stdin.read(&mut buffer).unwrap();
    let input_str = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    let mut input = input_str.split_ascii_whitespace().map(parse);
    let room_size = input.next().unwrap();
    let mut rooms = [0u8; 101];
    let action_count = input.next().unwrap();
    for _ in 0..action_count {
        let x = input.next().unwrap();
        let y = input.next().unwrap();
        for room in &mut rooms[x + 1..=y] { *room = 1; }
    }
    println!("{}", rooms[1..=room_size].iter().filter(|room| **room == 0).count());
}

fn parse(s: &str) -> usize {
    let mut result = 0;
    for byte in s.as_bytes() {
        result *= 10;
        result += (byte - b'0') as usize;
    }
    result
}
