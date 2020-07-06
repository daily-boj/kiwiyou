let N, k, cnt = 0
let max
require('readline').createInterface(process.stdin).on('line', line => {
    if (!N) [N, k] = line.split(' ').map(Number)
    else {
        [l, r] = line.split(' ').map(Number)
        if (!max) {
            max = Array(k + 1)
            max[0] = [l + r, -1, -1]
            max[1] = [-1, l, r]
        } else {
            const new_max = Array(k + 1)
            for (let i = 0; i < max.length; ++i) {
                if (max[i]) {
                    const [oo, oc, co] = max[i]
                    const new_oo = Math.max(oo, oc, co) + l + r
                    if (new_max[i]) {
                        new_max[i][0] = new_oo
                    } else {
                        new_max[i] = [new_oo, -1, -1]
                    }
                    if (i < k) {
                        let new_oc = Math.max(oo, oc)
                        let new_co = Math.max(oo, co)
                        if (new_oc >= 0 || new_co >= 0) {
                            new_max[i + 1] = [-1, new_oc + l, new_co + r]
                        }
                    }
                }
            }
            max = new_max
        }
        if (++cnt === N) {
            console.log(Math.max(...max[k].filter(a => a !== undefined)))
        }
    }
})