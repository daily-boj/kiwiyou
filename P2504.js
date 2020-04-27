const fs = require('fs')
const text = fs.readFileSync('/dev/stdin').toString().replace(/\(\)/g, '2').replace(/\[\]/g, '3')

const stack = [{value: 0}]
try {
    for (const char of text) {
        switch (char) {
            case '(':
                stack.push({
                    type: 0,
                    value: 0
                })
                break
            case '[':
                stack.push({
                    type: 1,
                    value: 0
                })
                break
            case '2':
                if (stack.length < 1) {
                    throw 1
                }
                stack[stack.length - 1].value += 2
                break
            case '3':
                if (stack.length < 1) {
                    throw 1
                }
                stack[stack.length - 1].value += 3
                break
            case ')': {
                if (stack.length < 1 || stack[stack.length - 1].type !== 0) {
                    throw 1
                }
                let { value } = stack.pop()
                stack[stack.length - 1].value += value * 2
            }
                break
            case ']': {
                if (stack.length < 1 || stack[stack.length - 1].type !== 1) {
                    throw 1
                }
                let { value } = stack.pop()
                stack[stack.length - 1].value += value * 3
            }
                break
        }
    }
    if (stack.length > 1) throw 1
    console.log(stack.pop().value)
} catch (e) {
    console.log('0')
}