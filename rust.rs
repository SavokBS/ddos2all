use std::io;
use std::net::TcpStream;

let mut is_on = true;

while is_on {
    println!("Enter the address to connect to: ");
    let mut address = String::new();
    io::stdin().read_line(&mut address).unwrap();
    let address = address.trim();

    println!("Enter the port to connect to: ");
    let mut port = String::new();
    io::stdin().read_line(&mut port).unwrap();
    let port = port.trim();

    match TcpStream::connect(format!("{}:{}", address, port)) {
        Ok(stream) => {
            println!("Connected to {}:{}", address, port);
            is_on = false;
        },
        Err(e) => {
            println!("Error: {}", e);
            is_on = false;
        }
    }
}
