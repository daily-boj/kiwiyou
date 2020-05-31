use std::fs::File;
use std::io::{BufWriter, Write};
use std::mem::MaybeUninit;
use std::os::unix::io::FromRawFd;

extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = u32;

fn main() {
    let mut inputs = input(3_300_014);
    let point_count = next(&mut inputs) as usize;
    let line_count = next(&mut inputs) as usize;
    let mut points: [u32; 100_000] = unsafe { MaybeUninit::uninit().assume_init() };
    let points = &mut points[..point_count];
    for i in 0..point_count {
        points[i] = next(&mut inputs);
    }
    points.sort_unstable();
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    for _ in 0..line_count {
        let left = next(&mut inputs);
        let right = next(&mut inputs);
        let mut low = 0;
        let mut count = point_count;
        while count > 0 {
            let step = count >> 1;
            let mid = low + step;
            if points[mid] < left {
                low = mid + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        let mut high = 0;
        count = point_count;
        while count > 0 {
            let step = count >> 1;
            let mid = high + step;
            if points[mid] <= right {
                high = mid + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        let _ = stdout.write_fmt(format_args!("{}\n", high - low));
    }
}