const rl = require('readline').createInterface(process.stdin)
rl.on('line', line => {
    const digits = new Set()
    line = +line
    let x = line
    let i = 0
    while (digits.size < 10) {
        for (const d of x.toString()) digits.add(d)
        ++i
        x += line
    }
    console.log(i)
})