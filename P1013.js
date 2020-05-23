const rl = require('readline').createInterface(process.stdin)

let cases
rl.on('line', line => {
    if (!cases) {
        cases = +line
    } else if (cases--) {
        console.log(['NO', 'YES'][+/^(100+1+|01)+$/.test(line)])
    }
})