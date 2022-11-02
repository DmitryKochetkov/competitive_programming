fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val t = reader.nextInt()
    for (i in 1..t) {
        val a = reader.nextInt()
        val b = reader.nextInt()

        println(a+b)
    }
}