const readline = require('readline')
const interface = readline.createInterface(process.stdin)

let players;
let times;
let sign_type;
let line_num = 0;
interface.on('line', line => {
    switch (line_num++) {
    case 0:
        players = Number(line)
        break
    case 1:
        times = Number(line)
        break
    case 2:
        sign_type = Number(line)
        break
    }
}).on('close', () => {
    let pu = 0
    let pa = 0
    let round = 1
    let count = 0
    if (sign_type === 0) {
        while(pu < times) {
            const all_pu = 3 + round
            if (times <= pu + all_pu) {
                pu += 1
                count += 1
                if (pu === times) {
                    break
                }
                pu += 1
                count += 2
                if (pu === times) {
                    break
                }
                count += 1
                for (let next_pu = 0; next_pu <= round; ++next_pu) {
                    pu += 1
                    count += 1
                    if (pu === times) {
                        break
                    }
                }
                break
            } else {
                pu += all_pu
                count += 2 * all_pu
            }
            round += 1
        }
    } else {
        while(pa < times) {
            const all_pa = 3 + round
            if (times <= pa + all_pa) {
                pa += 1
                count += 2
                if (pa === times) {
                    break
                }
                pa += 1
                count += 2
                if (pa === times) {
                    break
                }
                count += round + 1
                for (let next_pa = 0; next_pa <= round; ++next_pa) {
                    pa += 1
                    count += 1
                    if (pa === times) {
                        break
                    }
                }
                break
            } else {
                pa += all_pa
                count += 2 * all_pa
            }
            round += 1
        }
    }
    console.log((count - 1) % players)
})