#include<Wire.h>
//Declaring all the variables

float pi = 3.14159;
float a1 = 0;
float a2 = 39;
float a3 = 0;
float a4 = 39;
int relay[4][4] = {{23, 25, 27, 29}, {31, 33, 35, 37}, {39, 41, 43, 45}, {47, 49, 51, 53}};
float T[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
bool flag[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
//*****************************************************************************************************************************//
//Class for leg

class Leg
{
    int leg;  //private variable for leg number
    float X;
    float Y;
  public:
    Leg(int _leg)
    {
      leg = _leg; //declare public variable
    }
    //*************************//
    //gotopos takes X and Y and Goes to that position

    void gotopos(float _X, float _Y)
    {
      Serial.println("In gotopos");
      X = _X;
      Y = _Y;
      flag[0][leg] = 1;
      flag[1][leg] = 1;
    }
    //*************************//
    //choose function

    void choose_fn()
    {
      Serial.println("In choose_fn");
      if (X < 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          calculate_neg_angle(X, Y);
        }
      }
      else
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          calculate_pos_angle(X, Y);
        }
      }
    }

    //*************************//
    //calculates angle for positive X

    void calculate_pos_angle(float X, float Y)
    {
      Serial.println("In calcpos");
      float r1 = 0;
      float phi1 = 0;
      float phi2 = 0;
      float phi3 = 0;
      r1 = sqrt(X * X + Y * Y);
      phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2.0 * a2 * r1));
      phi2 = atan(Y / X);
      T[0][leg] = phi2 - phi1;
      phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2.0 * a2 * a4));
      T[1][leg] = pi - phi3;
      T[0][leg] = T[0][leg] * 180 / pi;
      T[1][leg] = T[1][leg] * 180 / pi;
      onoffcontrol();
    }
    //*************************//
    //calculates angle for niggative X

    void calculate_neg_angle(float X, float Y)
    {
      Serial.println("In calcneg");
      float r1 = 0;
      float phi1 = 0;
      float phi2 = 0;
      float phi3 = 0;
      X = abs(X);
      r1 = sqrt(X * X + Y * Y);
      phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2.0 * a2 * r1));
      phi2 = atan(-Y / X);
      phi2 = pi + phi2;
      T[0][leg] = phi2 - phi1;
      phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2.0 * a2 * a4));
      T[1][leg] = pi - phi3;
      T[0][leg] = T[0][leg] * 180 / pi;
      T[1][leg] = T[1][leg] * 180 / pi;
      onoffcontrol();
    }
    //*************************//
    //control logic for motion

    void onoffcontrol()
    {
      //Read the feedback pot
      float fb1 = 0;
      float fb2 = 0;
      float error1 = 0;
      float error2 = 0;

      fb1 = analogRead(A0);
      fb2 = analogRead(A1);

      //Map pot1 to required range
      if (917 < fb1 && fb1 < 953)
        fb1 = map(fb1, 917, 953, 45, 10);
      else if (873 < fb1 && fb1 < 917)
        fb1 = map(fb1, 873, 917, 90, 45);
      else if (831 < fb1 && fb1 < 873)
        fb1 = map(fb1, 831, 873, 115, 90);
      else
        fb1 = map(fb1, 831, 953, 115, 10);  //953,917,873,831

      //Map pot2 to required range
      if (278 < fb2 && fb2 < 465)
        fb2 = map(fb2, 278, 465, 10, 45);
      else if (465 < fb2 && fb2 < 863)
        fb2 = map(fb2, 465, 863, 45, 90);
      else if (863 < fb2 && fb2 < 892)
        fb2 = map(fb2, 863, 892, 90, 135);
      else if (892 < fb2 && fb2 < 916)
        fb2 = map(fb2, 892, 916, 135, 165);
      else
        fb2 = map(fb2, 916, 278, 165, 10);  //278,465,863,892,916

      //Print statements for debugging
      Serial.print(leg);
      Serial.print("  ");
      Serial.print("  fb1  ");
      Serial.print(fb1);
      Serial.print("  T[0][leg]  ");
      Serial.print(T[0][leg]);
      Serial.print("  fb2  ");
      Serial.print(fb2);
      Serial.print("  T[1][leg]  ");
      Serial.println(T[1][leg]);

      //Find error
      error1 = T[0][leg] - fb1;
      error2 = T[1][leg] - fb2;

      //Control statements for feedback based motion
      if (abs(error1) < 2)
      {
        hardstop(relay[leg][0], relay[leg][1]);
        flag[0][leg] = 0;
      }
      if (abs(error2) < 2)
      {
        hardstop(relay[leg][2], relay[leg][3]);
        flag[1][leg] = 0;
      }

      if (fb1 < T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
          forward(relay[leg][0], relay[leg][1]);
        if (flag[1][leg] == 1)
          forward(relay[leg][2], relay[leg][3]);
      }
      else if (fb1 < T[0][leg] && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
          forward(relay[leg][0], relay[leg][1]);
        if (flag[1][leg] == 1)
          backward(relay[leg][2], relay[leg][3]);
      }
      else if (fb1 > T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
          backward(relay[leg][0], relay[leg][1]);
        if (flag[1][leg] == 1)
          forward(relay[leg][2], relay[leg][3]);
      }
      else if (fb1 > T[0][leg]  && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
          backward(relay[leg][0], relay[leg][1]);
        if (flag[1][leg] == 1)
          backward(relay[leg][2], relay[leg][3]);
      }
    }
    //*************************//
    //back forward and stop functions

    void backward(int l1, int l2)
    {
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
    }

    void forward(int l1, int l2)
    {
      digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
    }

    void hardstop(int l1, int l2)
    {
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
    }
    //*************************//
};
//*****************************************************************************************************************************//

Leg leg1 = Leg(0);
Leg leg2 = Leg(1);
Leg leg3 = Leg(2);
Leg leg4 = Leg(3);


//Setup function to setup baud rate pinModes

void setup()
{
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  //  Serial.flush();
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(1000);

  Serial.println("start");

  noInterrupts();
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  interrupts();
  //  leg1.gotopos(-20, 60);
  //  leg2.gotopos(-20, 60);
  //  leg3.gotopos(-20, 60);
  //  leg4.gotopos(-20, 60);

}
//*************************//
//ISR

SIGNAL(TIMER0_COMPA_vect)
{
  if (digitalRead(2) == HIGH)
  {
    Serial.println("In ISR");
    leg1.choose_fn();
    leg2.choose_fn();
    leg3.choose_fn();
    leg4.choose_fn();
  }
}
//*************************//
//loop function

void loop()
{

}
//*************************//
//on receive

void receiveEvent(int howMany) {
  Serial.println("In onReceive");
  float v1, v2, v3, v4, v5, v6, v7, v8;
  float x_ = Wire.read();    // receive byte as an integer
  String x = (String)x_;

  int commaIndex = x.indexOf(',');
  int secondCommaIndex = x.indexOf(',', commaIndex + 1);
  int thirdCommaIndex = x.indexOf(',', secondCommaIndex + 1);
  int fourthCommaIndex = x.indexOf(',', thirdCommaIndex + 1);
  int fifthCommaIndex = x.indexOf(',', fourthCommaIndex + 1);
  int sixthCommaIndex = x.indexOf(',', fifthCommaIndex + 1);
  int seventhCommaIndex = x.indexOf(',', sixthCommaIndex + 1);
  int eighthCommaIndex = x.indexOf(',', seventhCommaIndex + 1);

  String firstValue = x.substring(0, commaIndex);
  String secondValue = x.substring(commaIndex + 1, secondCommaIndex);
  String thirdValue = x.substring(secondCommaIndex + 1, thirdCommaIndex);
  String fourthValue = x.substring(thirdCommaIndex + 1, fourthCommaIndex);
  String fifthValue = x.substring(fifthCommaIndex + 1, sixthCommaIndex);
  String sixthValue = x.substring(sixthCommaIndex + 1, seventhCommaIndex);
  String seventhValue = x.substring(seventhCommaIndex + 1, eighthCommaIndex);
  String eighthValue = x.substring(eighthCommaIndex + 1);

  v1 = firstValue.toFloat();
  v2 = secondValue.toFloat();
  v3 = thirdValue.toFloat();
  v4 = fourthValue.toFloat();
  v5 = fifthValue.toFloat();
  v6 = sixthValue.toFloat();
  v7 = seventhValue.toFloat();
  v8 = eighthValue.toFloat();
  Serial.print(v1);
  Serial.print(v2);
  Serial.print(v3);
  Serial.print(v4);
  Serial.print(v5);
  Serial.print(v6);
  Serial.print(v7);
  Serial.println(v8);
  
  leg1.gotopos(v1, v2);
  leg2.gotopos(v3, v4);
  leg3.gotopos(v5, v6);
  leg4.gotopos(v7, v8);
}
