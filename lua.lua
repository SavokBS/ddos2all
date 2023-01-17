local socket = require("socket")
local isOn = true

while isOn do
  print("Enter the address to connect to: ")
  local address = io.read()
  print("Enter the port to connect to: ")
  local port = io.read()
  
  local client, err = socket.tcp()
  if err then
    print("Error: ", err)
    isOn = false
  else
    client:connect(address, port)
    print("Connected to ", address, ":", port)
    client:close()
    isOn = false
  end
end
