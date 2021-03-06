//Include all libraries
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "MegunoLink.h"
#include "SimpleKalmanFilter.h"
/**********************************************/
//MPU6050 accelgyro; // <--use for AD0 floating
MPU6050 accelgyro(0x69); // <-- use for AD0 high
volatile int go_point=1;

//                                                               ^
/**********************************************/
//Declare constants for mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;
float points[7][2] = {{0, 0}, {14.3 , 6.6}, {10.5, 14.7}, {20, 20}, {30.5, 14.7}, {24.3, 6.6}, {40, 0}};
int x_bias = 10;
int y_bias = 50;
int pointer[4] = {1, 4, 1, 4};
int e_mea = 1;

int e_est = 1;
int q = 1;
SimpleKalmanFilter kfx_leg1 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfz_leg1 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx_leg2 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfz_leg2 = SimpleKalmanFilter(e_mea, e_est, q);
//Declaring all the variables

//  float pi = 3.14159;
float a1 = 0;
float a2 = 39;
float a3 = 0;
float a4 = 39;
int relay[4][4] = {{4, 5, 6, 7}, {31, 33, 35, 37}, {39, 41, 43, 45},{47, 49, 51, 53}};//{{23, 25, 27, 29}, {31, 33, 35, 37}, {39, 41, 43, 45}, {47, 49, 51, 53}};
float T[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
bool flag[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
/*****************************************************************************************************************************/
//Class for leg

class Leg
{
  public:
    int leg;  //private variable for leg number
    float X;
    float Y;

    Leg(int _leg)
    {
      leg = _leg; //declare public variable
    }
    //*************************//
    //gotopos takes X and Y and Goes to that position

    void gotopos(float _X, float _Y)
    {
      //      Serial.println("In gotopos");
      X = _X;
      Y = _Y;
      flag[0][leg] = 1;
      flag[1][leg] = 1;
      Serial.print("gotopos");
    }
    //*************************//
    //choose function

    void choose_fn()
    {
      //      Serial.println("In choose_fn");
      if (X <= 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          calculate_neg_angle(X, Y);
        }
      }
      else if (X > 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          calculate_pos_angle(X, Y);
        }
      }
      else
      {
        //        Serial.print("X ");
        //        Serial.print(X);
        //        Serial.println("  gotopos not set");
      }
    }

    //*************************//
    //calculates angle for positive X

    void calculate_pos_angle(float X, float Y)
    {
      //      Serial.println("In calcpos");
      float r1 = 0;
      float phi1 = 0;
      float phi2 = 0;
      float phi3 = 0;
      r1 = sqrt(X * X + Y * Y);
      phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2.0 * a2 * r1));
      phi2 = atan(Y / X);
      T[0][leg] = phi2 - phi1;
      phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2.0 * a2 * a4));
      T[1][leg] = PI - phi3;
      T[0][leg] = T[0][leg] * 180 / PI;
      T[1][leg] = T[1][leg] * 180 / PI;
      onoffcontrol();
    }
    //*************************//
    //calculates angle for niggative X

    void calculate_neg_angle(float X, float Y)
    {
      //      Serial.println("In calcneg");
      float r1 = 0;
      float phi1 = 0;
      float phi2 = 0;
      float phi3 = 0;
      X = abs(X);
      r1 = sqrt(X * X + Y * Y);
      phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2.0 * a2 * r1));
      phi2 = atan(-Y / X);
      phi2 = PI + phi2;
      T[0][leg] = phi2 - phi1;
      phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2.0 * a2 * a4));
      T[1][leg] = PI - phi3;
      T[0][leg] = T[0][leg] * 180 / PI;
      T[1][leg] = T[1][leg] * 180 / PI;
      onoffcontrol();
    }
    //*************************//
    //control logic for motion

    void onoffcontrol()
    {
      //Read the feedback pot
      float fb1 = 0;
      float fb2 = 0;
      float angle;
      float error1 = 0;
      float error2 = 0;
      digitalWrite(10, HIGH);
      
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      angle = find_angle(ax, ay, 0);
      Serial.print("Leg1");
      Serial.println(angle);
      digitalWrite(10, LOW);
      fb1 = angle;

      digitalWrite(9, HIGH);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      angle = find_angle(ax, ay, 1);
      Serial.print("Leg2");
      Serial.println(angle);
      digitalWrite(9, LOW);
      fb2 = angle;

      //      //Print statements for debugging
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
          backward(relay[leg][2],  relay[leg][3]);
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
    float find_angle(int ax, int ay , int a)
    {

      static  float angle;
      if (a == 0)
      {
        ax = kfx_leg1.updateEstimate(ax);
        az = kfz_leg1.updateEstimate(az);
        return angle = 180 * atan2(ax, az) / PI;
      }
      else
      {
        ax = kfx_leg2.updateEstimate(ax);
        az = kfz_leg2.updateEstimate(az);
        return angle = 180 * atan2(ax, az) / PI;
      }
    }

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

Leg leg1 = Leg(0);
Leg leg2 = Leg(1);
Leg leg3 = Leg(2);
Leg leg4 = Leg(3);
//*****************************************************************************************************************************//
class walkGait : public Leg
{
  public:
    //Declare constants
    int diff;
    float X;
    float Y;
    walkGait(int _leg): Leg(_leg)
    {
      leg = _leg;
    }
    //*************************//
    //decide path either sine or line
    void givePath()
    {
      move_leg(leg);
    }
    //*************************//
    //choose function
    void chosen_point()
    {
      Serial.print("leg 0 points ");
      Serial.print(points[pointer[0]][0]);
      Serial.print("  ");
      Serial.println(points[pointer[0]][1]);
      leg1.gotopos(points[pointer[0]][0], points[pointer[0]][1]);
      pointer[0]++;
      if (pointer[0] > 5)
        pointer[0] = 0;
    }
    void move_leg(int leg)
    {
      //check if previous point reached
      if (leg == 0)
      {
        if (flag[leg][0] == 1 && flag[leg][1] == 1)
        {
          //leg0.gotopos(points[leg][0], points[leg][1]);
          go_point = 1;
        }
        else go_point = 0;
      }
      else if (leg == 1)
      {
        if (flag[leg][0] == 1 && flag[leg][1] == 1)
        {
          //leg1.gotopos(points[leg][0], points[leg][1]);
          Serial.print("leg 1 points ");
          Serial.print(points[pointer[1]][0]);
          Serial.print("  ");
          Serial.println(points[pointer[1]][1]);
          pointer[1]++;
          if (pointer[1] > 5)
            pointer[1] = 0;
        }
      }
      else if (leg == 2)
      {
        if (flag[leg][0] == 1 && flag[leg][1] == 1)
        {
          //leg2.gotopos(points[leg][0], points[leg][1]);
          Serial.print("leg 2 points ");
          Serial.print(points[pointer[2]][0]);
          Serial.print("  ");
          Serial.println(points[pointer[2]][1]);
          pointer[2]++;
          if (pointer[2] > 5)
            pointer[2] = 0;
        }
      }
      else if (leg == 3)
      {
        if (flag[leg][0] == 1 && flag[leg][1] == 1)
        {
          //leg3.gotopos(points[leg][0], points[leg][1]);
          Serial.print("leg 3 points ");
          Serial.print(points[pointer[3]][0]);
          Serial.print("  ");
          Serial.println(points[pointer[3]][1]);
          pointer[3]++;
          if (pointer[3] > 5)
            pointer[3] = 0;
        }
      }
    }
};

walkGait path0 = walkGait(0);
//walkGait path1 = walkGait(1);
//walkGait path2 = walkGait(2);
//walkGait path3 = walkGait(3);



//Setup function to setup baud ratepinModes

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10,LOW);
  digitalWrite(9, LOW);

  Wire.begin();
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  //  for (int i = 0; i < 4; i++)
  //  {
  //    for (int j = 0; j < 4; j++)
  //    {
  //     pinMode(relay[i][j], OUTPUT);
  //    }
  //  }

  Serial.begin(115200);

  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

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

  noInterrupts();           // disable all interrupts

  TCCR1A = 0 ;

  TCCR1B = 0;

  TCNT1  = 0;

  OCR1A = 2000;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS12);    // 256 prescaler

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  //  Serial.print("noint");
  interrupts();
  Serial.println("Set points");

  //  leg2.gotopos(-20, 60);
  //  leg3.gotopos(-20, 60);
  //  leg4.gotopos(-20, 60);
  leg1.gotopos(points[pointer[0]][0], points[pointer[0]][1]);

}
//*************************//
//ISR


SIGNAL(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{

  //  if (digitalRead(2) == HIGH)
  //  {
  //  Serial.println("In ISR");
  cli();
  OCR1A = 2000;
  //Serial.println("In ISR");
  //leg1.choose_fn();
  path0.givePath();
  sei();

  //  }
}
//*************************//
//loop function


void loop()
{
  //leg1.gotopos(-20, 60);
  if (go_point == 1)
  {
    path0.chosen_point();
  }

}
//*************************//
