use std::io::stdin;

fn main() {
    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    let mut split = line.split_ascii_whitespace();

    let up_to: u64 = split.next().unwrap().parse().unwrap();
    let mut pos: u64 = split.next().unwrap().parse().unwrap();

    let mut tens = 1u64;
    let mut length = 1u64;
    if pos < 10 {
        pos -= 1;
    }
    loop {
        let count = if length == 1 { 10 } else  { 9 * tens * length };
        if pos < count {
            let number = pos / length + tens;
            if number > up_to {
                println!("-1");
            } else {
                let num_str = number.to_string();
                println!("{}", num_str.chars().nth((pos % length) as usize).unwrap());
            }
            break;
        } else {
            pos -= count;
            tens *= 10;
            length += 1;
        }
    }
}