use std::io::Read;
use std::fs::File;
use std::os::unix::io::FromRawFd;
use std::mem::MaybeUninit;
use std::hint::unreachable_unchecked;
use std::cmp::Ordering::*;

trait UnsafeUnwrap<T> {
    fn unsafe_unwrap(self) -> T;
}

impl<T, E> UnsafeUnwrap<T> for Result<T, E> {
    fn unsafe_unwrap(self) -> T {
        self.unwrap_or_else(|_| unsafe { unreachable_unchecked() })
    }
}

#[inline(always)]
fn difference(a: u8, b: u8) -> u8 {
    match a.cmp(&b) {
        Greater => a - b,
        _ => b - a
    }
}

fn main() {
    let mut stdin = unsafe { File::from_raw_fd(0) };
    let mut buffer: [u8; 108] = unsafe { MaybeUninit::uninit().assume_init() };
    stdin.read(&mut buffer).unsafe_unwrap();
    let mut board = [false; 48];
    let mut prev_x = buffer[0] - b'A';
    let mut prev_y = buffer[1] - b'1';
    let start_x = prev_x;
    let start_y = prev_y;
    board[((prev_y << 3) | prev_x) as usize] = true;
    let mut failed = false;
    for i in 1..36 {
        let x = buffer[i * 3] - b'A';
        let y = buffer[i * 3 + 1] - b'1';
        let x_diff = difference(x, prev_x);
        let y_diff = difference(y, prev_y);
        let index = ((y << 3) | x) as usize;
        if x_diff * y_diff != 2 || board[index] {
            failed = true;
            break;
        }
        board[index] = true;
        prev_x = x;
        prev_y = y;
    }
    let x_diff = difference(start_x, prev_x);
    let y_diff = difference(start_y, prev_y);
    if x_diff * y_diff != 2 {
        failed = true;
    }
    if failed {
        println!("Invalid");
    } else {
        println!("Valid");
    }
}
