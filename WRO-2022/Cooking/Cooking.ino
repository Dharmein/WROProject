void addWater()
{
  digitalWrite(40,HIGH);
  digitalWrite(41,LOW);
  analogWrite(45,100);
  delay(1000);
  analogWrite(45,0);
}
