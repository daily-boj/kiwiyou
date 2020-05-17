const rl = require('readline').createInterface(process.stdin)

let line_count = 0
let cities, buses
let connection
rl.on('line', line => {
    ++line_count
    if (line_count == 1) {
        cities = Number(line)
        connection = Array.from({ length: cities }, () => {
            const array = Array.from({ length: cities })
            array.fill(Infinity)
            return array
        })
    } else if (line_count == 2) {
        buses = Number(line) + 3
    } else if (line_count === buses) {
        let [start, end] = line.split(' ').map(Number)
        --start, --end
        const visited = new Set()
        const distance = Array.from({ length: cities })
        distance.fill(Infinity)
        distance[start] = 0
        while (visited.size < cities) {
            let min_distance = Infinity
            let min_vertex
            for (let v = 0; v < cities; ++v) {
                if (!visited.has(v) && distance[v] < min_distance) {
                    min_distance = distance[v]
                    min_vertex = v
                }
            }
            if (min_vertex == end) {
                console.log(min_distance)
                return
            }
            visited.add(min_vertex)
            const neighbours = connection[min_vertex]
            for (let neighbour = 0; neighbour < cities; ++neighbour) {
                if (neighbours[neighbour] === Infinity) {
                    continue
                }
                let alternative = distance[min_vertex] + neighbours[neighbour]
                if (alternative < distance[neighbour]) {
                    distance[neighbour] = alternative
                }
            }
        }
        console.log(distance[end])
    } else {
        const [bus_start, bus_end, weight] = line.split(' ').map(Number)
        connection[bus_start - 1][bus_end - 1] = Math.min(connection[bus_start - 1][bus_end - 1], weight)
    }
})