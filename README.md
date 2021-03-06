Arduino library for distance sensors
====================================

The current version provides a unified interface for four sensors:

 * SRF04 & SRF05 Ultrasonic Ranger
 * Sharp GP2Y0A21YK IR Distance sensor
 * Sharp GP2Y0A41SK IR Distance sensor

Code for the individual sensors in also maintained in separate Google code projects. (http://code.google.com/u/104098523773938750140/)

Other Sharp distance sensors:
-----------------------------

Currently this library only supports the sensors mentioned above.
If you want to use other distance sensors with this libraries you can do that by adding the appropriate source files.
Have a look at the class diagram below to get an idea of the structure.

Adding an other analog Sharp sensor would mean copy/pasting some of the existing (.cpp & .h) files and changing some parameters in the calculation in the function "getDistanceCentimeter".
You can either derive the parameters from your datasheet or perform a linear regression on experimental data using (1/distance on the X-axis!)

Feel free to fork this project & send me a pull request if you have some correctly working code.

Folders:
--------
 * DistanceSensor: source for the Arduino library
 * Documentation: generated with Doxygen (html, Latex)
  
Class diagram:
--------------
 
![Class diagram](https://raw.github.com/jeroendoggen/arduino-distance-sensor-library/master/Documentation/html/class_distance_sensor__inherit__graph.png)
