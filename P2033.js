require('readline').createInterface(process.stdin).once('line', line => {
    let num = +line
    let count = 0
    while (num > 10) {
        ++count
        num = Math.round(num / 10)
    }
    console.log(num + '0'.repeat(count))
})