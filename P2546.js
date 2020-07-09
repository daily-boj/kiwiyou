let units, unit
require('readline').createInterface(process.stdin).on('line', line => {
    if (!units) units = +line
    else if (!unit) unit = {}
    else if (!unit.c) [unit.c, unit.econ] = line.split(' ').map(Number)
    else if (!unit.ciq) unit.ciq = line.split(' ').map(Number)
    else {
        unit.eiq = line.split(' ').map(Number)
        const csum = unit.ciq.reduce((a, b) => a + b)
        const esum = unit.eiq.reduce((a, b) => a + b)
        console.log(unit.ciq.reduce((cnt, iq) => cnt + ((csum - iq) > iq * (unit.c - 1) && esum < iq * unit.econ), 0))
        unit = null
    }
})