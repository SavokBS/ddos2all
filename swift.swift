import Foundation

var isOn = true

while isOn {
    print("Enter the address to connect to: ")
    guard let address = readLine() else { break }
    print("Enter the port to connect to: ")
    guard let portString = readLine(), let port = UInt16(portString) else { break }
    
    let socket = Socket(address: address, port: port)
    do {
        try socket.connect()
        print("Connected to \(address):\(port)")
        socket.close()
        isOn = false
    } catch {
        print("Error: \(error)")
        isOn = false
    }
}
