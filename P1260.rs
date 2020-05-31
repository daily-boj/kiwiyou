extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = usize;

fn dfs(visited: &mut [bool], adj: &Vec<Vec<bool>>, to_visit: usize, output: &mut String) {
    visited[to_visit] = true;
    let s = (to_visit + 1).to_string();
    output.push_str(&s);
    output.push(' ');
    for (i, connected) in adj[to_visit].iter().enumerate() {
        if *connected && !visited[i] {
            visited[i] = true;
            dfs(visited, adj, i, output);
        }
    }
}

fn bfs(visited: &mut [bool], adj: &Vec<Vec<bool>>, to_visit: usize, output: &mut String) {
    use std::collections::VecDeque;
    let mut visit_queue = VecDeque::with_capacity(visited.len());
    visit_queue.push_back(to_visit);
    visited[to_visit] = true;
    while let Some(next) = visit_queue.pop_front() {
        let s = (next + 1).to_string();
        output.push_str(&s);
        output.push(' ');
        for (i, connected) in adj[next].iter().enumerate() {
            if *connected && !visited[i] {
                visited[i] = true;
                visit_queue.push_back(i);
            }
        }
    }
}

use std::fs::File;
use std::os::unix::io::FromRawFd;
use std::io::Write;

fn main() {
    let mut inputs = input(100_016);
    let v_count = next(&mut inputs);
    let mut adj = vec![vec![false; v_count]; v_count];
    let e_count = next(&mut inputs);
    let start = next(&mut inputs) - 1;
    for _ in 0..e_count {
        let a = next(&mut inputs) - 1;
        let b = next(&mut inputs) - 1;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    let mut visited = Vec::with_capacity(v_count);
    visited.resize(v_count, false);
    let mut output = String::with_capacity(10_000);
    dfs(&mut visited, &adj, start, &mut output);
    output.push('\n');
    for v in visited.iter_mut() {
        *v = false;
    }
    bfs(&mut visited, &adj, start, &mut output);
    let mut stdout = unsafe { File::from_raw_fd(1) };
    let _ = stdout.write(output.as_bytes());
}