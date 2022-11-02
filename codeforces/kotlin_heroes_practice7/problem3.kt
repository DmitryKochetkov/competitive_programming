fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val t = reader.nextInt()
    for (i in 1..t) {
        val n = reader.nextInt()
        val k = reader.nextInt()

        val m = n / k

        var c = 'a'
        var res = ""

        for (j in 1..k) {
            res += c.toString().repeat(m)
            c += 1
        }

        res += (c-1).toString().repeat(n % k)
        println(res)
    }
}