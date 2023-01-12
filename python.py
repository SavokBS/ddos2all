import socket

isOn = True

while isOn:
    address = input("Enter the address to connect to: ")
    port = input("Enter the port to connect to: ")
    try:
        s = socket.create_connection((address, int(port)), timeout=5)
        s.close()
        print("Connected to {}:{}!".format(address, port))
    except socket.timeout:
        print("Connection attempt failed, retrying in 5 seconds...")
    except:
        print("Unexpected error! " + str(e))
        isOn = False
