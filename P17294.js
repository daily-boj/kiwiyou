require('readline').createInterface(process.stdin).once('line', line => {
    if (line.length > 2) {
        const seq = [...line].map(Number)
        const diff = seq[1] - seq[0]
        for (let i = 2; i < seq.length; ++i) {
            if (seq[i] - seq[i - 1] != diff) {
                console.log('흥칫뿡!! <(￣ ﹌ ￣)>')
                return
            }
        }
    }
    console.log('◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!')
})