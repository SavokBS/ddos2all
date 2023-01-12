<?php

$isOn = true;

while ($isOn) {
    echo "Enter the address to connect to: ";
    $address = readline();
    echo "Enter the port to connect to: ";
    $port = readline();
    $fp = @fsockopen($address, $port, $errno, $errstr, 10);
    if (!$fp) {
        echo "Error: $errstr ($errno)\n";
    } else {
        echo "Connected to $address:$port\n";
        fclose($fp);
        $isOn = false;
    }
}
?>
