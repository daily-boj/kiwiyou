const rl = require('readline')
const interface = rl.createInterface(process.stdin)
interface.once('line', line => {
    console.log(/^(?:pi|ka|chu)+$/.test(line) ? 'YES' : 'NO')
})