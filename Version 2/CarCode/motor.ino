void configureMotor(){
  pinMode (mtr1N, OUTPUT);
  pinMode (mtr1P, OUTPUT);
  pinMode (mtr2N, OUTPUT);
  pinMode (mtr2P, OUTPUT);
  pinMode (mtr3N, OUTPUT);
  pinMode (mtr3P, OUTPUT);
  pinMode (mtr4N, OUTPUT);
  pinMode (mtr4P, OUTPUT);

  if(enTrainingWheel){
    analogWrite (mtr1N, 0);
    analogWrite (mtr1P, 0);
    analogWrite (mtr2N, 0);
    analogWrite (mtr2P, 0);
    analogWrite (mtr3N, 0);
    analogWrite (mtr3P, 0);
    analogWrite (mtr4N, 0);
    analogWrite (mtr4P, 0);
  }
}

void drive(int m1, int m2, int m3, int m4){
  motorControl(m1, m2, m3, m4); 
}

void motorControl(int m1, int m2, int m3, int m4){
  if (enTrainingWheel){
    if (m1 >= 0){
      analogWrite (mtr1N, m1);
      analogWrite (mtr1P, 0);
    }
    else{
      analogWrite (mtr1N, 0);
      analogWrite (mtr1P, -m1);
    }
    if (m4 >= 0){
      analogWrite (mtr4N, m4);
      analogWrite (mtr4P, 0);
    }
    else{
      analogWrite (mtr4N, 0);
      analogWrite (mtr4P, -m4);
    }
  }
  
  if (m2 >= 0){
    analogWrite (mtr2N, m2);
    analogWrite (mtr2P, 0);
  }
  else{
    analogWrite (mtr2N, 0);
    analogWrite (mtr2P, -m2);
  }

  if (m3 >= 0){
    analogWrite (mtr3N, m3);
    analogWrite (mtr3P, 0);
  }
  else{
    analogWrite (mtr3N, 0);
    analogWrite (mtr3P, -m3);
  }
}
