void attachServos(){
  robotBase.attach(22, 10, 180);
  robotShoulder.attach(24);
  robotElbow.attach(26, 110, 180);
  robotClaw.attach(28, minClaw, maxClaw);
}

void detachServos(){
  robotBase.detach();
  robotShoulder.detach();
  robotElbow.detach();
  robotClaw.detach();
}

void homeServos(){
  tElbow = 165;
  tShoulder = 30;
  tBase = 90;
  pElbow = 0;
  pShoulder = 0;
  pBase = 0;
  rSpeed = 20;
}

void openClaw (double percent){
  if(percent > 1) percent = 1;
  else if (percent < 0) percent = 0;
  robotClaw.write(minClaw + ((maxClaw - minClaw)*percent));
}

void closeClaw (double percent){
  if(percent > 1) percent = 1;
  else if (percent < 0) percent = 0;
  robotClaw.write(maxClaw - ((maxClaw - minClaw)*percent));
}

void moveRobot (){
  
  // MOVE ELBOW
  if ((tElbow+rDeadband < pElbow) or (tElbow-rDeadband > pElbow)){
    double tempMove = tElbow - pElbow;
    tempMove = tempMove * rSpeed / 100;
    if((tempMove * tempMove)<1){
      if (tempMove > 0) tempMove = 1;
      else tempMove = -1;
    }
    pElbow += tempMove;
    robotElbow.write(pElbow);
  }

  // MOVE SHOULDER
  if ((tShoulder+rDeadband < pShoulder) or (tShoulder-rDeadband > pShoulder)){
    double tempMove = tShoulder - pShoulder;
    tempMove = tempMove * rSpeed / 100;
    if((tempMove * tempMove)<1){
      if (tempMove > 0) tempMove = 1;
      else tempMove = -1;
    }
    pShoulder += tempMove;
    robotShoulder.write(pShoulder);
  }

  // MOVE BASE
  if ((tBase+rDeadband < pBase) or (tBase-rDeadband > pBase)){
    double tempMove = tBase - pBase;
    tempMove = tempMove * rSpeed / 100;
    if((tempMove * tempMove)<1){
      if (tempMove > 0) tempMove = 1;
      else tempMove = -1;
    }
    pBase += tempMove;
    robotBase.write(pBase);
    Serial.println(int(pBase)); 
  }
} 
