import java.util.stream.Collectors

fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val n = reader.nextLine().toInt()

    var a = reader.nextLine().split(" ").stream().map { s -> s.toLong() }.collect(Collectors.toList())
    a.sort()

    var c = 0L
    for (i in 0 until n-1 step 2) {
        c += a[i+1] - a[i]
    }

    print(c)
}