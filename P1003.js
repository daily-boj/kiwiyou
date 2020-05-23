const rl = require('readline').createInterface(process.stdin)
let ok
rl.on('line', line => {
    if (!ok) {
        ok = true
    } else {
        let [zero, one] = [1, 0]
        let n = +line
        while (n--) {
            [zero, one] = [one, zero + one]
        }
        console.log(zero, one)
    }
})