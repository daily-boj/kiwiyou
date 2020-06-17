use std::io::{stdin, Read};

fn main() {
    let stdin = stdin();
    let mut stdin = stdin.lock();
    let mut buffer = [0; 102];
    let has_read = stdin.read(&mut buffer).unwrap();
    let mut camel = Vec::with_capacity(100);
    let mut snake = Vec::with_capacity(150);
    let mut pascal = Vec::with_capacity(100);
    let op = buffer[0];
    let buffer = &buffer[2..has_read];
    match op {
        b'1' => {
            camel.extend_from_slice(buffer);
            pascal.extend_from_slice(buffer);
            pascal[0] ^= 0b0100000;
            let mut stage = buffer;
            while let Some(pos) = stage.iter().position(|c| c.is_ascii_uppercase()) {
                snake.extend_from_slice(&stage[..pos]);
                snake.push(b'_');
                snake.push(stage[pos] | 0b0100000);
                stage = &stage[pos + 1..];
            }
            snake.extend_from_slice(stage);
        }
        b'2' => {
            snake.extend_from_slice(buffer);
            for chunk in buffer.split(|c| *c == b'_') {
                let head_idx = camel.len();
                camel.extend_from_slice(chunk);
                pascal.extend_from_slice(chunk);
                camel[head_idx] ^= 0b0100000;
                pascal[head_idx] ^= 0b0100000;
            }
            camel[0] ^= 0b0100000;
        }
        b'3' => {
            camel.extend_from_slice(buffer);
            pascal.extend_from_slice(buffer);
            camel[0] ^= 0b0100000;
            snake.push(buffer[0] | 0b0100000);
            let mut stage = &buffer[1..];
            while let Some(pos) = stage.iter().position(|c| c.is_ascii_uppercase()) {
                snake.extend_from_slice(&stage[..pos]);
                snake.push(b'_');
                snake.push(stage[pos] | 0b0100000);
                stage = &stage[pos + 1..];
            }
            snake.extend_from_slice(stage);
        }
        _ => unreachable!()
    }
    let camel = std::str::from_utf8(&camel).unwrap().trim_end();
    let snake = std::str::from_utf8(&snake).unwrap().trim_end();
    let pascal = std::str::from_utf8(&pascal).unwrap().trim_end();
    println!("{}\n{}\n{}", camel, snake, pascal);
}