fn largest_rectangle(histogram: &[u32]) -> u64 {
    use std::cmp::max;
    let mut largest = histogram[0] as u64;
    let mut calc_context = Vec::with_capacity(histogram.len());
    calc_context.push((0, histogram[0]));
    for i in 1..histogram.len() {
        let mut new_start = i;
        while let Some((start, height)) = calc_context.last().copied() {
            if height >= histogram[i] {
                calc_context.pop();
                largest = max(largest, (i - start) as u64 * (height as u64));
                new_start = start;
            } else {
                break;
            }
        }
        calc_context.push((new_start, histogram[i]));
    }
    while let Some((start, height)) = calc_context.pop() {
        largest = max(largest, (histogram.len() - start) as u64 * (height as u64));
    }
    largest
}

fn main() {
    use std::fs::File;
    use std::io::{BufRead, BufReader, BufWriter, Write};
    use std::os::unix::io::FromRawFd;
    let mut stdin = BufReader::with_capacity(1_100_007, unsafe { File::from_raw_fd(0) });
    let mut buffer = Vec::with_capacity(1_100_007);
    let mut histogram = Vec::with_capacity(100_000);
    let mut stdout = BufWriter::with_capacity(65536, unsafe { File::from_raw_fd(1) });
    while let Ok(len) = stdin.read_until(b'\n', &mut buffer) {
        let line = unsafe { std::str::from_utf8_unchecked(&buffer[..len]) };
        let numbers = line
            .split_ascii_whitespace()
            .skip(1)
            .map(str::parse)
            .map(Result::unwrap);
        for number in numbers {
            histogram.push(number);
        }
        if histogram.is_empty() {
            break;
        }
        let height = largest_rectangle(histogram.as_ref());
        stdout.write_fmt(format_args!("{}\n", height)).unwrap();
        unsafe { histogram.set_len(0) };
        unsafe { buffer.set_len(0) };
    }
}
