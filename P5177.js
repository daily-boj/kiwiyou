const rl = require('readline').createInterface(process.stdin)
let k, a, b
rl.on('line', line => {
    if (!k) k = 1
    else if (!a) {
        a = line.trim()
        a = a.replace(/ +/g, ' ')
        a = a.replace(/ ?([\[\(\{\.,;\:]) ?/g, '$1')
        a = a.replace(/[\[\(\{]/g, '(')
        a = a.replace(/[\]\)\}]/g, ')')
        a = a.replace(/[,;]/g, ',')
    }
    else if (!b) {
        b = line.trim()
        b = b.replace(/ +/g, ' ')
        b = b.replace(/ ?([\[\(\{\.,;\:]) ?/g, '$1')
        b = b.replace(/[\[\(\{]/g, '(')
        b = b.replace(/[\]\)\}]/g, ')')
        b = b.replace(/[,;]/g, ',')
        console.log(`Data Set ${k++}: ${a.toUpperCase() === b.toUpperCase() ? 'equal' : 'not equal'}\n`)
        a = b = undefined
    }
})