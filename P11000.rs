extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = u32;

fn main() {
    let mut inputs = input(4_000_007);
    let count = next(&mut inputs);
    let mut events = Vec::with_capacity((count as usize) << 1);
    for _ in 0..count {
        let start = next(&mut inputs);
        events.push((start, 1));
        let end = next(&mut inputs);
        events.push((end, -1));
    }
    events.sort_unstable();
    let mut max_depth = 0;
    let mut depth = 0;
    for (_, delta) in &events {
        depth += delta;
        max_depth = std::cmp::max(max_depth, depth);
    }
    print!("{}", max_depth);
}