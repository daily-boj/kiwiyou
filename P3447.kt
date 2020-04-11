fun main(args: Array<String>) {
    var line = readLine()
    while (line != null) {
        var removed = true
        var output = line!!
        while (removed) {
            var temp = output.replace("BUG", "")
            removed = temp.length < output.length
            output = temp
        }
        println(output)
        line = readLine()
    }
}