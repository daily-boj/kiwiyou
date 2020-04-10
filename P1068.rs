use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let nodes: usize = input.trim_end().parse().unwrap();
    let mut root = 50;
    let mut tree = [[false; 50]; 50];
    input.clear();
    stdin().read_line(&mut input).unwrap();
    for (child, parent) in input
        .trim_end()
        .split_ascii_whitespace()
        .map(|s| s.parse::<i32>())
        .flatten()
        .enumerate()
    {
        if parent >= 0 {
            tree[parent as usize][child] = true;
        } else {
            root = child;
        }
    }
    input.clear();
    stdin().read_line(&mut input).unwrap();
    let remove: usize = input.trim_end().parse().unwrap();
    if remove == root {
        println!("0");
    } else {
        let mut visit = Vec::<usize>::new();
        let mut leaves = 0;
        visit.push(root);
        while !visit.is_empty() {
            let parent = visit.pop().unwrap();
            let mut found = false;
            for child in 0..nodes {
                if tree[parent][child] && child != remove {
                    found = true;
                    visit.push(child);
                }
            }
            if !found {
                leaves += 1;
            }
        }
        println!("{}", leaves);
    }
}
