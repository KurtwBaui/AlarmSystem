#include <NewPing.h>
#include <NewTone.h>
 
// Select which PWM-capable pins are to be used.
const int RED_PIN = 10;
const int GREEN_PIN = 11;
const int BLUE_PIN = 9;
 
const int TRIGGER_PIN = 6;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const int ECHO_PIN = 7;  // Arduino pin tied to echo pin on the ultrasonic sensor.
const int MAX_DISTANCE = 200; // Maximum distance we want to ping for (in centimeters).
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
boolean armed = false;
extern int triggerAmount = 0;
 
const int ALARM = 3;
float sinVal;
int toneVal;

const int BUTTON = 13;
const int BUTTON2 = 12;
 
void setup(){
   
 //set pinModes for RGB strip
   pinMode(RED_PIN,OUTPUT);
   pinMode(BLUE_PIN,OUTPUT);
   pinMode(GREEN_PIN,OUTPUT);

   pinMode(TRIGGER_PIN, OUTPUT);
   pinMode(ECHO_PIN, INPUT);
   
   pinMode(ALARM, OUTPUT);
   pinMode(BUTTON, INPUT);
   pinMode(BUTTON2, INPUT);
   
   //reset lights
   analogWrite(RED_PIN,0);
   analogWrite(BLUE_PIN,0);
   analogWrite(RED_PIN,0);
  
  delay(9600);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.  
}

void loop(){
  if(digitalRead(BUTTON) == LOW) {      //Turn Alarm On
    Serial.println("system armed/n");   
    armed = true;
  }
  if(digitalRead(BUTTON2) == LOW) {     //Turn Alarm Off
    Serial.println("system disarmed");
    armed = false;   
    NewTone(ALARM, 0);
    color(0,0,0);
  }
  if (armed) {
    
    if(triggerAmount > 50){
      Serial.println("alarm triggered");
      triggerAmount = 0;
      alarm();
  }
  
    delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    unsigned int distance = uS / US_ROUNDTRIP_CM;
    Serial.println(distance);
  
  if(distance < 100){
    Serial.println("sonar triggered");
    triggerAmount++;
  }
  }
}
 
void alarm(){
   color(255,0,0); //red
   delay(100);
   color(255,255,0); //yelow
   delay(100);
   
   for (int x=0; x<180; x++) {
    // convert degrees to radians then obtain sin value
    sinVal = (sin(x*(3.1412/180)));
    // generate a frequency from the sin value
    toneVal = 2000+(int(sinVal*1000));
    NewTone(ALARM, toneVal);
  }
}
 
//helper function enabling us to send a colour in one command
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{     
    analogWrite(RED_PIN, red);     
    analogWrite(BLUE_PIN, blue);
    analogWrite(GREEN_PIN, green);
}
