import java.net.Socket

var isOn = true

while (isOn) {
    val address = readLine()!!
    val port = readLine()!!.toInt()

    try {
        val socket = Socket(address, port)
        println("Connected to $address:$port")
        socket.close()
    } catch (e: Exception) {
        println("Error: ${e.message}")
        isOn = false
    }
}
