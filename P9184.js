const cache = Array.from({ length: 20 }, () => Array.from({ length: 20 }, () => Array.from({ length: 20 })))
const w = (a, b, c) => {
    if (a < 0 || b < 0 || c < 0) {
        return 1
    } else if (a >= 20 || b >= 20 || c >= 20) {
        return w(19, 19, 19)
    } else if (cache[a][b][c] !== undefined) {
        return cache[a][b][c]
    } else if (a < b && b < c) {
        return cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
    } else {
        return cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
    }
}
require('readline').createInterface(process.stdin).on('line', line => {
    const [a, b, c] = line.split(' ').map(Number)
    if (a === -1 && b === -1 && c === -1) process.exit(0)
    console.log(`w(${a}, ${b}, ${c}) = ${w(a - 1, b - 1, c - 1)}`)
})