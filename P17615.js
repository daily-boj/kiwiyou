const rl = require('readline').createInterface(process.stdin)

let count
rl.on('line', line => {
    if (!count) {
        count = +line
    } else {
        const left_red_count = line.indexOf('B')
        const right_red_count = count - line.lastIndexOf('B') - 1
        const left_blue_count = line.indexOf('R')
        const right_blue_count = count - line.lastIndexOf('R') - 1
        let reds = 0
        let blues = 0
        for (const c of line) {
            c === 'R' ? ++reds : ++blues
        }
        console.log(Math.min(
            reds - left_red_count,
            reds - right_red_count,
            blues - left_blue_count,
            blues - right_blue_count,
        ))
    }
})