use std::io::{stdin, BufRead};

fn main() {
    let stdin = stdin();
    let handle = stdin.lock();
    let mut lines = handle.lines().flatten();
    lines.next();
    let line = lines.next().unwrap();

    let knowing = line
        .trim()
        .split(' ')
        .skip(1)
        .filter_map(|i| i.parse::<u64>().ok())
        .fold(0u64, |prev, i| prev | (1 << i));

    let parties: Vec<u64> = lines
        .map(|line| {
            line.trim()
                .split(' ')
                .skip(1)
                .filter_map(|i| i.parse::<u64>().ok())
                .fold(0u64, |prev, i| prev | (1 << i))
        })
        .collect();

    let mut know_state = Vec::<(u64, u64, usize)>::new();
    know_state.push((knowing, 0, 0));
    for party in parties {
        let temp: Vec<_> = know_state.drain(..).collect();
        for (aware, unaware, max_lie) in temp {
            if party & aware == 0 {
                know_state.push((aware, unaware | party, max_lie + 1));
            }
            if party & unaware == 0 {
                know_state.push((aware | party, unaware, max_lie));
            }
        }
    }

    let max_lie = know_state
        .into_iter()
        .fold(0, |max, (_, _, lie)| if max < lie { lie } else { max });
    println!("{}", max_lie);
}
