const readline = require('readline')
const interface = readline.createInterface(process.stdin)

const connections = Array.from({ length: 50 }).map(() => ({ friends: new Set(), two_friends: 0 }))

let line_count = 0
let friends_count;
interface.on('line', line => {
    if (line_count > 0) {
        let with_whom = 0
        for (const is_friend of line) {
            if (is_friend == 'Y') {
                connections[line_count - 1].friends.add(with_whom)
            }
            with_whom += 1
        }
    } else {
        friends_count = Number(line)
    }
    line_count += 1
}).on('close', () => {
    for (let one = 1; one < friends_count; ++one) {
        for (let other = 0; other < one; ++other) {
            if (connections[one].friends.has(other)
                || [...connections[one].friends].some(friend => connections[other].friends.has(friend))
                ) {
                connections[one].two_friends += 1
                connections[other].two_friends += 1
            }
        }
    }
    console.log(Math.max(...connections.map(person => person.two_friends)))
})
