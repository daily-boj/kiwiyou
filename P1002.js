const rl = require('readline').createInterface(process.stdin)

let cases
rl.on('line', line => {
    if (!cases) {
        cases = +line
    } else {
        const [x1, y1, r1, x2, y2, r2] = line.split(' ').map(Number)
        const distance = Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2)
        const internal_threshold = Math.pow(r1 - r2, 2)
        const external_threshold = Math.pow(r1 + r2, 2)
        if (distance == 0 && internal_threshold == 0) {
            console.log(-1)
        } else if (distance > external_threshold) {
            console.log(0)
        } else if (distance === external_threshold) {
            console.log(1)
        } else if (distance > internal_threshold) {
            console.log(2)
        } else if (distance === internal_threshold) {
            console.log(1)
        } else {
            console.log(0)
        }
    }
})