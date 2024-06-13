# Gecko Terrarium Environmental Monitoring

This Arduino project provides environmental monitoring for a gecko terrarium. It currently monitors the temperature and humidity on the hot side of the terrarium, as well as the ambient light outside the terrarium. The project is designed to ensure that Sunny the Gecko lives in a comfortable and well-regulated environment.

## Features

- **Temperature Monitoring**: Continuously monitors the temperature on the hot side of the terrarium to ensure it stays within a suitable range for your gecko.
- **Humidity Monitoring**: Tracks the humidity levels on the hot side of the terrarium to maintain optimal conditions.
- **Ambient Light Monitoring**: Measures the ambient light outside the terrarium to provide data for future lighting control.

## Future Enhancements

- **Cool Side Monitoring**: In the next update, the project will include a second sensor to monitor the temperature and humidity on the cool side of the terrarium.
- **Lighting Control**: Eventually, the system will control the terrarium lights to maintain a consistent schedule, simulating natural day-night cycles for Sunny the Gecko.

## Code Reuse

Please note that there is currently some extra unused code within this project. This is because the application reuses code from similar applications that I have written and maintain. Future updates will optimize and clean up the codebase as new features are added.

## Components Used

- NodeMCU ESP8266 microcontroller
- DHT22 sensor for temperature and humidity monitoring
- Light sensor (e.g., LDR or a photoresistor)
- Additional sensor (e.g., another DHT22) for future cool side monitoring

## Installation

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/jasonmce/gecko-tank.git
   ```

2. **Credentials file**:
   - Copy the credientials_example.h file to credentials.h
   - Set your Wifi connection credentials
   - Set your ThingSpeak channel ID and API Key

2. **Upload the Code**:
   - Open the `gecko_terrarium_monitoring.ino` file in the Arduino IDE.
   - Connect your Arduino board to your computer.
   - Select the appropriate board and port from the `Tools` menu.
   - Click on the `Upload` button to upload the code to your Arduino board.

3. **Connect the Sensors**:
   - Follow the wiring diagram provided in the repository to connect the DHT22 and light sensor to the Arduino board.
   - Ensure that all connections are secure and correct.

## Usage

Once the code is uploaded and the sensors are connected, the Arduino will begin monitoring the environment within the terrarium. You can view the temperature, humidity, and light readings on the oled display, and view notifications through the Serial Monitor in the Arduino IDE.

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or additional features you'd like to see, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

Sunny the Gecko and I hope this project helps you create a comfortable and well-monitored habitat for your reptile. Happy coding!

---

### Contact

For any questions or support, feel free to contact me at [gecko-tank-readme@brightshinyobject.com](mailto:gecko-tank-readme@brightshinyobject.com).

---

### Acknowledgements

Thanks to the Arduino community for their continuous support and contributions to open-source projects.

---

### Author

[Jason McEachen](https://github.com/jasonmce)

---

Enjoy monitoring your gecko terrarium with Arduino!

---
