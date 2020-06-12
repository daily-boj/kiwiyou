fn main() {
    let mut input = String::new();
    let stdin = std::io::stdin();
    stdin.read_line(&mut input);
    let n: u128 = input.trim_end().parse().unwrap();
    let mut count: u128 = 0;
    let mut divisor = 5;
    while n >= divisor {
        let q = n / divisor;
        let r = n % divisor;
        count += (q * (q - 1) >> 1) * divisor;
        count += q * (r + 1);
        divisor *= 5;
    }
    println!("{}", count);
}