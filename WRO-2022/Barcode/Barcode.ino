void scanItem()
{
  //delay(1000);
  digitalWrite(scannerPin, LOW);
  while (Serial1.available() == 0) {}
  scannedCode = Serial1.readString();
  digitalWrite(scannerPin, HIGH);
  scannedCode.trim();
  //Serial.println(scannedCode);
}
