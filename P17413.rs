use std::io::{stdin, Read};

fn main() {
    let mut buffer = [0u8; 100000];
    let len = stdin().read(&mut buffer).unwrap();
    let mut string = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
    while let Some(other_index) = string.find(|c: char| !c.is_ascii_alphanumeric()) {
        let reversed: String = string[..other_index].chars().rev().collect();
        print!("{}", reversed);
        match string.as_bytes()[other_index] {
            b'<' => {
                let close = string.find('>').unwrap();
                print!("{}", &string[other_index..=close]);
                string = &string[close + 1..];
            }
            b' ' => {
                print!(" ");
                string = &string[other_index + 1..];
            }
            _ => string = &string[other_index + 1..],
        }
    }
    let reversed: String = string.chars().rev().collect();
    println!("{}", reversed);
}
