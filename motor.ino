void motor(int lPWM, int rPWM) {
  // Constrain to the ESP8266 maximum PWM limit
  lPWM = constrain(lPWM, -1023, 1023);
  rPWM = constrain(rPWM, -1023, 1023); 

  // Left Motor
  if (lPWM > 0) {
    digitalWrite(lFwd, HIGH); 
    analogWrite(PWMa, lPWM);
  } else {
    // Cannot reverse without lRev pin, so we brake
    digitalWrite(lFwd, LOW); 
    analogWrite(PWMa, 0);
  }

  // Right Motor
  if (rPWM > 0) {
    digitalWrite(rFwd, HIGH); 
    analogWrite(PWMb, rPWM);
  } else {
    digitalWrite(rFwd, LOW); 
    analogWrite(PWMb, 0); 
  }
}