
#include <Encoder.h>
Encoder myEnc(20, 21);

//------------Stepper Library -----------------
#include <AccelStepper.h>
const int dirPinH = 5;
const int stepPinH = 2;

const int dirPinV = 6;
const int stepPinV = 3;

const int dirPinC1 = 7;
const int stepPinC1 = 4;
const int C1Sens = 22;

const int dirPinC2 = 13;
const int stepPinC2 = 12;

#define motorInterfaceType 1

AccelStepper VStepper(motorInterfaceType, stepPinV, dirPinV);
AccelStepper HStepper(motorInterfaceType, stepPinH, dirPinH);
AccelStepper C1Stepper(motorInterfaceType, stepPinC1, dirPinC1);
AccelStepper C2Stepper(motorInterfaceType, stepPinC2, dirPinC2);

//-----------------------------

const int ppa = 42;
const int ppb = 43;
const int pppwm = 44 ;

const int scannerPin = 23;

long oldPosition  = -999;
long newPosition;

long vPos;
long hPos;

int X = 0;
int Y = 0;

String inString;
String outString;
String id;
String dropLocStr;
String message;

int dropLoc, dropLocX, dropLocY;
int ind1, ind2;

String scannedCode;
String opCode;
int C1pallets = 0;
int location;
int location1 = 10;
int location2 = 15;

char BT = ' ';

void setup() {

  Serial.begin(9600);
  BT = Serial1.read();


  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);

  //---------Pick n Place------
  pinMode(ppa, OUTPUT);
  pinMode(ppb, OUTPUT);
  pinMode(pppwm, OUTPUT);
  //----------------------------

  //---------stepper settings
  VStepper.setMaxSpeed(1000);
  VStepper.setAcceleration(500);
  VStepper.setSpeed(1000);

  HStepper.setMaxSpeed(2000);
  HStepper.setAcceleration(1000);
  HStepper.setSpeed(2000);

  C1Stepper.setMaxSpeed(1000);
  C1Stepper.setAcceleration(1000);
  C1Stepper.setSpeed(1000);

  C2Stepper.setMaxSpeed(1000);
  C2Stepper.setAcceleration(1000);
  C2Stepper.setSpeed(1000);
  //---------------------------
  pinMode(31, OUTPUT);
  pinMode(scannerPin, OUTPUT);
  digitalWrite(scannerPin, HIGH);
  pinMode(41, OUTPUT);
  digitalWrite(41, HIGH);
pinMode(50, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(51, OUTPUT);
  delay(1000);

}

void loop() {

  BT = Serial1.read();

   if (( BT == 'O' )) {Serial.print("O ");
  Serial.println();
  digitalWrite(51,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,LOW);
  delay(10000);
  
  digitalWrite(50,HIGH);
  digitalWrite(52,HIGH);
  

   }
     if (( BT == 'F' )) {Serial.print("F ");
  Serial.println();
  digitalWrite(51,LOW);

  

   }
  if (( BT == 'A' )) {Serial.print("A ");
  Serial.println();
   digitalWrite(51,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,LOW);
  delay(30000);
  
  digitalWrite(50,LOW);
  digitalWrite(52,LOW);

  gotoPos(1, 0);
  pick();
  gotoEnd();
  dropItem();
  gotoPos(1, 0);
  place();
  gotoHome();
  delay(10000);
  gototouch();
   gotoHome();
  }

  if (( BT == 'B' )) {Serial.print("B ");
   digitalWrite(51,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,LOW);
  delay(30000);
  
  digitalWrite(50,LOW);
  digitalWrite(52,LOW);
  
  gotoPos(1, 1);
  pick();
  gotoEnd();
  dropItem();
  gotoPos(1, 1);
  place();
  gotoHome();
  delay (1000);
  gotoPos(2, 1);
  pick();
  gotoEnd();
  dropItem();
  gotoPos(2,1);
  place();
  gotoHome();
  delay(60000);
  gototouch();
   gotoHome();
  }

  if (( BT == 'C' )) {Serial.print(" C");
   digitalWrite(51,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,LOW);
  delay(15000);
  
  digitalWrite(50,LOW);
  digitalWrite(52,LOW);

   gotoPos(2, 0);
  pick();
  gotoEnd();
  dropItem();
  gotoPos(2,0 );
  place();
  gotoHome();
  delay(10000);
  gototouch();
   gotoHome();
  }

  if (( BT == 'D' )) {Serial.print("D ");
   digitalWrite(51,HIGH);
  digitalWrite(50,HIGH);
  digitalWrite(52,LOW);
  delay(3000);
  
  digitalWrite(50,LOW);
  digitalWrite(52,LOW);

  gotoPos(2, 1);
  pick();
  gotoEnd();
  dropItem();
  gotoPos(2, 1);
  place();
  gotoHome();
 delay(10000);
 gototouch();
  gotoHome();
  }
}
