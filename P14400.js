let n, xpos = [], ypos = []
require('readline').createInterface(process.stdin).on('line', line => {
    if (!n) n = +line
    else {
        const [x, y] = line.split(' ').map(Number)
        xpos.push(x)
        ypos.push(y)
        if (xpos.length === n) {
            xpos.sort()
            ypos.sort()
            const xmed = xpos[n >> 1]
            const ymed = ypos[n >> 1]
            console.log(xpos.reduce((p, c) => p + Math.abs(c - xmed), 0) + ypos.reduce((p, c) => p + Math.abs(c - ymed), 0))
            process.exit(0)
        }
    }
})