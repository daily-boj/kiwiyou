const rl = require('readline').createInterface(process.stdin)

let height, amp;
let multiplier = 1
let sum = 0
const mod = 1_000_000_007
rl.on('line', line => {
    if (!amp) {
        [height, amp] = line.split(' ').map(Number)
    } else if (height) {
        multiplier = (multiplier * amp) % mod
        sum = (sum + (multiplier * line) % mod) % mod
        if (!--height) {
            console.log(sum)
        }
    }
})