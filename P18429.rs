use std::io::{stdin, Read};

fn main() {
    let mut stdin = stdin();
    let mut input = String::new();
    stdin.read_to_string(&mut input).unwrap();
    let mut args = input.split_ascii_whitespace();
    let days: i32 = args.next().unwrap().parse().unwrap();
    let loss: i32 = args.next().unwrap().parse().unwrap();
    let kits: Vec<i32> = args.map(|arg| arg.parse::<i32>().unwrap() - loss).collect();
    let mut state: Vec<(u64, i32)> = kits
        .iter()
        .enumerate()
        .filter(|(_, gain)| **gain >= 0)
        .map(|(i, gain)| (1u64 << i, *gain))
        .collect();
    for _ in 1..days {
        let mut next_state = Vec::new();
        for (used, gain) in state.into_iter() {
            for (index, kit) in kits.iter().enumerate() {
                if (1u64 << index) & used == 0 && (gain + kit) >= 0 {
                    //println!("Used {:b}, Current {}, kit #{:b}, Gained {}", used, gain, 1u64 << index, kit);
                    next_state.push((used | (1u64 << index), gain + kit));
                }
            }
        }
        state = next_state;
    }
    println!("{}", state.len());
}
