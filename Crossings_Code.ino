//When the green crosswalk light is on, pedestrians can safely begin crossing the road.
//When the red crosswalk light is flashing, pedestrians must not begin crossing; Pedestrians already crossing must continue to cross.
//When the red crosswalk light is solid, pedestrians must not begin crossing.

//Setting all LEDs as outputs.
void setup() {
  for (int pinLEDs = 4; pinLEDs < 14; pinLEDs ++) {
    pinMode(pinLEDs, OUTPUT);
  }
}


void loop() {
  // All red crosswalk lights are activated along with east/west red traffic lights.
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(13, HIGH);
   
  // North/south advanced (flashing) green traffic lights activate for 10 seconds.
  // NOTE: When there are solid red and advanced (flashing) green traffic lights active in the same traffic light trio, ONLY left turns are allowed. Traffic moving straight or turning right must stop because traffic turning left has the right of way.
  digitalWrite(10, HIGH);
  for(int i=0; i<10; i++){
  	digitalWrite(8, HIGH);
  	delay(500);
  	digitalWrite(8, LOW);
  	delay(500);
  }
  digitalWrite(10, LOW);
  
  // North/south solid green traffic lights activate for 17 seconds. The north/south solid green crosswalk lights activate for 5 seconds.
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(4, HIGH);
  delay(5000);
  digitalWrite(4, LOW);
  
  //The north/south solid green crosswalk lights deactivate and the north/south red crosswalk lights begin flashing for 12 seconds.
  for(int i=0; i<12; i++){
  	digitalWrite(5, HIGH);
  	delay(500);
  	digitalWrite(5, LOW);
  	delay(500);
  }
  //The flashing red crosswalk lights become solid.
  digitalWrite(5, HIGH);
  
  //The north/south solid yellow traffic lights activate for 5 seconds. After the 5 seconds, the yellow traffic lights are disabled and the north/south solid red traffic lights are enabled.
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  
  //There is an extra 2 second delay to briefly stop all traffic in order to ensure that drivers who are still in the middle turning left have a chance to go.
  delay(2000);
  
  //When the north/south solid red traffic lights and solid red crosswalk lights are enabled at the SAME time, the east/west solid red and advanced (flashing) green traffic lights activate for 10 seconds.
  if(digitalRead(5) == HIGH && digitalRead(10) == HIGH){
    
   digitalWrite(13, HIGH);
   for(int i=0; i<10; i++){
  	digitalWrite(11, HIGH);
  	delay(500);
  	digitalWrite(11, LOW);
   	delay(500);
   }
   digitalWrite(13, LOW);
    
   //The east/west solid green traffic lights activate for 17 seconds. The east/west solid green crosswalk lights are enabled for 5 seconds and then disabled.
   digitalWrite(7, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(6, HIGH);
   delay(5000);
   digitalWrite(6, LOW);
   
   //The east/west red crosswalk lights begin flashing for 12 seconds.
   for(int i=0; i<12; i++){
   	digitalWrite(7, HIGH);
   	delay(500);
  	digitalWrite(7, LOW);
  	delay(500);
   }
   
   //The east/west flashing red crosswalk lights become solid.
   digitalWrite(7, HIGH);
    
   //The east/west solid yellow traffic lights activate for 5 seconds. After the 5 seconds, the yellow traffic lights are disabled and the east/west solid red traffic lights are enabled.
   digitalWrite(11, LOW);
   digitalWrite(12, HIGH);
   delay(5000);
   digitalWrite(12, LOW);
   digitalWrite(13, HIGH);
   
   //There is an extra 2 second delay to briefly stop all traffic in order to ensure that drivers who are still in the middle turning left have a chance to go.
   delay(2000); 
  }
}
