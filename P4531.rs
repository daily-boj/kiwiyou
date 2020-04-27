use std::io::{stdin, BufRead};

#[inline]
fn convert_roman(c: u8) -> i32 {
    match c {
        b'I' => 1,
        b'V' => 5,
        b'X' => 10,
        b'L' => 50,
        b'C' => 100,
        b'D' => 500,
        b'M' => 1000,
        _ => 0,
    }
}

fn main() {
    let stdin = stdin();
    let mut handle = stdin.lock();
    let mut count = String::new();
    handle.read_line(&mut count).unwrap();
    for _ in 0..count.trim().parse::<u32>().unwrap() {
        let mut line = String::new();
        handle.read_line(&mut line).unwrap();
        let mut result = 0;
        let bytes = line.into_bytes();
        for window in bytes.windows(2) {
            let current = convert_roman(window[0]);
            let next = convert_roman(window[1]);
            if current < next {
                result -= current;
            } else {
                result += current;
            }
        }
        println!("{}", result);
    }
}
