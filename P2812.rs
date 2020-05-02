use std::fs::File;
use std::io::{BufReader, BufWriter, Read, Write};
use std::os::unix::io::FromRawFd;

fn main() {
    let mut handle = BufReader::with_capacity(512000, unsafe { File::from_raw_fd(0) });
    let mut line = String::with_capacity(512000);
    handle.read_to_string(&mut line).unwrap();
    let mut split = line.split_ascii_whitespace().skip(1);
    let mut remove: usize = split.next().unwrap().parse().unwrap();
    let mut number = split.next().unwrap().as_bytes();
    let mut result = Vec::new();
    while remove > 0 && remove < number.len() {
        let mut max = 0usize;
        for (i, byte) in number.iter().take(remove + 1).enumerate() {
            if number[max] < *byte {
                max = i;
            }
            if number[max] == b'9' {
                break;
            }
        }
        remove -= max;
        result.push(number[max]);
        number = &number[(max + 1)..];
    }
    result.extend_from_slice(&number[..number.len() - remove]);
    let mut handle = BufWriter::with_capacity(50000, unsafe { File::from_raw_fd(1) });
    handle.write(&result).unwrap();
}
