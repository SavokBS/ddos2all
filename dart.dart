import 'dart:io';

var isOn = true;

Future main() async {
  while (isOn) {
    stdout.write("Enter the address to connect to: ");
    var address = stdin.readLineSync();
    stdout.write("Enter the port to connect to: ");
    var port = int.parse(stdin.readLineSync());

    var socket = await Socket.connect(address, port);
    print("Connected to $address:$port");
    socket.close();
    isOn = false;
  }
}
