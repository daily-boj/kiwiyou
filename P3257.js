const rl = require('readline').createInterface(process.stdin)

const up_to = Array.from({ length: 301 }, () => Array.from({ length: 301 }))
up_to[0][0] = ''

let a, b, mixed
rl.on('line', line => {
    if (!a) {
        a = line
    } else if (!b) {
        b = line
    } else {
        mixed = line
        rl.removeAllListeners('line')
    }
}).on('close', () => {
    for (let m_i = 0; m_i < mixed.length; ++m_i) {
        const to_compare = mixed[m_i];
        for (let a_i = 0; a_i <= m_i && a_i < a.length; ++a_i) {
            if (up_to[m_i][a_i] !== undefined && to_compare === a[a_i]) {
                up_to[m_i + 1][a_i + 1] = up_to[m_i][a_i] + '1'
            }
        }
        for (let b_i = 0; b_i <= m_i && b_i < b.length; ++b_i) {
            if (up_to[m_i][m_i - b_i] !== undefined && to_compare === b[b_i]) {
                up_to[m_i + 1][m_i - b_i] = up_to[m_i][m_i - b_i] + '2'
            }
        }
    }

    for (let i = 0; i <= mixed.length; ++i) {
        if (up_to[mixed.length][i]) {
            console.log(up_to[mixed.length][i])
            break
        }
    }
})
