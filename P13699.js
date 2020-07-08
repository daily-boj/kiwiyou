const ts = [1,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,]
const t = n => ts[n] || (ts[n] = Array.from({length: n}).reduce((v, _, i) => v + t(i) * t(n - i - 1), 0))
require('readline').createInterface(process.stdin).once('line', line => console.log(t(+line)))