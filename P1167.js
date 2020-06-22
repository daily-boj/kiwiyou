const rl = require('readline').createInterface(process.stdin)
let v, list = [], x
rl.on('line', line => {
    if (!v) {
        x = v = +line
        list.length = v + 1
    } else {
        const edges = line.split(' ')
        const conn = []
        for (let i = 2; i < edges.length; i += 2) {
            conn.push([+edges[i - 1], +edges[i]])
        }
        list[+edges[0]] = conn
        if (--x === 0) {
            const dfs = from => {
                const found = Array.from({ length: v + 1 }, () => false)
                found[from] = true
                const next = [[from, 0]]
                let farthest = from, distance = 0
                while (next.length > 0) {
                    const [cur, len] = next.pop()
                    if (len > distance) {
                        farthest = cur
                        distance = len
                    }
                    for (const [node, d] of list[cur]) {
                        if (!found[node]) {
                            found[node] = true
                            next.push([node, len + d])
                        }
                    }
                }
                return [farthest, distance]
            }
            const [x, _d] = dfs(1)
            const [_y, dist] = dfs(x)
            console.log(dist)
        }
    }
})