package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

var isOn = true

func main() {
	for isOn {
		fmt.Print("Enter the address to connect to: ")
		reader := bufio.NewReader(os.Stdin)
		address, _ := reader.ReadString('\n')
		fmt.Print("Enter the port to connect to: ")
		port, _ := reader.ReadString('\n')

		conn, err := net.Dial("tcp", address+port)
		if err != nil {
			fmt.Println("Error: ", err.Error())
			isOn = false
		} else {
			fmt.Println("Connected to ", address, ":", port)
			conn.Close()
			isOn = false
		}
	}
}
