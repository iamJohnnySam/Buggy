void goBack(){
  analogWrite(M1p, fSpeed);
  analogWrite(M1p, 0);
  analogWrite(M2p, fSpeed);
  analogWrite(M2n, 0);
  analogWrite(M3p, 0);
  analogWrite(M3n, fSpeed);
  analogWrite(M4p, 0);
  analogWrite(M4n, fSpeed);
}

void goStraight(){
  analogWrite(M1p, 0);
  analogWrite(M1n, fSpeed);
  analogWrite(M2p, 0);
  analogWrite(M2n, fSpeed);
  analogWrite(M3p, fSpeed);
  analogWrite(M3n, 0);
  analogWrite(M4p, fSpeed);
  analogWrite(M4n, 0);
}

void goLeft() {
  analogWrite(M1p, 0);
  analogWrite(M1n, fSpeed);
  analogWrite(M2p, 0);
  analogWrite(M2n, fSpeed);
  analogWrite(M3p, 0);
  analogWrite(M3n, fSpeed);
  analogWrite(M4p, 0);
  analogWrite(M4n, fSpeed);
}

void goRight(){
  analogWrite(M1p, fSpeed);
  analogWrite(M1n, 0);
  analogWrite(M2p, fSpeed);
  analogWrite(M2n, 0);
  analogWrite(M3p, fSpeed);
  analogWrite(M3n, 0);
  analogWrite(M4p, fSpeed);
  analogWrite(M4n, 0);
}

void goStop(){
  analogWrite(M1p, 0);
  analogWrite(M1n, 0);
  analogWrite(M2p, 0);
  analogWrite(M2n, 0);
  analogWrite(M3p, 0);
  analogWrite(M3n, 0);
  analogWrite(M4p, 0);
  analogWrite(M4n, 0);
}
