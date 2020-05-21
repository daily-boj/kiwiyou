const rl = require('readline').createInterface(process.stdin)

function fix_available(parens) {
    const lowest_behind = [0]
    let total = 0
    for (let i = parens.length - 1; i >= 0; --i) {
        const par = parens[i] === '(' ? 1 : -1
        lowest_behind.push(par + Math.min(lowest_behind[lowest_behind.length - 1], 0))
        total += par
    }
    lowest_behind.reverse()
    let count = 0
    if (Math.abs(total) === 2 && lowest_behind[0] >= -2) {
        let height = 0
        let lowest = 0
        if (total === 2) {
            for (let i = 0; i < parens.length; ++i) {
                if (parens[i] === '(' && height >= 1 && height + lowest_behind[i + 1] >= 1) {
                    ++count
                }
                height += parens[i] === '(' ? 1 : -1
                lowest = Math.min(lowest, height)
                if (lowest < 0) break
            }
        } else {
            for (let i = 0; i < parens.length; ++i) {
                if (parens[i] === ')' && height >= 0 && height + lowest_behind[i + 1] >= -1) {
                    ++count
                }
                height += parens[i] === '(' ? 1 : -1
                lowest = Math.min(lowest, height)
                if (lowest < 0) break
            }
        }
    }
    console.log(count)
}

rl.once('line', line => {
    fix_available(line)
})