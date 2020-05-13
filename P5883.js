const rl = require('readline')
const interface = rl.createInterface(process.stdin)
const queue = []
const types = new Set()
interface.once('line', line => {
    queue.length = Number(line)
    interface.on('line', line => {
        queue.push(Number(line))
        types.add(Number(line))
    })
}).on('close', () => {
    let max_len = 0
    for (const type of types) {
        const new_queue = queue.filter(v => v !== type)
        let current = new_queue.shift()
        let consequent = 1
        for (const next of new_queue) {
            if (next !== current) {
                max_len = Math.max(max_len, consequent)
                consequent = 1
                current = next
            } else {
                consequent += 1
            }
        }
        max_len = Math.max(max_len, consequent)
    }
    console.log(max_len)
})