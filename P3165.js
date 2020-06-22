const with_5 = (num, k) => {
    if (num.length < k) {
        return false
    } else if (num.length === k) {
        const ans = '5'.repeat(k)
        if (+ans > +num) {
            return ans
        } else {
            return false
        }
    } else if (num.length === 1) {
        if (num === '9') return false
        else return ++num
    } else {
        const rest = num.slice(1)
        let attempt = num[0] === '5' ? with_5(rest, k - 1) : with_5(rest, k)
        if (attempt) {
            return num[0] + attempt
        } else if (num[0] === '9') {
            return false
        } else if (num[0] === '4') {
            return '5' + '0'.repeat(num.length - k) + '5'.repeat(k - 1)
        } else {
            return ++num[0] + '0'.repeat(num.length - k - 1) + '5'.repeat(k)
        }
    }
}
require('readline').createInterface(process.stdin).on('line', line => {
    const [a, b] = line.split(/\s/)
    console.log(with_5(a.padStart(16, '0'), +b).replace(/^0+/, ''))
})