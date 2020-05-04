use std::io::{stdin, BufRead};
use std::cmp::max;

fn main() {
    let stdin = stdin();
    let mut lock = stdin.lock();
    let mut line = String::new();
    lock.read_line(&mut line).unwrap();
    line.clear();
    lock.read_line(&mut line).unwrap();
    let numbers: Vec<i32> = line.split_ascii_whitespace().map(str::parse).flatten().collect();
    if numbers.len() == 1 {
        println!("{}", numbers[0]);
    } else {
        let mut continued = [0i32; 100000];
        let mut removed = [0i32; 100000];
        continued[0] = numbers[0];
        removed[0] = numbers[0];
        continued[1] = max(continued[0] + numbers[1], numbers[1]);
        removed[1] = numbers[1];
        for i in 2..numbers.len() {
            continued[i] = max(continued[i - 1] + numbers[i], numbers[i]);
            removed[i] = max(max(removed[i - 1] + numbers[i], continued[i - 2] + numbers[i]), numbers[i]);
        }
        let cont_max = continued[1..numbers.len()].iter().copied().fold(continued[0], max);
        let remv_max = removed[1..numbers.len()].iter().copied().fold(removed[0], max);
        println!("{}", max(cont_max, remv_max));
    }
}