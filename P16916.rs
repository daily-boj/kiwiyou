use std::{io::Read, fs::File, os::unix::io::FromRawFd};

fn main() {
    let mut buffer = {
        let mut uninit = Vec::<u8>::with_capacity(2_000_001);
        unsafe { uninit.set_len(2_000_001) };
        uninit
    };
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let len = stdin.read(&mut buffer).unwrap();
    let buffer = &buffer[..len];
    let mut split = buffer.split(|b| *b == b'\n');
    let haystack = split.next().unwrap();
    let needle = split.next().unwrap();
    let mut retry = {
        let mut uninit = Vec::<usize>::with_capacity(needle.len());
        unsafe { uninit.set_len(needle.len()) };
        uninit
    };
    retry[0] = 0;
    let mut offset = 0;
    for i in 1..needle.len() {
        while offset > 0 && needle[i] != needle[offset] {
            offset = retry[offset - 1];
        }
        if needle[i] == needle[offset] {
            offset += 1;
            retry[i] = offset;
        }
    }
    offset = 0;
    let mut found = false;
    for i in 0..haystack.len() {
        while offset > 0 && haystack[i] != needle[offset] {
            offset = retry[offset - 1];
        }
        if haystack[i] == needle[offset] {
            offset += 1;
            if offset == needle.len() {
                found = true;
                break;
            }
        }
    }
    if found {
        println!("1");
    } else {
        println!("0");
    }
}
