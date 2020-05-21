const rl = require('readline').createInterface(process.stdin)

rl.on('line', line => {
    let num = +line
    if (num === 1) {
        console.log(1)
    } else {
        let exp = Math.ceil(Math.log10(9 * num + 1))
        let modulo = 1
        num *= 9
        for (let i = 0; i < exp; ++i) {
            modulo *= 10
            modulo %= num
        }
        while (modulo !== 1) {
            modulo *= 10
            modulo %= num
            ++exp
        }
        console.log(exp)
    }
})