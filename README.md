Laser Rangefinder Simulator Interface
 Project Goal:
The aim of this project was to develop a physical device that emulates a laser rangefinder, used for measuring distances within a simulated environment. The project was created to enhance the realism of artillery training by providing a more immersive and tactile experience.

Project Context:
This device was designed as an immersion-enhancing tool for use in military training simulators, such as Arma 3. Instead of relying solely on on-screen UI, trainees can physically “measure” the distance to a virtual target — just like with a real rangefinder.

When the user presses a button, a laser pointer is activated to assist in aiming. Meanwhile, the simulator calculates the in-game distance and saves it to a .txt file. A lightweight Python Flask server shares this file over a local network.

An ESP32 microcontroller continuously queries the server, retrieves the current distance, and displays it on a small OLED screen, mimicking the behavior of a real-world laser rangefinder device.

Technologies Used:
ESP32 microcontroller (Wi-Fi-enabled)

OLED display (I2C)

Laser pointer module

Python + Flask (minimal server)

Simulation environment (e.g., Arma 3)

Text file as data bridge between simulation and hardware

