// thanks to jhnah917

const transition = [
    // A, B, N
    [0, 1, 0],
    [2, 1, 0],
    [0, 0, 3],
    [4, 0, 0],
    [0, 0, 5],
    [6, 0, 0],
    [0, 1, 5],
]
const REPR = new Map([
    ['A', 0],
    ['B', 1],
    ['N', 2],
])
require('readline').createInterface(process.stdin).once('line', banana => {
    const cache = Array.from({ length: banana.length + 1 }, _ => Array.from({ length: 7 }, _ => -1))
    cache[banana.length].fill(Infinity)
    cache[banana.length][6] = 0
    for (let i = banana.length; i-- > 0;) {
        for (let s = 0; s <= 6; ++s) {
            let edit = Infinity
            for (let fix = 0; fix < 3; ++fix) {
                if (transition[s][fix] > 0) {
                    edit = Math.min(edit, (REPR.get(banana[i]) !== fix) + cache[i + 1][transition[s][fix]])
                }
            }
            cache[i][s] = edit
        }
    }
    console.log(cache[0][0])
})