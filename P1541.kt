fun main(args: Array<String>) {
    var chunks = readLine()!!.split("-")
    var base = chunks[0].split("+").map(::convert).sum()
    for (i in 1 until chunks.size) {
        base -= chunks[i].split("+").map(::convert).sum()
    }
    println(base)
}

fun convert(s: String): Int {
    return if (s == "") {
        0
    } else {
        s.toInt()
    }
}