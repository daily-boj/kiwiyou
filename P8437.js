const [sum, diff] = require('fs').readFileSync('/dev/stdin').toString().split('\n').map(BigInt)
const natalia = (sum - diff) >> 1n
console.log((natalia + diff).toString() + '\n' + natalia.toString())