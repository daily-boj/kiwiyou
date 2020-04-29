const readline = require('readline')
const interface = readline.createInterface(process.stdin)
let line_index = 0
let actions, count
let left, right
let reversed
interface.once('line', () => interface.on('line', line => {
    switch (line_index % 3) {
        case 0:
            actions = line
            break
        case 1:
            count = Number(line)
            left = 0
            right = count
            reversed = false
            for (const action of actions) {
                if (action === 'R') {
                    reversed = !reversed
                } else if (reversed) {
                    right -= 1
                } else {
                    left += 1
                }
            }
            break
        case 2:
            if (left > right) {
                console.log('error')
            } else {
                const numbers = line.slice(1, line.length - 1).split(',').slice(left, right)
                if (reversed) {
                    numbers.reverse()
                }
                console.log('[' + numbers.join(',') + ']')
            }
            break
    }
    line_index += 1
}))