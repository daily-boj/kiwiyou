use std::collections::HashMap;
use std::io::{stdin, Read, Write, BufWriter};
use std::fs::File;
use std::os::unix::io::FromRawFd;

fn main() {
    let stdin = stdin();
    let mut lock = stdin.lock();
    let mut buffer = String::with_capacity(8000000);
    lock.read_to_string(&mut buffer).unwrap();
    let mut inputs = buffer.split_ascii_whitespace();
    let available: usize = inputs.next().unwrap().parse().unwrap();
    let length = inputs.next().unwrap().parse().unwrap();
    let mut queue = Vec::with_capacity(length);
    let mut listed = HashMap::with_capacity(length);
    for (i, line) in inputs.enumerate() {
        if let Some(index) = listed.insert(line, i) {
            queue[index] = None;
        }
        queue.push(Some(line));
    }
    let mut stdout = BufWriter::with_capacity(65535, unsafe { File::from_raw_fd(1) });
    queue
        .iter()
        .flatten()
        .take(available)
        .for_each(|student| {
            stdout.write(student.as_bytes()).unwrap();
            stdout.write(b"\n").unwrap();
        });
}
