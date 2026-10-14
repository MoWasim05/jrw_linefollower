void readLine(){
  sensorSum = 0;
  sensorWeight = 0;
  sensorBit = 0;

  for (int i = 0; i < 3; i++) {
    // digital read
    irValDigital[i] = digitalRead(irPins[i]); 
    
    sensorSum += irValDigital[i];
    sensorWeight += irValDigital[i] * weightVal[i];
    sensorBit += irValDigital[i] * bitWeight[i];
  }
}