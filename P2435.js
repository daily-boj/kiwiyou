const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString()

const [[n, k], temps] = input.split('\n').map(l => l.split(' ').map(Number))

for (let i = 1; i < n; ++i)
    temps[i] += temps[i - 1]

let max = temps[k - 1]
for (let i = k; i < n; ++i)
    max = Math.max(max, temps[i] - temps[i - k])

console.log(max)