const rl = require('readline').createInterface(process.stdin)

let count, chunks
let max_sum
let numbers
rl.on('line', line => {
    if (!max_sum) {
        [count, chunks] = line.split(' ').map(Number)
        max_sum = Array.from(
            { length: chunks },
            () => Array.from({ length: count }, () => ({ inclusive: -Infinity, exclusive: -Infinity }))
        )
        numbers = []
    } else if (numbers.length < count) {
        numbers.push(Number(line))
    }
}).on('close', () => {
    if (count === 1) {
        console.log(numbers[0])
    } else {
        max_sum[0][0].inclusive = numbers[0]
        for (let i = 1; i < count; ++i) {
            max_sum[0][i].inclusive = numbers[i] + Math.max(0, max_sum[0][i - 1].inclusive)
            max_sum[0][i].exclusive = Math.max(
                max_sum[0][i - 1].inclusive,
                max_sum[0][i - 1].exclusive
            )
            for (let chunk = 1; chunk < chunks; ++chunk) {
                max_sum[chunk][i].inclusive = Math.max(
                    max_sum[chunk][i - 1].inclusive,
                    max_sum[chunk - 1][i - 1].exclusive
                ) + numbers[i]
                max_sum[chunk][i].exclusive = Math.max(
                    max_sum[chunk][i - 1].inclusive,
                    max_sum[chunk][i - 1].exclusive
                )
            }
        }
        const {
            inclusive,
            exclusive
        } = max_sum[chunks - 1][count - 1]
        console.log(Math.max(inclusive, exclusive))
    }
})
