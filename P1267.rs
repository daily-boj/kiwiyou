use std::io::{stdin, BufRead};

fn main() {
    let stdin = stdin();
    let handle = stdin.lock();
    let mut lines = handle.lines().flatten();
    let count: usize = lines.next().unwrap().parse().unwrap();
    let mut bridges = Vec::with_capacity(count);
    for line in lines.take(count) {
        let mut split = line
            .split_ascii_whitespace()
            .map(str::parse::<u32>)
            .flatten();
        let height = split.next().unwrap();
        let from = split.next().unwrap();
        let to = split.next().unwrap();
        bridges.push((from..=(to - 1), height));
    }
    bridges.sort_unstable_by_key(|(_, height)| *height);
    let mut sum = 0u32;
    for i in 0..bridges.len() {
        let mut left = None;
        let mut right = None;
        let (range, height) = &bridges[i];
        let from = range.start();
        let to = range.end();
        for j in (0..i).rev() {
            if left.is_none() && bridges[j].0.contains(from) {
                left = Some(height - bridges[j].1);
            }
            if right.is_none() && bridges[j].0.contains(to) {
                right = Some(height - bridges[j].1);
            }
            if left.is_some() && right.is_some() {
                break;
            }
        }
        sum += left.unwrap_or(*height);
        sum += right.unwrap_or(*height);
    }
    println!("{}", sum);
}
