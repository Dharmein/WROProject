int ppdistance = 2300;
void pick()
{
  newPosition = myEnc.read();

  while (newPosition < ppdistance - 1)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, HIGH);
    digitalWrite(ppb, LOW);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);

  newPosition = myEnc.read();

  vPos = VStepper.currentPosition();
  VStepper.moveTo(vPos + 120);

  while (VStepper.currentPosition() != vPos + 120)
  {
    VStepper.run();
  }

  while (newPosition > 30)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, LOW);
    digitalWrite(ppb, HIGH);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);
  newPosition = myEnc.read();

}

void place()
{
  vPos = VStepper.currentPosition();
  VStepper.moveTo(vPos + 100);

  while (VStepper.currentPosition() != vPos + 100)
  {
    VStepper.run();
  }
  
  newPosition = myEnc.read();
  while (newPosition < ppdistance - 1)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, HIGH);
    digitalWrite(ppb, LOW);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);

  newPosition = myEnc.read();

  vPos = VStepper.currentPosition();
  VStepper.moveTo(vPos - 100);

  while (VStepper.currentPosition() != vPos - 100)
  {
    VStepper.run();
  }

  while (newPosition > 30)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, LOW);
    digitalWrite(ppb, HIGH);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);
  newPosition = myEnc.read();
}
void dropItem()
{

  newPosition = myEnc.read();
  while (newPosition < ppdistance - 1)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, HIGH);
    digitalWrite(ppb, LOW);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);
  digitalWrite(31, HIGH);
  delay(1000);
  digitalWrite(31, LOW);
  delay(2000);
  newPosition = myEnc.read();

  while (newPosition > 30)
  {
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;
    }
    digitalWrite(ppa, LOW);
    digitalWrite(ppb, HIGH);
    analogWrite(pppwm, 200);
  }
  analogWrite(pppwm, 0);
  delay(100);
  newPosition = myEnc.read();
}
