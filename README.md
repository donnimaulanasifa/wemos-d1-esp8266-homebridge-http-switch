# Wemos D1 http switch

You want to use Home app on your Apple device ?
Wemos D1 have a lot of function that can be merged with Homebridge, and controlled through apple device :)

## Chapter 1 Requirement

- Wireless network with internet connection
- Wemos D1 ( ESP8266 Module )
- Arduino relay module
- [Homebridge (Refer to the repo for instructions)](https://github.com/nfarina/homebridge)
- Apple device

## Chapter 2 Wemos D1

Upload the code to the Wemos D1, and set the wiring like the picture below :

![Diagram](https://i.ibb.co/Jrzr2Hm/68747470733a2f2f696d6167652e6962622e636f2f68454468464c2f576972696e672d52656c61792d4469616772616d2e6a7067.jpg)

## Chapter 3 Homebridge

Run the following command to install [homebridge-http-switch](https://github.com/Supereg/homebridge-http-switch)
```
sudo npm install -g homebridge-http-switch
```

Edit your config.json file (usually located in ~/.homebridge/config.json). find the "accessories", then put your device there :

```json
"accessories": [
   {
      "accessory": "HTTP-SWITCH",
      "name": "Switch",
      "switchType": "stateful",
      "httpMethod": "POST",
      "onUrl": "http:// / yourip /relay_on",
      "offUrl": "http:// / yourip /relay_off",
      
      "statusUrl": "http:// /yourip /relay_status",
   }   
]
```

## Chapter 4 Finally

Now that everything is in place its time to test!

You should see Homebridge as an accessory available to be connected. Use the pin number 031-45-154, this can be customised in the config.json file.

Once connected you can move this around within the App into the desired Room etc. Give Siri a test! It should be able to control the relay using voice!
