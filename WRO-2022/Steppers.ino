void gotoC1()
{
  HStepper.moveTo(350);
  VStepper.moveTo(-100);
  while (VStepper.currentPosition() != -100 || HStepper.currentPosition() != 350)
  {
    HStepper.run();
    VStepper.run();
  }
}

void gotoC2()
{
  HStepper.moveTo(4000);
  VStepper.moveTo(-150);
  while (VStepper.currentPosition() != -150 || HStepper.currentPosition() != 4000)
  {
    HStepper.run();
    VStepper.run();
  }
}

void gotostandby()
{
  HStepper.moveTo(900);
  VStepper.moveTo(-200);
  while (VStepper.currentPosition() != -200 || HStepper.currentPosition() != 900)
  {
    HStepper.run();
    VStepper.run();
  }
}

void gotoHome()
{
  HStepper.moveTo(0);
  VStepper.moveTo(0);
  while (VStepper.currentPosition() != 0 || HStepper.currentPosition() != 0)
  {
    HStepper.run();
    VStepper.run();
  }
}


int cellV = 600;
int cellH = 500;

void gotoPos(int X, int Y)
{
  VStepper.moveTo(cellV + (Y * 650));
  HStepper.moveTo(cellH + (X * 520));
  while (VStepper.currentPosition() != cellV + (Y * 650) || HStepper.currentPosition() != cellH + (X * 520))
  {
    HStepper.run();
    VStepper.run();
  }
}

void gotoPosPick(int X, int Y)
{
  VStepper.moveTo(cellV + 90 + (Y * 660));
  HStepper.moveTo(cellH - (X * 500));
  while (VStepper.currentPosition() != cellV + 90 + (Y * 660) || HStepper.currentPosition() != cellH - (X * 500))
  {
    HStepper.run();
    VStepper.run();
  }
}


void gotoDemo()
{
  VStepper.moveTo(-400);
  HStepper.moveTo(1000);
  while (VStepper.currentPosition() != -400 || HStepper.currentPosition() != 1000)
  {
    HStepper.run();
    VStepper.run();
  }
}

void gotoEnd()
{
  VStepper.moveTo(1000);
  HStepper.moveTo(2900);
  while (VStepper.currentPosition() != 1000 || HStepper.currentPosition() != 2900)
  {
    HStepper.run();
    VStepper.run();
  }
}
void gototouch()
{
  //VStepper.moveTo(1000);
  HStepper.moveTo(3550);
  while ( HStepper.currentPosition() != 3550)
  {
    HStepper.run();
   // VStepper.run();
  }
}
