const rl = require('readline').createInterface(process.stdin)

let count
const price = []
rl.on('line', line => {
    if (!count) {
        count = +line
    } else {
        price.push(+line)
        if (!--count) {
            price.sort((a, b) => b - a)
            let sum = 0
            for (let i = 0; i < price.length - 2; i += 3) {
                sum += price[i]
                sum += price[i + 1]
            }
            for (let i = price.length % 3; i > 0; --i) {
                sum += price[price.length - i]
            }
            console.log(sum)
            process.exit(0)
        }
    }
})