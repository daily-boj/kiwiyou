use std::cmp::min;
use std::io::{stdin, BufRead};

fn main() {
    let stdin = stdin();
    let handle = stdin.lock();
    let (r, g, b) = handle
        .lines()
        .skip(1)
        .flatten()
        .map(|line| {
            line.trim()
                .split(' ')
                .filter_map(|cost| cost.parse().ok())
                .collect::<Box<[u32]>>()
        })
        .fold((0, 0, 0), |(r, g, b), costs| {
            (
                min(g + costs[0], b + costs[0]),
                min(r + costs[1], b + costs[1]),
                min(r + costs[2], g + costs[2]),
            )
        });
    println!("{}", min(r, min(g, b)));
}
