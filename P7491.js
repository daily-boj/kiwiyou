let cnt;
require('readline').createInterface(process.stdin).on('line', line => {
    if (!cnt) cnt = +line
    else {
        const [a, b, S] = line.split(' ').map(Number)
        let found
        if (a < b) {
            for (let i = Math.floor(S / b); i >= 0; --i) {
                if ((S - b * i) % a === 0) {
                    found = [(S - b * i) / a, i]
                    break
                }
            }
        } else {
            for (let i = Math.floor(S / a); i >= 0; --i) {
                if ((S - a * i) % b === 0) {
                    found = [i, (S - a * i) / b]
                    break
                }
            }
        }
        if (found) {
            console.log(found[0], found[1])
        } else {
            console.log('Impossible')
        }
        if (!--cnt) process.exit(0)
    }
})