let a, b, i = 1
require('readline').createInterface(process.stdin).on('line', line => {
    if (!a) a = line
    else {
        b = line
        if (a === 'END' && b === 'END') process.exit(0)
        const result = [...a].sort().join('') === [...b].sort().join('') ? 'same' : 'different'
        console.log(`Case ${i++}: ${result}`)
        a = undefined
    }
})