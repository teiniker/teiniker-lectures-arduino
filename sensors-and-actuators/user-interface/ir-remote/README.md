# Infrared Remote Control

Infrared (IR) remote controls and receivers, like those used for TVs, operate using infrared light to send signals. Here's a basic overview of how they work:

**IR Remote Control (Transmitter)**
* **User Input**: When a button is pressed on the remote, it generates 
    a specific signal corresponding to that function (e.g., volume up, 
    channel change).

* **Signal Encoding**: This signal is encoded into a binary format, 
    representing different commands as different sequences of 1s and 0s.

* **Modulation**: The binary signal modulates an infrared light signal. 
    This is typically done using a Light Emitting Diode (LED) that emits 
    infrared light. The modulation usually involves pulsing the infrared 
    light at a specific frequency (**38 kHz is common**).

* **Transmission**: The modulated infrared light is transmitted towards 
    the TV. Infrared light is invisible to the human eye but can be 
    detected by electronic sensors.

**IR Receiver**
* **Detection**: The receiver on the TV, which is an IR sensor, detects 
    the infrared light pulses.

* **Demodulation**: The receiver demodulates the signal, it extracts the 
    binary signal from the pulsed infrared light.

* **Decoding**: The binary signal is decoded into a command. The receiver's 
    circuitry is designed to recognize different patterns as different commands.

* **Action**: Once the command is recognized, the TV executes the corresponding 
    action (e.g., changing the channel, adjusting the volume).

When working with IR, one should consider the following points:
* **Line of Sight**: Infrared communication typically requires a line of sight 
    between the remote and the receiver. This is because IR light, like visible 
    light, does not bend around corners.

* **Range and Angle**: The effective range and angle depend on the strength 
    of the IR LED in the remote and the sensitivity of the IR receiver. 
    Typically, this range is limited to a few meters.

* **Interference**: Devices that emit infrared light or heat can potentially 
    interfere with the IR signal. Sunlight, for instance, can cause interference.

* **Frequency**: The use of a specific modulation frequency (like 38 kHz) helps 
    the receiver distinguish the signal from ambient infrared light.

IR remote controls are a simple and effective technology, widely used due to 
their low cost and ease of implementation. However, they are being gradually supplemented or replaced by **radio frequency (RF)** and **Bluetooth** controls 
in some applications, which do not require line of sight and can offer greater 
range and functionality.


## Simulation

_Example:_ Tinkercad - [IR Receiver](https://www.tinkercad.com/things/dFI00lKMRg4-arduino-ir-receiver)



## References

*  [DroneBot Workshop: Using IR Remote Controls with the Arduino](https://youtu.be/8E3ltjnbV0c?si=6a-uyWbBkqdgAiZ9)

* [Arduino IRRemote Library](https://github.com/Arduino-IRremote/Arduino-IRremote)

*Egon Teiniker, 2020 - 2024, GPL v3.0* 
