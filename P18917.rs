extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = u64;

fn main() {
    use std::io::{BufWriter, Write};
    let mut inputs = input(11_000_007);
    let mut sum = 0;
    let mut xor = 0;
    let mut stdout = BufWriter::with_capacity(524288, unsafe { <std::fs::File as std::os::unix::io::FromRawFd>::from_raw_fd(1) });
    for _ in 0..next(&mut inputs) {
        let op = next(&mut inputs);
        match op {
            1 => {
                let x = next(&mut inputs);
                sum += x;
                xor ^= x;
            }
            2 => {
                let x = next(&mut inputs);
                sum -= x;
                xor ^= x;
            }
            3 => stdout.write_fmt(format_args!("{}\n", sum)).unwrap(),
            4 => stdout.write_fmt(format_args!("{}\n", xor)).unwrap(),
            _ => unsafe { std::hint::unreachable_unchecked() }
        }
    }
}