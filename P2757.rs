use std::io::{stdin, BufRead};

fn to_alpha(mut column: u32) -> String {
    let mut buffer = Vec::new();
    while column > 0 {
        column -= 1;
        buffer.push((column % 26) as u8 + b'A');
        column /= 26;
    }
    buffer.reverse();
    unsafe { String::from_utf8_unchecked(buffer) }
}

fn main() {
    let stdin = stdin();
    let handle = stdin.lock();
    for line in handle.lines().flatten() {
        let mut splitter = line.trim_end().split(char::is_alphabetic).skip(1);
        let row = splitter.next().unwrap();
        let column = splitter.next().unwrap().parse::<u32>().unwrap();
        if row == "0" && column == 0 {
            break;
        } else {
            println!("{}{}", to_alpha(column), row);
        }
    }
}
