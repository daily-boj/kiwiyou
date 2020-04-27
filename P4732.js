const readline = require('readline')
const interface = readline.createInterface(process.stdin)

const keys = new Map([
    ['A', 0],
    ['A#', 1],
    ['Bb', 1],
    ['B', 2],
    ['Cb', 2],
    ['B#', 3],
    ['C', 3],
    ['C#', 4],
    ['Db', 4],
    ['D', 5],
    ['D#', 6],
    ['Eb', 6],
    ['E', 7],
    ['Fb', 7],
    ['E#', 8],
    ['F', 8],
    ['F#', 9],
    ['Gb', 9],
    ['G', 10],
    ['G#', 11],
    ['Ab', 11],
])

const keys_rev = 'A A# B C C# D D# E F F# G G#'.split(' ')

let line_num = 0
let sequence
interface.on('line', line => {
    if (line_num % 2 === 0) {
        if (line === '***') {
            process.exit(0)
        }
        sequence = line.split(' ').map(s => keys.get(s))
    } else {
        let key_move = Number(line)
        console.log(sequence.map(key => keys_rev[((key + key_move) % 12 + 12) % 12]).join(' '))
    }
    line_num += 1
})