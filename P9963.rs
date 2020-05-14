use std::io::stdin;

struct Queens {
    cols: [bool; 16],
    rdiags: [bool; 32],
    ldiags: [bool; 32],
}

fn try_queen(queens: &mut Queens, size: usize, x: usize, y: usize) -> usize {
    let next_y = y + 1;
    if next_y == size {
        1
    } else {
        queens.cols[x] = true;
        queens.rdiags[size - x + y - 1] = true;
        queens.ldiags[x + y] = true;

        let rdiag_cache = size + next_y - 1;
        let mut count = 0;
        for next_x in 0..size {
            let rdiag = rdiag_cache - next_x;
            let ldiag = next_x + next_y;
            if !(queens.cols[next_x] || queens.rdiags[rdiag] || queens.ldiags[ldiag]) {
                count += try_queen(queens, size, next_x, next_y);
            }
        }

        queens.cols[x] = false;
        queens.rdiags[size - x + y - 1] = false;
        queens.ldiags[x + y] = false;
        count
    }
}

fn main() {
    let stdin = stdin();
    let mut line = String::new();
    stdin.read_line(&mut line).unwrap();
    let size: usize = line.trim_end().parse().unwrap();
    let mut queens = Queens {
        cols: [false; 16],
        rdiags: [false; 32],
        ldiags: [false; 32],
    };
    let mut count = 0;
    for x in 0..size {
        count += try_queen(&mut queens, size, x, 0);
    }
    println!("{}", count);
}