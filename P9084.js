const rl = require('readline').createInterface(process.stdin)

let unit
rl.on('line', line => {
    if (!unit) {
        unit = {}
    } else if (!unit.types) {
        Object.assign(unit, {
            types: +line,
            values: null,
            cases: Array.from({ length: 10001 }, () => Array.from({ length: +line }, () => 0)),
        })
    } else if (!unit.values) {
        unit.values = line.split(' ').map(Number)
    } else {
        const target = +line
        const { types, values, cases } = unit
        cases[values[0]][0] = 1
        for (let money = 2 * values[0]; money <= target; ++money) {
            cases[money][0] = cases[money - values[0]][0]
        }
        for (let type = 1; type < types; ++type) {
            const value = values[type]
            cases[value][type] = 1
            for (let money = value + 1; money <= target; ++money) {
                cases[money][type] = cases[money - value][type]
                for (let subtype = 0; subtype < type; ++subtype) {
                    cases[money][type] += cases[money - value][subtype]
                }
            }
        }
        let sum = 0
        for (let type = 0; type < types; ++type) {
            sum += cases[target][type]
        }
        console.log(sum)
        unit = {}
    }
})