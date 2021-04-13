# AlarmSystem
# Table of Content
* 1. Introductory 
* 2. Video and Showcase
* 3. Materials
* 4. Build
* 5. Dependency and Usage
* 6. Future Plans
* 7. Final Remarks
# Introductory
  Before starting with the showcase, I would like to mention that this build is not fully finish to my standards due to time crunch and being a beginner coder. I did not get to add a sound system to this fire alarm like I wanted, but I did manage to create an on and off kill switch to this alarm system code. I got this alarm code by James Bruce, where it detects movement, then scare the heck out of an intruder with a high pitched alarm sounds and flashing lights, but I changed this code by adding an on and off kill switch to the system because the code lacked a power button. The setbacks of this code was that there was no on and off switch for the alarm. It just triggeres the alarm on any body who comes in the range of the sensor. 
  
James Bruce Simple Fire Alarm Link : https://www.makeuseof.com/tag/how-to-make-a-simple-arduino-alarm-system/
# Video and Showcase
# Materials 
Here are the list of Materials you will need to create this sound system:
- 1 x Arduino Uno
- 1 x 5v LED Strip
- 1 x Ultrasonic Ping Sensor (HC-SR04) 
- 1 x Piezo Buzzer
- 3 x MOFSET N Transistors
- 2 x Resistors
- 24 x Wires

Dependency:
- NewPing (https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
# Build
  Here are the step by step process on creating the alarm system in the Arduino Uno, I will try to section this off from left to right. 
  ![Alarm_bb](https://user-images.githubusercontent.com/79666499/114623686-d4788000-9c6c-11eb-8e68-5877ed601503.png)
  (FULL Breadboard) 
  
  <h3> Lights: 
  
  For this breadboard image I will be using the 4 pin LED light to Substitute the LED Strip lights due to no having an LED Strip light part in Fritzing. For the LED strip make sure to buy a 5 volt LED strip because if the voltage was any higher, you would need to buy a volt power supply for higher LED Strip voltage. If you look closely in your LED it should have a marking of: 5v, Green, Red, and Blue; this markings allows us to know which pins they lead to. The MOFSETs are used to isolate the current from the Arduino because connecting the strips directly to the Arduino would fry it with the amount of current they draw. A MOFSET has 3 pins: gate, source and dran; the gate is an electronic switch that the arduino controls so we connect the gate to the output, the source connects through the LED strip channel, and the drain is connected to the ground. 
  
  From left to right the pins for the LED Strip should be: Volts, Green, Red, Blue
  From left to right the pins for the MOFSET should be: Gate, Source, Drain
  To connect the Led to the Arduino you would want to connect the Green pin to 11, Red pin to 10, and Blue pin to 9
  
![Lights_bb](https://user-images.githubusercontent.com/79666499/114625024-e2c79b80-9c6e-11eb-8e84-6f15e976f5f5.png)

<h3> Buzzer:
  
  The buzzer is easy to hook up, a buzzer has two pins: 
  
  one of the pin should be connected to pin 3
  and the other pin is connected to ground
  
  ![Buzzer_bb](https://user-images.githubusercontent.com/79666499/114625382-684b4b80-9c6f-11eb-9b4d-d3ded067d04c.png)
  
<h3> Buttons: 
  
  For the buttons you would need two of them, one on switch and one kill switch. The on switch turns on the senors, while the kill switch resets and turns off the alarm system. 
  
  For the On switch connect it to pin 13
  For the Off switch connect it to pin 12
  
  ![Button_bb](https://user-images.githubusercontent.com/79666499/114625647-ce37d300-9c6f-11eb-84f1-b6b3af9263c4.png)

<h3> Sensor: 
  
  For the sensor pin you will find 4 pins in it: VCC, TRIG, ECHO, and GND. The VCC and GND are the power source, TRIG send sonar signals, and ECHO is used to read the signal back. 
  
  For the VCC pin connect it to volts rails
  For the GND pin connect it to ground
  For the TRIG pin connect it to pin 6
  For the ECHO pin connect it to pin 7
  
  ![Sensor_bb](https://user-images.githubusercontent.com/79666499/114626312-c7f62680-9c70-11eb-91de-6ae70039a745.png)
  
# Dependency and Usage
<h3> Dependency
To use the ping sensor users would need to add NewPing in their libraries. https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home

<h3> Usage
  To use this alarm system, you can put it anywhere you want to. For me, I stick the LED strips around my door frame and hid the arudino in the corner below the door frame. Make sure that the sensors are not getting block with any obstruction. Another thing to think about is the distance of your sensors and how long you want it to sense movement. 
  
# Future Plans
For some future plans, I would like to acutally add the sound system for his alarm. I got the materials for it, but I was having troubles with the sound to code process because it was a lot of lines of code. If I get better at coding in general, I would like to change sensors in facial recognition, where it allows the user to only detect a specific face to go through the alarm system and if the person does not match the facial recognition the alarm would go off. 

# Final Remarks
I would like to thank CS207, for showing me some new knowledge about coding as a beginner coder, I had some ups and downs coding, but it was really fun overall. 

<h3> Links to where I got some of the materials:
  
  * 5v LED Strips (https://www.amazon.ca/Backlight-Lighting-Controller-inch-65-Monitor/dp/B08D6RZRGN?pd_rd_w=cfXVw&pf_rd_p=0ba79034-c53d-434f-9818-5f9152f407a5&pf_rd_r=T80TXFNBD5QEAAZWY1Q4&pd_rd_r=dd7addf8-54a2-4353-b5b8-346bde7b48e2&pd_rd_wg=FnnaP&pd_rd_i=B08D6RZRGN&psc=1&ref_=pd_bap_d_rp_1_i)
  * Ping Sensor (https://www.amazon.ca/Sainsmart-HC-SR04-Ranging-Detector-Distance/dp/B004U8TOE6?pd_rd_w=cfXVw&pf_rd_p=0ba79034-c53d-434f-9818-5f9152f407a5&pf_rd_r=T80TXFNBD5QEAAZWY1Q4&pd_rd_r=dd7addf8-54a2-4353-b5b8-346bde7b48e2&pd_rd_wg=FnnaP&pd_rd_i=B004U8TOE6&psc=1&ref_=pd_bap_d_rp_7_i)
  * MOFSETs (https://www.amazon.ca/Value-10N06-N-Channel-MOSFET-Transistor/dp/B07S3XH7DS/ref=sr_1_1?dchild=1&keywords=MOFset&qid=1618352477&sr=8-1)

Specials thanks to:

* Bruce, James.“How To Make a Simple Arduino Alarm System.” MUO, 26 Aug. 2013, www.makeuseof.com/tag/how-to-make-a-simple-arduino-alarm-system/. 
