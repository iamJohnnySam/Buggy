void debuggingMode(){
  int temp = 0;
  switch(readSerialChar()){
    case 0: break;
    case 'a': enTrainingWheel = !enTrainingWheel; Serial.println("Toggled Training Wheels"); break;
    case 'b': enRobot = !enRobot; Serial.println("Toggled Robot"); break;
    case 'e':
      Serial.print("Forward Speed Updated to: ");
      temp = readSerialInt();
      if ((temp >= 0) and (temp < 256)){
        Serial.println(temp);
        forwardSpeed = temp;
      }
      else{
        Serial.println("Invalid Input");
      }
      break;
      
    case 'p':
      Serial.print("Robot Base will move to: ");
      temp = readSerialInt();
      if ((temp >= 0) and (temp <= 180)){
        Serial.println(temp);
        tBase = temp;
      }
      break;

    case 'q':
      Serial.print("Robot Shoulder will move to: ");
      temp = readSerialInt();
      if ((temp >= 0) and (temp <= 180)){
        Serial.println(temp);
        tShoulder = temp;
      }
      break;

    case 'r':
      Serial.print("Robot Elbow will move to: ");
      temp = readSerialInt();
      if ((temp >= 0) and (temp <= 180)){
        Serial.println(temp);
        tElbow = temp;
      }
      break;

    case 's':
      Serial.print("Robot Speed updated to: ");
      temp = readSerialInt();
      if ((temp >= 0) and (temp <= 500)){
        Serial.println(temp);
        rSpeed = temp;
      }
      break;
    
    case 'x':
      Serial.println("----- Serial Input Menu : -----\n");
      Serial.println("a :\t enable/disable training wheels");
      Serial.println("b :\t enable/disable robot");

      Serial.println("e :\t update forward speed");

      Serial.println("p :\t move robot base");
      Serial.println("q :\t move robot shoulder");
      Serial.println("r :\t move robot elbow");
      Serial.println("s :\t update robot speed");
      
      Serial.println("x :\t print menu");
      Serial.println("z :\t kill car");
      Serial.println("");
      break;
      
    case 'z': while(1); break;
    default: Serial.println("Invalid Input"); break;
  }
}

char readSerialChar(){
  char serialOut = 0;
  if (Serial.available() > 0){
    serialOut = Serial.read();
  }
  flushSerial();
  return serialOut;
}

String readSerialString(){
  flushSerial();
  String serialOut;
  while(Serial.available()) {
    serialOut = Serial.readString();
  }
  flushSerial();
  return serialOut; 
}

int readSerialInt(){
  while (Serial.available()==0);
  int temp1 = (int(Serial.read()) - 48)*100;
  while (Serial.available()==0);
  int temp2 = (int(Serial.read()) - 48)*10;
  while (Serial.available()==0);
  int temp3 = int(Serial.read()) - 48;
    
  flushSerial();
  return (temp1 + temp2 + temp3);
}

void flushSerial (){
  while (Serial.available() > 0){
    int temp = Serial.read();
  }
}
