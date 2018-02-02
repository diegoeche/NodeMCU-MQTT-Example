## Setup your NodeMCU

1. Install the cp210x driver
2. Install the ESP8266 driver for Arduino
3. Load the sketch
4. Install the required libraries (PubSubClient, ...)

## Change the SSID/Password in the code

It defaults to use Geeny's Guest network

## Convert the Geeny Keys

This is mostly based on:

https://hackaday.io/project/12482-garage-door-opener/log/45617-connecting-the-esp8266-with-tls

openssl x509 -in geeny-ca.crt -sha1 -noout -fingerprint
> SHA1 Fingerprint=0C:91:46:C8:05:FE:23:41:18:52:DE:61:C5:40:2F:B4:CA:D1:EC:9D

// Convert certificates to .der
openssl x509 -outform der -in thing.crt -out thing-crt.der
openssl rsa -outform der -in thing.key -out thing-key.der

## TODO:

Fingerprint check in the client
