const parens = require('fs').readFileSync('/dev/stdin').toString().trimRight()

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
    const [c, bound, after_bound] = total === 2 ? ['(', 1, 1] : [')', 0, -1]
    for (let i = 0; i < parens.length; ++i) {
        if (parens[i] === c && height >= bound && height + lowest_behind[i + 1] >= after_bound) {
            ++count
        }
        height += parens[i] === '(' ? 1 : -1
        lowest = Math.min(lowest, height)
        if (lowest < 0) break
    }
}
console.log(count)
