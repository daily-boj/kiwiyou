const rl = require('readline').createInterface(process.stdin)

let unit
rl.on('line', line => {
    if (!unit) {
        unit = {}
    } else if (!unit.width) {
        const [width, height, pakchoi_left] = line.split(' ').map(Number)
        Object.assign(unit, {
            width,
            height,
            pakchoi_left,
            field: Array.from({ length: height }, () => Array.from({ length: width }, () => false)),
            visited: Array.from({ length: height }, () => Array.from({ length: width }, () => false)),
        })
    } else if (unit.pakchoi_left) {
        const [x, y] = line.split(' ').map(Number)
        unit.field[y][x] = true
        if (!--unit.pakchoi_left) {
            let caterpillar = 0
            for (let y = 0; y < unit.height; ++y) {
                for (let x = 0; x < unit.width; ++x) {
                    if (!unit.field[y][x] || unit.visited[y][x]) continue
                    ++caterpillar
                    unit.visited[y][x] = true
                    const next_visit = [{x, y}]
                    while (next_visit.length) {
                        const {x, y} = next_visit.pop()
                        if (x > 0 && unit.field[y][x - 1] && !unit.visited[y][x - 1]) {
                            next_visit.push({x: x - 1, y})
                            unit.visited[y][x - 1] = true
                        }
                        if (x < unit.width - 1 && unit.field[y][x + 1] && !unit.visited[y][x + 1]) {
                            next_visit.push({x: x + 1, y})
                            unit.visited[y][x + 1] = true
                        }
                        if (y > 0 && unit.field[y - 1][x] && !unit.visited[y - 1][x]) {
                            next_visit.push({x, y: y - 1})
                            unit.visited[y - 1][x] = true
                        }
                        if (y < unit.height - 1 && unit.field[y + 1][x] && !unit.visited[y + 1][x]) {
                            next_visit.push({x, y: y + 1})
                            unit.visited[y + 1][x] = true
                        }
                    }
                }
            }
            console.log(caterpillar)
            unit = {}
        }
    }
})