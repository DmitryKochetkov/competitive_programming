import java.util.stream.Collectors

fun main(args: Array<String>) {
    val reader = java.util.Scanner(System.`in`)

    val n = reader.nextLine().toInt()
    var input = ArrayList<String>()
    var ans = ""

    var max1 = ""
    var max2 = ""

    var mid1 = ""
    var mid2 = ""

    for (i in 0 until 2*n-2) {
        input.add(reader.nextLine())
        ans += '.'

        if (input[i] > max1)
            max1 = input[i]
        else if (input[i] > max2)
            max2 = input[i]

        if (input[i].length == n / 2 + 1)
            if (mid1 == "")
                mid1 = input[i]
            else if (mid2 == "")
                mid2 = input[i]
    }

    println(max1)
    println(max2)
    println(mid1)
    println(mid2)
}