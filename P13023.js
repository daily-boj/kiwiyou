const readline = require('readline')
const interface = readline.createInterface(process.stdin)

interface.once('line', line => {
    const [ppl_count, rel_count] = line.split(' ').map(Number)
    const friends = Array.from({length: ppl_count}, () => ({ relation: [] }))
    const visited = Array.from({length: ppl_count}).fill(false)
    interface.on('line', line => {
        const [a, b] = line.split(' ').map(Number)
        friends[a].relation.push(b)
        friends[b].relation.push(a)
    }).on('close', () => {
        let found = false
        const dfs = (i, depth) => {
            if (found) {
                return
            } else if (depth >= 5) {
                found = true
                return
            }
            for (const friend of friends[i].relation) {
                if (!visited[friend]) {
                    visited[friend] = true;
                    dfs(friend, depth + 1)
                    visited[friend] = false;
                }
            }
        }
        for (let i = 0; i < ppl_count; ++i) {
            dfs(i, 0)
        }
        console.log(1 * found)
    })
})