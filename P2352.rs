use std::io::{stdin, Read};

fn main() {
    let stdin = stdin();
    let mut handle = stdin.lock();
    let mut input = String::new();
    handle.read_to_string(&mut input).unwrap();
    let mut longest_subseq = vec![];
    for port_str in input.split_ascii_whitespace().skip(1) {
        let port: u32 = port_str.parse().unwrap();
        if longest_subseq
            .last()
            .map(|last| port > *last)
            .unwrap_or(true)
        {
            longest_subseq.push(port);
        } else {
            let mut lower_bound = 0;
            let mut count = longest_subseq.len();
            while count > 0 {
                let mid = lower_bound + (count >> 1);
                if port > longest_subseq[mid] {
                    lower_bound = mid + 1;
                    count -= count >> 1;
                    count -= 1;
                } else {
                    count >>= 1;
                }
            }
            longest_subseq[lower_bound] = port;
        }
    }
    println!("{}", longest_subseq.len());
}
