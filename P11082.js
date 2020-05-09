const readline = require('readline')
const interface = readline.createInterface(process.stdin)
interface.once('line', line => {
    let { groups: { integer, noncyclic, cyclic } } = line.match(/(?<integer>\d+)(?:\.(?<noncyclic>\d*)(?:\((?<cyclic>\d+)\))?)?/)
    if (cyclic && [...cyclic].every(c => c === '0')) cyclic = undefined
    if (noncyclic && !cyclic && [...noncyclic].every(c => c === '0')) noncyclic = undefined
    if (!cyclic) {
        if (!noncyclic) {
            console.log(`${integer}/1`)
        } else {
            let numerator = Number(noncyclic)
            let divisor = 1;
            while (numerator % 2 === 0) {
                numerator /= 2;
                divisor *= 2;
            }
            while (numerator % 5 === 0) {
                numerator /= 5;
                divisor *= 5;
            }
            const denominator = Number('1' + '0'.repeat(noncyclic.length)) / divisor
            console.log(`${integer * denominator + numerator}/${denominator}`)
        }
    } else {
        noncyclic = noncyclic || ''
        let numerator = Number(noncyclic + cyclic) - Number(noncyclic)
        let denominator = Number('9'.repeat(cyclic.length) + '0'.repeat(noncyclic.length))
        let a = numerator, b = denominator
        while (a) {
            const temp = a
            a = b % a
            b = temp
        }
        denominator /= b
        numerator /= b
        console.log(`${integer * denominator + numerator}/${denominator}`)
    }
})