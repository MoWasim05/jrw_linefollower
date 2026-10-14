void PIDControl(int baseSpeed, float kp, float kd) {

  if (debugMode == true) {
    Serial.print(sensorSum);
    Serial.print("\t");
    Serial.print(sensorWeight);
    Serial.print("\t");
    Serial.print(sensorBit);
    Serial.print("\t");
  }

  // Calculate where the line is
  if (sensorSum > 0) {
    linePosition = (float)sensorWeight / sensorSum;
  }

  // Calculate error and rate of change
  error = linePosition - centerPosition;
  derivative = error - previousError;

  // Apply motor difference parity
  int leftBase = baseSpeed - adjustSpeed;

  // Calculate new motor speeds
  int lMotor = leftBase + (error * kp + derivative * kd);
  int rMotor = baseSpeed - (error * kp + derivative * kd);

  previousError = error;

  if (debugMode == true) {
    // Updated for 3 sensors (Index 2 down to 0)
    for (int i = 2; i >= 0; i--) {
      Serial.print(irValDigital[i]);
    }

    Serial.print("\t");
    Serial.print("Weight: " + String(sensorWeight));
    Serial.print("\t");
    Serial.print("Error : " + String(error));
    Serial.println(); 
  }

  motor(lMotor, rMotor); 
}