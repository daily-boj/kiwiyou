let count
require('readline').createInterface(process.stdin).on('line', line => {
    if (!count) count = +line
    else {
        let cycle = 0
        line = line.padStart(4, '0')
        while (line !== '6174') {
            const a = [...line].sort()
            const b = [...a].reverse()
            line = (b.join('') - a.join('')).toString().padStart(4, '0')
            ++cycle
        }
        console.log(cycle)
        if (!--count) process.exit(0)
    }
})