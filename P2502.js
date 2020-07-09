require('readline').createInterface(process.stdin).once('line', line => {
    let [day, dduk] = line.split(' ').map(Number)
    let prev_ac = -1, prev_bc = 1
    let ac = 1, bc = 0
    while (--day) [prev_ac, prev_bc, ac, bc] = [ac, bc, ac + prev_ac, bc + prev_bc]
    for (let B = Math.ceil(dduk / (ac + bc)); B <= dduk / bc; ++B) {
        if ((dduk - bc * B) % ac === 0) {
            console.log((dduk - bc * B) / ac)
            console.log(B)
            break
        }
    }
})