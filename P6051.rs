extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = usize;

struct Commit {
    recent: i32,
    prev: usize,
}

use std::fs::File;
use std::os::unix::io::FromRawFd;
use std::io::{BufWriter, Write};

fn main() {
    let mut inputs = input(800006);
    let query_len = next(&mut inputs);
    let mut state: Vec<usize> = Vec::with_capacity(query_len);
    let mut arena = Vec::with_capacity(query_len);
    state.push(0);
    arena.push(Commit { recent: -1, prev: 0 });
    let mut current = 0;
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    for _ in 0..query_len {
        let op = unsafe { *inputs };
        inputs = unsafe { inputs.offset(2) };
        match op {
            b'a' => {
                let recent = next(&mut inputs) as i32;
                arena.push(Commit { recent, prev: current });
                current = arena.len() - 1;
            }
            b's' => {
                current = arena[current].prev;
            }
            b't' => {
                let revert_to = next(&mut inputs) as usize;
                current = state[revert_to - 1];
            }
            _ => unsafe { std::hint::unreachable_unchecked() },
        }
        state.push(current);
        let _ = stdout.write_fmt(format_args!("{}\n", arena[current].recent));
    }
}