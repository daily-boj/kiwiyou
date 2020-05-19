const rl = require('readline').createInterface(process.stdin)

rl.once('line', line => {
    const [h, w] = line.split(' ').map(Number)
    const territory = [Array.from({ length: w + 1 }, () => 0)]
    rl.on('line', line => {
        const cluster = line.split(' ').map(Number)
        const prev_row = territory[territory.length - 1]
        const new_row = [0]
        for (let i = 0; i < w; ++i) {
            new_row.push(prev_row[i + 1] + new_row[i] + cluster[i] - prev_row[i])
        }
        territory.push(new_row)
        if (territory.length > h) {
            rl.removeAllListeners('line')
            rl.once('line', line => {
                let queries = Number(line)
                rl.on('line', line => {
                    const [y1, x1, y2, x2] = line.split(' ').map(Number)
                    const people = territory[y2][x2] - territory[y1 - 1][x2] + territory[y1 - 1][x1 - 1] - territory[y2][x1 - 1]
                    console.log(people)
                    if (!--queries) {
                        process.exit(0)
                    }
                })
            })
        }
    })
})