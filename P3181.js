const rl = require('readline').createInterface(process.stdin)

const special = new Set('i pa te ni niti a ali nego no ili'.split(' '))

rl.on('line', line => {
    let acronym = line[0].toUpperCase()
    for (const words of line.split(' ').slice(1)) {
        if (!special.has(words)) {
            acronym += words[0].toUpperCase()
        }
    }
    console.log(acronym)
})