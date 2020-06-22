let n
require('readline').createInterface(process.stdin).on('line', line => {
    if (!n) n = +line
    else {
        console.log('god' + line.split(' ').slice(1).join(''))
        if (!--n) process.exit(0)
    }
})