use std::io::{stdin, BufRead};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let stdin = stdin();
    let handle = stdin.lock();
    let mut input = handle.lines().flatten().skip(1);
    let expr = input.next().unwrap();
    let numbers: Vec<u32> = input.flat_map(|line| line.parse()).collect();
    let mut stack = Vec::<f64>::new();
    for letter in expr.chars() {
        match letter {
            '+' => {
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                stack.push(b + a);
            }
            '-' => {
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                stack.push(b - a);
            }
            '*' => {
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                stack.push(b * a);
            }
            '/' => {
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                stack.push(b / a);
            }
            _ => {
                let index = letter as u8 - b'A';
                stack.push(numbers[index as usize] as f64);
            }
        }
    }
    println!("{:.2}", stack[0]);
    Ok(())
}