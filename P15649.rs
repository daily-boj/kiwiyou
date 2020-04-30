use std::fs::File;
use std::io::{stdin, BufWriter, Write};
use std::os::unix::io::FromRawFd;

fn print_permutation_element(
    writer: &mut impl Write,
    mut marker: u32,
    len: u32,
    depth: u32,
    buffer: &mut [u8],
    buf_end: usize,
) {
    if depth == 0 {
        for i in 0..len {
            let mask = 1 << i;
            if (marker & mask) == 0 {
                writer.write(&buffer[..buf_end]).unwrap();
                writer.write(&[b'1' + i as u8, b'\n']).unwrap();
            }
        }
    } else {
        for i in 0..len {
            let mask = 1 << i;
            if (marker & mask) == 0 {
                marker |= mask;
                buffer[buf_end] = b'1' + i as u8;
                buffer[buf_end + 1] = b' ';
                print_permutation_element(writer, marker, len, depth - 1, buffer, buf_end + 2);
                marker &= !mask;
            }
        }
    }
}

fn main() {
    let (n, m): (u32, u32) = {
        let mut line = String::new();
        let stdin = stdin();
        stdin.read_line(&mut line).unwrap();
        let mut iter = line.split_ascii_whitespace().map(str::parse);
        (iter.next().unwrap().unwrap(), iter.next().unwrap().unwrap())
    };
    let stdout: File = unsafe { FromRawFd::from_raw_fd(1) };
    let mut handle = BufWriter::with_capacity(65536, stdout);
    let mut buffer = [0u8; 32];
    print_permutation_element(&mut handle, 0, n, m - 1, &mut buffer, 0);
}
