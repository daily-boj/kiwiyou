const readline = require('readline')
const interface = readline.createInterface(process.stdin)

let line_count = 0
let people_count = 0
let from, to
let people
interface.on('line', line => {
    if (line_count === 0) {
        people_count = Number(line)
        people = Array.from({ length: people_count }).map(() => [])
    } else if (line_count === 1) {
        [from, to] = line.split(' ').map(Number)
        --from, --to
    } else if (line_count >= 3) {
        let [one, other] = line.split(' ').map(Number)
        people[one - 1].push(other - 1)
        people[other - 1].push(one - 1)
        return
    }
    ++line_count
}).on('close', () => {
    let next_visit = [from]
    let next_depth = [0]
    let visited = Array.from({ length: people_count })
    visited[from] = true
    while (next_visit.length > 0) {
        let current = next_visit.pop()
        let depth = next_depth.pop()
        if (current === to) {
            console.log(depth)
            return
        }
        depth += 1
        for (const blood of people[current]) {
            if (!visited[blood]) {
                visited[blood] = true
                next_visit.push(blood)
                next_depth.push(depth)
            }
        }
    }
    console.log('-1')
})
