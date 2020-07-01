const MOD = 1000000
require('readline').createInterface(process.stdin).on('line', line => {
    let n = BigInt(line) - BigInt(1)
    let m = [1, 1, 1, 0]
    let x = [1, 1, 1, 0]
    while (n > BigInt(0)) {
        if (n & BigInt(1)) {
            m = [
                (m[0] * x[0] % MOD + m[1] * x[2] % MOD) % MOD,
                (m[0] * x[1] % MOD + m[1] * x[3] % MOD) % MOD,
                (m[2] * x[0] % MOD + m[3] * x[2] % MOD) % MOD,
                (m[2] * x[1] % MOD + m[3] * x[3] % MOD) % MOD,
            ]
        }
        x = [
            (x[0] * x[0] % MOD + x[1] * x[2] % MOD) % MOD,
            (x[0] * x[1] % MOD + x[1] * x[3] % MOD) % MOD,
            (x[0] * x[2] % MOD + x[2] * x[3] % MOD) % MOD,
            (x[1] * x[2] % MOD + x[3] * x[3] % MOD) % MOD,
        ]
        n >>= BigInt(1)
    }
    console.log(m[1])
})