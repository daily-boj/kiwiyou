const fs = require('fs')
const inputs = fs.readFileSync(0).toString().trim().split('\n').map(Number).slice(1)
for (let input of inputs) {
    let [n, t, s, b, m, f] = [1, 1, 0, 1, 1, 1]
    while (--input) {
        [n, t, s, b, m, f] = [f, b + f, m, t + f, s + f, n + t + b + m + f]
    }
    console.log(f)
}