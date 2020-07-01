let n, m, a = [], k, b = []
require('readline').createInterface(process.stdin).on('line', line => {
    if (!n) {
        [n, m] = line.split(' ').map(Number)
    } else if (a.length < n) {
        a.push(line.split(' ').map(Number))
    } else if (!k) {
        [, k] = line.split(' ').map(Number)
    } else {
        b.push(line.split(' ').map(Number))
        if (b.length >= m) {
            for (let p = 0; p < n; ++p) {
                const row = []
                for (let q = 0; q < k; ++q) {
                    let sum = 0
                    for (let r = 0; r < m; ++r) {
                        sum += a[p][r] * b[r][q]
                    }
                    row.push(sum)
                }
                console.log(row.join(' '))
            }
        }
    }
})