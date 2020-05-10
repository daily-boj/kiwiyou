const rl = require('readline')
const interface = rl.createInterface(process.stdin)
const strings = []
interface.on('line', line => strings.push(line)).on('close', () => {
    const [sa, sb] = strings
    const lcs_len = Array.from({ length: sa.length }, () => Array.from({ length: sb.length }))
    lcs_len[0][0] = +(sa[0] === sb[0])
    for (let j = 1; j < sb.length; ++j) {
        lcs_len[0][j] = Math.max(lcs_len[0][j - 1], +(sa[0] === sb[j]))
    }
    for (let i = 1; i < sa.length; ++i) {
        const lcs_i = lcs_len[i]
        const lcs_prev = lcs_len[i - 1]
        lcs_i[0] = Math.max(+(sa[i] === sb[0]), lcs_prev[0])
        for (let j = 1; j < sb.length; ++j) {
            lcs_i[j] = Math.max(lcs_prev[j - 1] + (sa[i] === sb[j]), lcs_prev[j], lcs_i[j - 1])
        }
    }
    console.log(lcs_len[sa.length - 1][sb.length - 1])
})