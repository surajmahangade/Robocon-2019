//Include all libraries
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "MegunoLink.h"
#include "SimpleKalmanFilter.h"
volatile int a = 0;
/**********************************************/
//MPU6050 accelgyro; // <--use for AD0 floating
MPU6050 accelgyro(0x69); // <-- use for AD0 high
int e_mea = 1;
float angle;
int e_est = 1;
int q = 10 ;
SimpleKalmanFilter kfx = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx1 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy1 = SimpleKalmanFilter(e_mea, e_est, q);
//e_mea: Measurement Uncertainty - How much do we expect to our measurement vary
//e_est: Estimation Uncertainty - Can be initilized with the same value as e_mea since the kalman filter will adjust its value.
//q: Process Variance - usually a small number between 0.001 and 1 - how fast your measurement moves. Recommended 0.01. Should be tunned to your needs.
//                                                               ^
/**********************************************/
//Declare constants for mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Declaring all the variables

float pi = 3.14159;
float a1 = 0;
float a2 = 39;
float a3 = 0;
float a4 = 39;
int relay[4][4] = {{4, 5, 6, 7}, {31, 33, 35, 37}, {39, 41, 43, 45}, {47, 49, 51, 53}};//{{23, 25, 27, 29}, {31, 33, 35, 37}, {39, 41, 43, 45}, {47, 49, 51, 53}};
float T[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
volatile int flag[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
volatile int neg_flag[4] = {0, 0, 0, 0};
volatile int pos_flag[4] = {0, 0, 0, 0};
volatile float points[7][2] = {{0, 0}, { -14.3 , 6.6}, { -10.5, 14.7}, { -20, 20}, { -30.5, 14.7}, { -24.3, 6.6}, { -40, 0}};
volatile int pointer = 0;
/*****************************************************************************************************************************/
//Class for leg

class Leg
{
    volatile int leg;  //private variable for leg number
    volatile float X;
    volatile float Y;
  public:
    Leg(int _leg)
    {
      leg = _leg; //declare public variable
    }
    //*************************//
    //gotopos takes X and Y and Goes to that position

    void gotopos(volatile float _X, volatile  float _Y)
    {
      Serial.println("In gotopos");
      X = _X;
      Y = _Y;
      flag[0][leg] = 1;
      flag[1][leg] = 1;
      Serial.print(X, Y);
    }
    void chosen_fun()
    {
      if  (neg_flag[leg] == 1)
      {
        calculate_neg_angle(X, Y);
        //        Serial.println("neg");

      }

      if  (pos_flag[leg] == 1)
      {
        calculate_pos_angle(X, Y);
        //        Serial.println("pos");
      }
    }


    //*************************//
    //choose function

    void choose_fn()
    {
      //  Serial.println("In choose_fn");
      //Serial.print(X,Y);
      if (X < 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          //          calculate_neg_angle(X, Y);
          neg_flag[leg] = 1;
        }
      }
      else if (X >= 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          //          calculate_pos_angle(X, Y);
          pos_flag[leg] = 1;
        }
      }
      else
      {
        // Serial.print("X ");
        //Serial.print(X);
        Serial.println("  gotopos not set");
      }
    }

    //*************************//
    //calculates angle for positive X

    void calculate_pos_angle(float X, float Y)
    {
      //  Serial.println("In calcpos");
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
      //Serial.println("In calcneg");
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
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      delay(2);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

      ax = kfx.updateEstimate(ax);
      az = kfy.updateEstimate(az);

      Serial.print("Leg1   angle=");
//      Serial.print(ax);
//      Serial.print(" ");
      angle = 180 * atan2(ax, az) / PI;
      //ax=map(ax,-4200,-15600,11.5,96.5);
      angle = angle + 3;
      fb1 = abs(angle);
      Serial.print(fb1);
      Serial.print(" ");
      Serial.print(T[0][leg]);
      //Serial.print("                az=");
      //Serial.print(az);
      digitalWrite(9, LOW);

      digitalWrite(10, HIGH);
      delay(2);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

      ax = kfx1.updateEstimate(ax);
      az = kfy1.updateEstimate(az);
      Serial.print("Leg2   angle=");
//      Serial.print(ax);
      Serial.print(" ");
      angle = 180 * atan2(ax, az) / PI;
      //ax=map(ax,-4200,-15600,11.5,96.5);
      fb2 = abs(angle + 10);
      //fb2=angle-fb1;
//      Serial.print("  Leg2  ");
      Serial.print(fb2);
      Serial.print(" ");
      Serial.println(T[1][leg]);
      //      ax = ADCFilter2.Current();
      //      if (az > 0)
      //      {
      //        if (ax < 0)
      //          ax = map(ax, 0, -15000, 5, 99);
      //        else
      //          ax = map(ax, 0, 15000, 270, 359);
      //      }
      //      else {
      //        if (ax < 0)
      //          ax = map(ax, 0, -15000, 180, 90);
      //        else
      //          ax = map(ax, 0, 15000, 180, 270);
      //      }
      //      fb2 = ax;
      //      Serial.println("Leg2");
      //Serial.println(ax);
      //      Serial.println(az);
      digitalWrite(10, LOW);


      //Print statements for debugging
      //      Serial.print(leg);
      //      Serial.print("  ");
      //      Serial.print("  fb1  ");
      //      Serial.print(fb1);
      //      Serial.print("  T[0][leg]  ");
      //      Serial.print(T[0][leg]);
      //      Serial.print("  fb2  ");
      //      Serial.print(fb2);
      //      Serial.print("  T[1][leg]  ");
      //      Serial.println(T[1][leg]);
      //
      //      //Find error
      error1 = T[0][leg] - fb1;
      error2 = T[1][leg] - fb2;
//      Serial.println(error1);
//      Serial.println(error2);
      //Control statements for feedback based motion
      if (abs(error1) < 2)
      {
        hardstop(relay[leg][0], relay[leg][1]);
        flag[0][leg] = 0;
        Serial.println("L1 stop");
      }
      if (abs(error2) < 2)
      {
        hardstop(relay[leg][2], relay[leg][3]);
        flag[1][leg] = 0;
        Serial.println("L2 stop");
      }

      if (fb1 < T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          forward(relay[leg][0], relay[leg][1]);
          Serial.print("leg one  move down");
        }
        if (flag[1][leg] == 1)
        {
          forward(relay[leg][2], relay[leg][3]);
          Serial.print("leg two  move down");
        }
      }
      else if (fb1 < T[0][leg] && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          forward(relay[leg][0], relay[leg][1]);
          Serial.print("leg one  move down");
        }
        if (flag[1][leg] == 1)
        {
          backward(relay[leg][2],  relay[leg][3]);
          Serial.print("leg two move up");
        }
      }
      else if (fb1 > T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          backward(relay[leg][0], relay[leg][1]);
          Serial.print("leg one  move up");
        }
        if (flag[1][leg] == 1)
        {
          forward(relay[leg][2], relay[leg][3]);
          Serial.print("leg two  move down");
        }
      }
      else if (fb1 > T[0][leg]  && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          backward(relay[leg][0], relay[leg][1]);
          Serial.print("leg one  move up");
        }
        if (flag[1][leg] == 1)
        {
          backward(relay[leg][2], relay[leg][3]);
          Serial.print("leg two  move up");
        }
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
    void check_point()
    {
//      Serial.println("IN CHECKPOINT");
      if (flag[0][leg] == 0 && flag[1][leg] == 0)
      {
//        Serial.println("NEXT POINT");
        pointer++;
        if (pointer > 5)
        {
          pointer = 0;
        }
        gotopos(points[pointer][0], points[pointer][1]);
//        Serial.println(points[pointer][0], points[pointer][1]);
      }
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
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  Wire.begin();
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  //   digitalWrite(10, HIGH);
  //  digitalWrite(9, LOW);
  //  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  //  for (int i = 0; i < 4; i++)
  //  {
  //    for (int j = 0; j < 4; j++)
  //    {
  //      pinMode(relay[i][j], OUTPUT);
  //    }
  //  }

  Serial.begin(115200);

  // join I2C bus (I2Cdev library doesn't do this automatically)
  //Wire.begin();

  // initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");



  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

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


  // initialize timer1

  noInterrupts();           // disable all interrupts

  TCCR1A = 0 ;

  TCCR1B = 0;

  TCNT1  = 0;

  OCR1A = 2000;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS12);    // 256 prescaler

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  //  Serial.print("noint");
  interrupts();             // enable all interrupts
  Serial.println("Set points");
  leg1.gotopos(-15, 6);
  //  leg2.gotopos(-20, 60);
  //  leg3.gotopos(-20, 60);
  //  leg4.gotopos(-20, 60);

}
//*************************//
//ISR

SIGNAL(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  //  if (digitalRead(2) == HIGH)
  //  {
  cli();
  OCR1A = 3000;
  //Serial.println("In ISR");
  leg1.choose_fn();
  leg1.check_point();
  //  a++;
  sei();
  //  leg2.choose_fn();
  //  leg3.choose_fn();
  //  leg4.choose_fn();
  //  }
}
//*************************//
//loop function


void loop()
{
  //Serial.println("hello");
  //Serial.println(a);
  leg1.chosen_fun();

  //*************************//
}
