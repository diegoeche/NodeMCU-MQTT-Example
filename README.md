# NodeMCU-MQTT-Example

TODO: More detailed example.

This is mostly based on:

https://hackaday.io/project/12482-garage-door-opener/log/45617-connecting-the-esp8266-with-tls

openssl x509 -in geeny-ca.crt -sha1 -noout -fingerprint
> SHA1 Fingerprint=0C:91:46:C8:05:FE:23:41:18:52:DE:61:C5:40:2F:B4:CA:D1:EC:9D

// Convert certificates to .der
openssl x509 -outform der -in thing.crt -out thing-crt.der
openssl rsa -outform der -in thing.key -out thing-key.der
