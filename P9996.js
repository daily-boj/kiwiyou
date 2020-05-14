const rl = require('readline')
const interface = rl.createInterface(process.stdin)

interface.once('line', () => {
    interface.once('line', line => {
        const regex = new RegExp('^' + line.replace('*', '.*') + '$')
        interface.on('line', line => {
            console.log(regex.test(line) ? 'DA' : 'NE')
        })
    })
})