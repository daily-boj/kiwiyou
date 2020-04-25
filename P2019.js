const fs = require('fs')
const lines = fs.readFileSync('/dev/stdin').toString().split('\n')
lines.shift()
const vertices = []
const edges = []
for (const line of lines) {
    let [x1, y1, x2, y2] = line.split(' ').map(Number)
    --x1, --y1, --x2, --y2
    let index1 = vertices.indexOf(y1 * 10000 + x1)
    if (index1 < 0) {
        index1 = vertices.push(y1 * 10000 + x1) - 1
        edges.push({ friend: [], visited: false })
    }
    let index2 = vertices.indexOf(y2 * 10000 + x2)
    if (index2 < 0) {
        index2 = vertices.push(y2 * 10000 + x2) - 1
        edges.push({ friend: [], visited: false })
    }
    if (index1 === index2) continue;
    edges[index1].friend.push(index2)
    edges[index2].friend.push(index1)
}

let cycles = 0
for (let i = 0; i < edges.length; ++i) {
    if (edges[i].visited) continue
    const next = [i]
    edges[i].visited = true
    let is_cycle = true
    while (next.length > 0) {
        let current = next.pop()
        if (edges[current].friend.length !== 2) is_cycle = false
        for (const friend of edges[current].friend) {
            if (!edges[friend].visited) {
                next.push(friend)
                edges[friend].visited = true
            }
        }
    }
    if (is_cycle) {
        ++cycles
    }
}

console.log(cycles)