void configureLCD (){ 
  pinMode(31, OUTPUT);
  digitalWrite(31, LOW); 
  LCD.begin();
  LCD.setContrast(60);
  LCD.clearDisplay();

  LCD.setTextSize(1);
  LCD.setTextColor(BLACK);
  LCD.setCursor(0,0);
  LCD.println(" iamJohnnySam");
  LCD.display();

  LCD.setTextSize(1);
  LCD.setTextColor(BLACK);
  LCD.setCursor(0,10);
  LCD.println("Buggy");
  LCD.display();
}
