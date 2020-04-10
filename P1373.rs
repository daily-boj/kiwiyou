use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.pop();
    let chunks = input.into_bytes();
    for chunk in chunks.rchunks(3).rev() {
        let s = unsafe { std::str::from_utf8_unchecked(chunk) };
        let value: u64 = u64::from_str_radix(s, 2).unwrap();
        print!("{:o}", value);
    }
}
