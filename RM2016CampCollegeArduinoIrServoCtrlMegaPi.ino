#include "MeMegaPi.h"
#include <SoftwareSerial.h>

#define CLAW1_OPEN_ANGLE  0
#define CLAW1_CLOSE_ANGLE 90
#define CLAW2_OPEN_ANGLE  180
#define CLAW2_CLOSE_ANGLE 90

#define OPEN_CLAW  0xaa
#define CLOSE_CLAW 0xbb
#define CLAW1_MINUS_MINUS 0x10
#define CLAW1_PLUS_PLUS 0x11
#define CLAW2_MINUS_MINUS 0x20
#define CLAW2_PLUS_PLUS 0x21

/***********************************/
/*          舵机控制接口           */
/***********************************/
MePort port(PORT_8);

int port1 = port.pin1();
int port2 = port.pin2();

Servo servo1;
Servo servo2;

int claw1_angle = 0;
int claw2_angle = 0;

void OpenClaw(void)
{
  claw1_angle = CLAW1_OPEN_ANGLE;
  claw2_angle = CLAW2_OPEN_ANGLE;
}

void CloseClaw(void)
{
  claw1_angle = CLAW1_CLOSE_ANGLE;
  claw2_angle = CLAW2_CLOSE_ANGLE;
}

void LimitClaw1(void)
{
  //if(claw1_angle > 
}

void LimitClaw2(void)
{
  
}

void Claw1MinusMinus(void)
{
  claw1_angle--;
}

void Claw1PlusPlus(void)
{
  claw1_angle++;
}

void Claw2MinusMinus(void)
{
  claw2_angle--;
}

void Claw2PlusPlus(void)
{
  claw2_angle++;
}

void Action(void)
{
  servo1.write(claw1_angle);
  servo2.write(claw2_angle);
}

void process(uint8_t data)
{
  switch(data)
    {
       case OPEN_CLAW: 
       {
        OpenClaw();
        Action();
       }break;
       case CLOSE_CLAW: 
       {
        CloseClaw();
        Action();
       }break;
       case CLAW1_MINUS_MINUS:
       {
        //Claw1MinusMinus();
       }break;
       case CLAW1_PLUS_PLUS:
       {
        //Claw1PlusPlus();
       }break;
       case CLAW2_MINUS_MINUS:
       {
        //Claw2MinusMinus();
       }break;
       case CLAW2_PLUS_PLUS:
       {
        //Claw2PlusPlus();
       }break;
       default: break;
    }
}

void PrintCurrentAngle(void)
{
  Serial.print("claw1_angle=");
  Serial.print(claw1_angle);
  Serial.print(".claw2_angle=");
  Serial.println(claw2_angle);
}
void setup() 
{
  Serial.begin(115200);    //配置PC串口波特率
  Serial3.begin(115200);
  servo1.attach(port1);
  servo2.attach(port2);
  Serial.println("setup done!");
}

void loop() 
{
  int data = 0;
  if(Serial3.available())
  {
    data = Serial3.read();
    Serial.println(data);
    process(data);
    PrintCurrentAngle();
  }
}
