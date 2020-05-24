const rl = require('readline').createInterface(process.stdin)

const cache = Array.from({ length: 51 }, () => Array.from({ length: 1001 }))
function min_try(balls, floors) {
    if (balls === 1) {
        return floors
    } else if (!cache[balls][floors]) {
        if (floors <= 2) {
            return floors
        } else {
            let min = Infinity
            for (let split = 2; split < floors; ++split) {
                min = Math.min(min, Math.max(min_try(balls - 1, split - 1), min_try(balls, floors - split)))
            }
            cache[balls][floors] = min + 1
        }
    }
    return cache[balls][floors]
}

let sets
rl.on('line', line => {
    if (!sets) {
        sets = +line
    } else {
        const [balls, floors] = line.split(' ').map(Number)
        console.log(min_try(balls, floors))
    }
})