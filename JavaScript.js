const net = require('net');

let isOn = true;

while (isOn) {
    const address = prompt('Enter the address to connect to: ');
    const port = parseInt(prompt('Enter the port to connect to: '));

    const client = net.createConnection({
        host: address,
        port: port
    }, () => {
        console.log(`Connected to ${address}:${port}`);
    });

    client.on('error', (error) => {
        console.log(`Error: ${error}`);
        isOn = false;
    });

    client.on('end', () => {
        console.log('Connection closed');
        isOn = false;
    });
}
