# Controller Area Network 

The Controller Area Network (CAN) Bus is a robust vehicle bus standard designed 
to allow microcontrollers and devices to communicate with each other's applications 
without a host computer. 

It was originally developed in the 1980s by **Bosch** for automotive applications 
to connect electronic control units (ECUs) within vehicles. Since then, its use has 
expanded into many other areas, including industrial automation, medical equipment, 
and other demanding environments.


Key aspects of the CAN Bus system:

* **Network Topology**: CAN Bus typically employs a differential signal to reduce 
    susceptibility to interference. The network is usually arranged in a bus topology, 
    connecting all devices in parallel.
* **Data Transmission**: It uses a multi-master serial bus standard for communication. 
    Each node can send and receive messages but not simultaneously, using a message-based protocol.
* **Speed**: CAN Bus offers different transmission rates, from lower speeds like 125 kbps 
    to higher speeds up to 1 Mbps, depending on the length of the cable and the specific 
    CAN standard used.
* **Error Handling**: It has sophisticated error detection and handling mechanisms. The 
    system can detect errors, signal them to other devices, and attempt to correct or 
    isolate faulty nodes.
* **Standards**: The original CAN standard (now known as CAN 2.0A) introduced an 11-bit
    identifier, while the extended CAN 2.0B standard supports a 29-bit identifier, 
    allowing for more devices and more detailed messaging.


## CAN Bus Frames


A CAN 2.0 frame consists of several distinct parts, each serving a specific purpose:

1. **Start of Frame (SOF)**
    * A single dominant bit that marks the beginning of a frame. It's used to 
        synchronize all nodes on the network to the start of the message.

2. **Arbitration Field**
    * **Identifier** (11 bits for standard CAN 2.0A or 29 bits for extended CAN 2.0B): 
        Determines the message's priority and its type (data or remote). 
        Lower numerical values have higher priority.
    * **Remote Transmission Request (RTR)** bit (1 bit): Differentiates between data 
        frames (dominant bit) and remote frames (recessive bit).

3. **Control Field**
    * **Identifier Extension (IDE) bit (1 bit)**: Indicates whether the frame uses a 
        standard (0) or extended (1) identifier.
    * **Reserved bits (r0, r1 for CAN 2.0B)**: Reserved for future use; typically set 
        to dominant (0).
    * **Data Length Code (DLC) (4 bits)**: Specifies the number of bytes in the data 
        field, ranging from 0 to 8 bytes.

4. **Data Field**
    * Contains the actual **data being transmitted**. Its length is indicated by the 
        DLC and can be up to 8 bytes for CAN 2.0.

5. **CRC Field**
    * **CRC Sequence (15 bits)**: A cyclic redundancy check sequence that allows 
        receiving nodes to detect errors in the message.
    * **CRC Delimiter (1 recessive bit)**: Marks the end of the CRC sequence.

6. **Acknowledge Field**
    * **ACK Slot (1 bit)**: The transmitter sends a recessive bit (1), and a receiver 
        acknowledges the receipt of a valid message by overwriting this bit with a 
        dominant bit (0).
    * **ACK Delimiter (1 recessive bit)**: Marks the end of the acknowledgment section.

7. **End of Frame (EOF)**
    * A sequence of 7 recessive bits indicating the end of a frame.

The design of the CAN bus frame, with its detailed structure, ensures efficient 
use of the network bandwidth, minimizes collision potential through priority-based 
arbitration, and enhances data integrity with error detection mechanisms. 


The CAN protocol specifies several **types of frames** for communication among devices on the 
network. These frames are designed to ensure reliable transmission of data, error handling, 
and network management. 

Here's an overview of the different CAN frames:

* **Data Frame**: Used to transmit data from the sender to the receiver(s).
    * Contains an arbitration ID, control fields, data (up to 8 bytes for standard CAN 2.0 
        and up to 64 bytes for CAN FD), and a CRC (Cyclic Redundancy Check) for error detection.
    * The arbitration ID determines the priority of the message; lower values have higher priority.

* **Remote Frame**: Used to request data from another device. A node sends a remote
    frame to request a data frame with the same arbitration ID.
    * Similar to a data frame but contains no data field. It's identified by the 
        RTR (Remote Transmission Request) bit set to a different value than in data frames.
    * Upon receiving a remote frame, the addressed device responds with a data frame carrying 
        the requested data.

* **Error Frame**: Used to signal an error in data transmission. When a node detects 
    an error, it transmits an error frame to alert other nodes.
    * Consists of two fields: 
        * **Error Flag** disrupts the normal form of the frame to indicate an error.
        * **Error Delimiter** marks the end of the error frame.
    * The transmission of an error frame leads to automatic retransmission of the corrupted 
        frame unless it was deemed as an error passive.

* Overload Frame: Used to request a delay between the transmission of messages. It's mainly 
    used to manage the receiver's ability to process incoming frames.
    * Similar to the error frame, it includes an Overload Flag followed by an Overload Delimiter.
    * Overload frames are used to manage congestion or to allow for additional processing 
        time at the receiver.

The design of these frames allows CAN to provide high levels of fault tolerance and data 
integrity in complex automotive and industrial applications.



## CAN Physical Layer 



## References

* [YouTube (Texas Instruments): CAN physical layer](https://youtu.be/4nk8Lb_K8rs?si=QXvdk2lZZQUiHSzt)
* [YouTube (Texas Instruments): CAN and CAN FD protocol](https://youtu.be/2Mhqwt2xTxk?si=EeA1K7nyD_MrK5NF)

* Dogan Ibrahim, Ahmet Ibrahim. **The CAN Bus Companion**. Elector International Media, 2023

*Egon Teiniker, 2020-2024, GPL v3.0* 