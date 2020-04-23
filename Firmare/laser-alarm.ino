/* This code is for a LASER Tripwire Alarm based on a light sensor, LASER module and a push button
 * The LASER is constantly sending beams to the sensor, when someone passes the light is not detected
 * and the alarm goes off, and will not stop until you press the button
 * Refer to www.surtrtech.com for more details
 */
 
#define Rec 0      //Light sensor output
#define Laser 2    //Laser module 
#define Button 3   //Push button input

bool detection;

void setup() {
  pinMode(Laser, OUTPUT);
  digitalWrite(Laser, HIGH); //Turning on the laser
  delay(2000);
}

void loop() {

 short Detect = analogRead(Rec);            //Constanly reading the module value
 bool  Button_state = digitalRead(Button);  //And the button value (1-0)
 
 if(Detect < 500)              //The Max value is 760, if someone passes it goes below that (every value lower than 700 can do the work)
    detection = true;          //The detection is triggered

 if(detection==true)
    {
       tone(13,2000);        //Alarm sequence will go on as long as the detection is true
       delay(50);            //This alarm has two sounds 2kHz nd 1Khz delayed by 50ms
       tone(13,1000);
       delay(50);
    }
 
 if(Button_state == HIGH)  //If the button is pressed the buzzer is turned off and the detection too
    {
      detection = false;
      noTone(13);
    }

  
}
