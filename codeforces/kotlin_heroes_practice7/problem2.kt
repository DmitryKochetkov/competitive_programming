fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val t = reader.nextInt()
    for (i in 1..t) {
        val a = reader.nextLong()
        val b = reader.nextLong()
        val k = reader.nextLong()

        var res = (k / 2) * (a - b)
        if (k % 2L == 1L)
            res += a
        println(res)
    }
}