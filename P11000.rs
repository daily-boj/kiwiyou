extern "C" { fn mmap(a: *mut u8, l: usize, p: i32, f: i32, d: i32, o: i64) -> *mut u8; }
fn input(size: usize) -> *const u8 { unsafe { mmap(0 as *mut u8, size, 1, 2, 0, 0) } }
fn next(p: &mut *const u8) -> I { unsafe { let mut n = 0; while **p & 16 != 0 { n = n * 10 + (**p as I & 15); *p = p.offset(1) } *p = p.offset(1); n } }
type I = u32;

use std::collections::BTreeMap;

fn main() {
    let mut inputs = input(4_000_007);
    let count = next(&mut inputs);
    let mut classes = Vec::with_capacity(count as usize);
    for _ in 0..count {
        let begin = next(&mut inputs);
        let end = next(&mut inputs);
        classes.push((begin, end));
    }
    classes.sort_unstable_by_key(|(begin, _)| *begin);
    let mut rooms = 0;
    let mut scheduled_room = BTreeMap::new();
    for (begin, end) in classes.iter() {
        let mut bounds = scheduled_room.range(0..=*begin);
        let range = bounds.next().map(|(last_end, count)| (*last_end, *count));
        if let Some((last_end, count)) = range {
            if count > 1 {
                scheduled_room.insert(last_end, count - 1);
            } else {
                scheduled_room.remove(last_end);
            }
        } else {
            rooms += 1;
        }
        if let Some(count) = scheduled_room.get_mut(end) {
            *count += 1;
        } else {
            scheduled_room.insert(end, 1);
        }
    }
    print!("{}", rooms);
}