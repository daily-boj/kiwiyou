const readline = require('readline')
const interface = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

let line_number = 0;
let computer_count;
const connection = Array.from({ length: 101 }).map(() => ({ friends: new Set() }))
interface.on('line', line => {
    if (line_number === 0) {
        computer_count = Number(line)
    } else if (line_number >= 2) {
        const [one, other] = line.split(' ').map(Number)
        connection[one].friends.add(other)
        connection[other].friends.add(one)
    }
    line_number += 1
}).on('close', () => {
    visited = Array.from({ length: computer_count + 1 }).map(() => false)
    visited[1] = true
    to_visit = [1]
    while (to_visit.length > 0) {
        let current = to_visit.pop()
        for (const friend of connection[current].friends) {
            if (!visited[friend]) {
                visited[friend] = true
                to_visit.push(friend)
            }
        }
    }

    console.log(visited.reduce((prev, current) => current ? prev + 1 : prev) - 1)
})
