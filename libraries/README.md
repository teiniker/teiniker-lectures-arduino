# Arduino Libraries

Arduino Libraries are a **collection of code** that makes it easy for you to connect to a sensor, 
display, module, etc.

## Library Manager
The Arduino IDE comes with a build-in Library Manager.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Manage Libraries**.
  There, we can find a list of libraries that are already installed or ready for installation.
* Scroll the list to find the right library, click on it and select the version of the library we 
  want to install.
* Finally, click on install and wait for the IDE to install the new library.
  Once it has finished, an Installed tag should appear next to the library.
  Now we can close the library manager.

## Import a ZIP File
Libraries are often distributed as a ZIP file.
The name of the file (which includes a folder of the same name) is the name of the library.
Inside the folder will be a .cpp file, a .h file and often a keywords.txt file, examples folder, 
and other files required by the library.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Add .ZIP Library...**.
* Navigate to the .zip file's location and open it.
* Return to the **Sketch > Include Library** menu and now we can see the library at the 
  bottom of the drop-down menu.
  The zip file has been expanded in the **Arduino/libraries** folder in your Arduino installation.

## Manual Installation
We can do the same steps as in "Inport a ZIP File" but manually.
* Download the library as a ZIP file and expand it.
* Move the library directory into the **Arduino/libraries** folder.
* Start the Arduino IDE, go to **Sketch > Include Library**. Verify that the library we just added 
  is available in the list.


## References

* [Arduino Standard Libraries](https://www.arduino.cc/en/reference/libraries)
* [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries)

*Egon Teiniker, 2020 - 2021, GPL v3.0* 