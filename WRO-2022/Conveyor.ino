void C1Deposit()
{
  //int movepos = 860;
  int movepos = 860 - (430*C1pallets);
  C1Stepper.moveTo(movepos);
  while (C1Stepper.currentPosition() != movepos)
  {
    C1Stepper.run();
  }
  C1Stepper.setCurrentPosition(0);
}

void C1Jog()
{
  int movepos = 430;
  C1Stepper.moveTo(movepos);
  while (C1Stepper.currentPosition() != movepos)
  {
    C1Stepper.run();
  }
  C1Stepper.setCurrentPosition(0);
}

void C2Deposit()
{
  int movepos = 500;
  C2Stepper.moveTo(movepos);
  while (C2Stepper.currentPosition() != movepos)
  {
    C2Stepper.run();
  }
  C2Stepper.setCurrentPosition(0);
}
