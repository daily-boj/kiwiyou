use std::io::stdin;

fn main() {
    let stdin = stdin();
    let mut line = String::new();
    stdin.read_line(&mut line).unwrap();
    line.clear();
    stdin.read_line(&mut line).unwrap();
    let mut time: Vec<u32> = line
        .split_ascii_whitespace()
        .map(|s| s.parse())
        .flatten()
        .collect();
    time.sort();
    for i in 1..time.len() {
        time[i] += time[i - 1];
    }
    println!("{}", time.into_iter().sum::<u32>());
}
