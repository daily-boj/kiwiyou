const rl = require('readline')
const interface = rl.createInterface(process.stdin)

const valid_digit = new Set([...'123456789'])
const valid_lookahead = new Set(Array.from({ length: 17 }, (v, k) => k + 10 + ''))
interface.once('line', line => {
    if (!valid_digit.has(line[0])) {
        console.log(0)
    } else {
        let prev_prev = 1
        let prev = 1
        for (let i = 1; i < line.length; ++i) {
            const direct = valid_digit.has(line[i])
            const lookahead = valid_lookahead.has(line[i - 1] + line[i])
            if (direct || lookahead) {
                [prev_prev, prev] = [prev, (prev * direct + prev_prev * lookahead) % 1000000]
            } else {
                console.log(0)
                return
            }
        }
        console.log(prev)
    }
})