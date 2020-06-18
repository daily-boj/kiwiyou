const rl = require('readline').createInterface(process.stdin)
let count, queue
rl.on('line', line => {
    if (!count) count = +line
    else if (!queue) {
        queue = line.split(/\s/g).map(Number)
        const stack = []
        let i = 1
        for (const num of queue) {
            if (num == i) {
                ++i
                while (stack.length > 0 && stack[stack.length - 1] == i) {
                    stack.pop()
                    ++i
                }
            }
            else if (num > i) {
                if (stack[stack.length - 1] < num) {
                    console.log('Sad')
                    return
                } else {
                    stack.push(num)
                }
            }
        }
        console.log('Nice')
    }
})