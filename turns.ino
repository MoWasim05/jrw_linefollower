void straight() {
  digitalWrite(lFwd, HIGH);
  digitalWrite(rFwd, HIGH);
  
  // PWM range is 0-1023
  analogWrite(PWMa, 150 - adjustSpeed); 
  analogWrite(PWMb, 150);
}

void stop() {
  digitalWrite(lFwd, LOW);
  digitalWrite(rFwd, LOW);
  
  analogWrite(PWMa, 0);
  analogWrite(PWMb, 0);
}

void turnRight() {
  digitalWrite(lFwd, HIGH);
  digitalWrite(rFwd, LOW);
  
  analogWrite(PWMa, 600);
  analogWrite(PWMb, 0);
}