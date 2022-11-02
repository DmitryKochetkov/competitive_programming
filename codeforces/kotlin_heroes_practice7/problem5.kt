import java.util.stream.Collectors

fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val n = reader.nextLine().toInt()

    var a = reader.nextLine().split(" ").stream().map { s -> s.toLong() }.collect(Collectors.toList())

    var b = ArrayList<Long>(n)
    var s = 0L

    for (i in 0 until n)
        s += a[i]

    var c = 0
    var indeces = ArrayList<Int>(0)

    for (i in 0 until n)
        if (s - a[i] == a[i]) {
            c += 1
            indeces.add(i)
        }

    println(c)
    for (i in indeces)
        print(i)
}