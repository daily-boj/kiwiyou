use std::io::{stdin, BufRead};

fn main() {
    let stdin = stdin();
    let mut handle = stdin.lock();
    let mut line = String::new();
    handle.read_line(&mut line).unwrap();
    let money: u32 = line
        .split_ascii_whitespace()
        .nth(1)
        .unwrap()
        .parse()
        .unwrap();
    let coins: Vec<u32> = handle
        .lines()
        .flatten()
        .map(|line| line.parse())
        .flatten()
        .collect();
    let (_, count) = coins.into_iter().rfold((money, 0), |(money, count), coin| {
        (money % coin, count + money / coin)
    });
    println!("{}", count);
}

