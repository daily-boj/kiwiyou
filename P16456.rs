use std::io::{BufReader, Read};
use std::fs::File;

#[inline]
fn stdin() -> BufReader<File> {
    BufReader::with_capacity(65536, unsafe { std::os::unix::io::FromRawFd::from_raw_fd(0) })
}

fn main() {
    let mut line = String::new();
    stdin().read_to_string(&mut line).unwrap();
    let islands: usize = line.trim_end().parse().unwrap();
    if islands == 1 {
        println!("1");
    } else {
        let mut step_on = [0u32; 50000];
        let mut step_back_on = [0u32; 50000];
        step_on[0] = 1;
        step_on[1] = 1;
        step_back_on[1] = 1;
        for i in 2..islands {
            step_on[i] = (step_on[i - 1] + step_back_on[i - 2]) % 1_000_000_009;
            step_back_on[i] = step_on[i - 1];
        }
        println!("{}", (step_on[islands - 1] + step_back_on[islands - 2]) % 1_000_000_009);
    }
}