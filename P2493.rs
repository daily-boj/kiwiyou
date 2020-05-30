use std::fs::File;
use std::io::{BufWriter, Write};
use std::mem::MaybeUninit;
use std::os::unix::io::FromRawFd;

extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = u32;

fn main() {
    let mut inputs = input(5_000_007);
    let count = next(&mut inputs) as usize;
    let mut towers: [u32; 500000] = unsafe { MaybeUninit::uninit().assume_init() };
    for i in 0..count {
        towers[i] = next(&mut inputs);
    }
    let mut stack = Vec::with_capacity(count);
    let mut result = [0u32; 500000];
    for i in (0..count).rev() {
        let height = towers[i];
        while let Some(lowest) = stack.pop() {
            if towers[lowest as usize] < height {
                result[lowest as usize] = (i + 1) as u32;
            } else {
                stack.push(lowest);
                break;
            }
        }
        stack.push(i);
    }
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    for i in 0..count {
        let _ = stdout.write_fmt(format_args!("{} ", result[i]));
    }
}
