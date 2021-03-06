// this code is for driver recieved from robukits having direction pin ,brake pin , and pwm pin
//Include all libraries
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "MegunoLink.h"
#include "SimpleKalmanFilter.h"
//volatile int a = 0;
/**********************************************/
//MPU6050 accelgyro; // <--use for AD0 floating
MPU6050 accelgyro(0x69); // <-- use for AD0 high
int e_mea = 1;
float angle;
int e_est = 1;
int q = 1 ;
int l = 0, m = 1, n = 2, o = 3;
SimpleKalmanFilter kfx11 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy11 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx12 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy12 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx21 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy21 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx22 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy22 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx31 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy31 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx32 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy32 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx41 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy41 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfx42 = SimpleKalmanFilter(e_mea, e_est, q);
SimpleKalmanFilter kfy42 = SimpleKalmanFilter(e_mea, e_est, q);

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
float fb1;
volatile int  no_pointer = 4;
int pwm[4][2] = {{3, 2}, {5, 4}, {7, 6}, {9, 8}};
int driver[4][2] = {{38, 36}, {42, 40}, {46, 44}, {50, 48}};
int mpu [4][2] = {{22, 23}, {24, 25}, {26, 27}, {28, 29}};
int brake[4][2] = {{39, 37}, {43, 41}, {47, 45}, {51, 49}};
float T[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
volatile int flag[][4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
volatile int neg_flag[4] = {0, 0, 0, 0};
volatile int pos_flag[4] = {0, 0, 0, 0};
boolean b; ///uiadhfiuahdif
//volatile float points[9][2] = {{-19.34,54.90},{-17.3,49.96},{-13.4,45.153},{9.8,42.66},{13.7,45.429},{17.2,49.79},{19.3,54.755},{20,60},{-20,60} };
volatile float points_leg1[4][2] = {{1, 50}, {20, 60}, {1, 60}, { -20, 60}}; //, { -20, 60} }; // rear
volatile float points_leg3[4][2] = {{ -20, 60}, {1, 50}, {20, 60}, {1, 60}}; //rear
volatile float points_leg2[4][2] = {{ -20, 60}, {1, 60}, {20, 60}, {1, 50}}; //front
volatile float points_leg4[4][2] = {{1, 60}, {20, 60}, {1, 50}, { -20, 60}}; //front
//volatile float points[10][2] = {/*{0, 55.15}, { 0 , 54.15}, { 0, 53.15}, { 0, 52.15}, { 0, 51.15},*/ { 0, 50.15}, { -6, 51.15}, { -8, 52.15}, { -9.17, 53.15}, { -9.8, 54.15}, { -10, 55.15}, { -9.8, 56.15}, { -9.17, 57.15}, { -8, 58.15}, { -6, 59.15}};
//volatile float points[36][2] = { { 0, 55.15}, { 0, 54.15}, { 0, 53.15}, { 0, 52.15}, { 0, 51.15}, { 0, 50.15}, { -6, 51.15}, { -8, 52.15}, { -9.17, 53.15}, { -9.8, 54.15},{-10, 55.15},{ -9, 55.15},{-8,55.15},{-7,55.15},{-6,55.15},{-5,55.15},{-4,55.15},{-3,55.15},{-2,55.15},{-1,55.15},{0,55.15},{1,55.15},{2,55.15},{3,55.15},{4,55.15},{5,55.15},{6,55.15},{7,55.15},{8,55.15},{9,55.15},{10,55.15},{9.8,54.15},{9.17,53.15},{8,52.15},{6,51.15},{0.50.15} };
volatile int pointer = 0;
/*****************************************************************************************************************************/
//Class for leg

//class next_leg
//{
//  Leg current_leg;
//  public:
//
//};
class Leg
{
  public:
    volatile int leg;  //private variable for leg number
    volatile float X;
    volatile float Y;
    volatile float points[3][2];
    friend void chooseleg();
    SimpleKalmanFilter kfx = SimpleKalmanFilter(e_mea, e_est, q);
    SimpleKalmanFilter kfy = SimpleKalmanFilter(e_mea, e_est, q);
    SimpleKalmanFilter kfx1 = SimpleKalmanFilter(e_mea, e_est, q);
    SimpleKalmanFilter kfy1 = SimpleKalmanFilter(e_mea, e_est, q);

    int readIndex[2] = {0, 0};
    int total[2] = {0, 0};

    int numReadings = 10;
    int readings[2][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    float  avg1, avg2;
    float fb2 = 0, fb1 = 0;
    float error1 = 0;
    float error2 = 0;
    Leg(int _leg, SimpleKalmanFilter _kfx, SimpleKalmanFilter _kfy, SimpleKalmanFilter _kfx1, SimpleKalmanFilter _kfy1, volatile float _points[][2])
    {
      leg = _leg; //declare public variable
      SimpleKalmanFilter kfx = _kfx;
      SimpleKalmanFilter kfy = _kfy;
      SimpleKalmanFilter kfx1 = _kfx1;
      SimpleKalmanFilter kfy1 = _kfy1;
      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 2; j++)
        {
          points[i][j] = _points[i][j];
        }
      }


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
      Serial.print(X);
      Serial.print("  ");
      Serial.print(Y);
    }
    void chosen_fun()
    {
      if  (neg_flag[leg] == 1)
      {
        calculate_neg_angle(X, Y);
        neg_flag[leg] = 0;
      }

      if  (pos_flag[leg] == 1)
      {
        calculate_pos_angle(X, Y);
        pos_flag[leg] = 0;
      }
    }


    //*************************//
    //choose function

    void choose_fn()
    {
      if (X < 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          neg_flag[leg] = 1;
        }
      }
      else if (X >= 0)
      {
        if (flag[0][leg] == 1 || flag[1][leg] == 1)
        {
          pos_flag[leg] = 1;
        }
      }
      else
      {
        Serial.println("  gotopos not set");
      }
    }

    //*************************//
    //calculates angle for positive X

    void calculate_pos_angle(float X, float Y)
    {
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
      //
      //      r1 = sqrt(X * X + Y * Y);
      //      phi1 = (acos((r1 * r1 + a2 * a2 - a4 * a4) / (2 * a2 * r1))) * 180. / PI;
      //      phi2 = (atan(Y / X)) * 180 / PI;
      //      phi3 = (acos((a2 * a2 + a4 * a4 - r1 * r1) / (2 * a2 * a4))) * 180. / PI;
      //      T[0][leg] = phi1 + phi2;
      //      T[1][leg] = phi3 + T[0][leg] - 180;
      //      T[0][leg] = 180 - T[0][leg] ;/
      //      T[1][leg] = 180 - T[1][leg] ;/
      //steve changes
      //      T[0][leg] = 180 - T[0][leg];
      //      T[1][leg] = 180 - T[1][leg];

      //      T[0][leg] = T[0][leg] - 90;
      /*********************/
      //       r1 = sqrt(X * X + Y * Y);
      //      phi1 = acos(((r1 * r1) + (a2 * a2) - (a4 * a4)) / (2.0 * a2 * r1));
      //      phi2 = atan(Y / X);
      //      phi3 = (acos(((a4 * a4) + (a2 * a2) - (r1 * r1)) / (2.0 * a2 * a4)))*180/PI;
      //      T[0][leg] = (phi2 + phi1)*180/PI;
      //      T[1][leg] = -(phi3 + T[0][leg] - 180);
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
      //      T[1/][leg] = phi3 + T[0][leg] - 180;
      //      //steve

      //      r1 = sqrt(X * X + Y * Y);
      //      phi1 = (acos((r1 * r1 + a2 * a2 - a4 * a4) / (2 * a2 * r1))) * 180. / PI;
      //      phi2 = (atan(-Y / X)) * 180 / PI; // Here X is negetive so, in k2 it is multipled by negetive sign.
      //      phi3 = (acos((a2 * a2 + a4 * a4 - r1 * r1) / (2 * a2 * a4))) * 180. / PI;
      //      T[0][leg] = phi1 + phi2;
      //      T[1][leg] = phi3 + T[0][leg] - 180;
      //      T[0][leg] = 180 - T[0][leg] ;/
      //      T[1][leg] = 180 - T[1][leg] ;/

      //   T[0][leg] = 180 - T[0][leg];
      //      T[1][leg] = 180 - T[1][leg]'
      onoffcontrol();
    }
    //*************************//
    //control logic for motion

    void onoffcontrol()
    {
      float Kp1 = 1.3, Kp2 = 45;
      int standard = 150;
      //Read the feedback pot

      digitalWrite(mpu[leg][0], HIGH);
      digitalWrite(mpu[leg][1], LOW);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      Serial.print("#####################################leg   ");
      Serial.println(leg);

      ax = kfx.updateEstimate(ax);
      az = kfy.updateEstimate(az);
      Serial.print("Link 1   angle=");
      angle = 180 * atan2(ax, az) / PI;
      fb1 = abs(angle) - 5.5 ;
      Serial.print(fb1);
      avg1 = average(fb1, 0);
      Serial.print("   ");
      Serial.print(T[0][leg]);
      digitalWrite(mpu[leg][0], LOW);

      digitalWrite(mpu[leg][1], HIGH);
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      ax = kfx1.updateEstimate(ax);
      az = kfy1.updateEstimate(az);
      Serial.print("Link2   angle=");
      Serial.print(" ");
      angle = 180 * atan2(ax, az) / PI;
      fb2 =  abs(angle);
      fb2 = fb2 - fb1;
      Serial.print(fb2);
      Serial.print(" ");
      Serial.println(T[1][leg]);
      Serial.print(" ");
      avg2 = average(fb2, 1);
      Serial.println(avg1);
      Serial.println(avg2);
      fb1 = avg1;
      fb2 = avg2;
      digitalWrite(mpu[leg][1], LOW);

      //      //Find error
      error1 = T[0][leg] - fb1;
      error2 = T[1][leg] - fb2;
      int pwm1 = (abs(error1) - abs(error2)) * Kp1 + standard;
      int pwm2 = 255;
      //      int pwm1 = int((error1) * Kp1 * (abs(error1) - abs(error2)) + standard);
      //      int pwm2 = int((error2) * Kp2 * (pow(1.7, (-abs(error1) + 20)) + 1) + standard);
      pwm1 = constrain(pwm1, 0, 255);
      //      pwm2 = constrain(pwm2, 0, 255);


      analogWrite(pwm[leg][0], 255); //pwm1);
      analogWrite(pwm[leg][1], 255); //);

      //      Serial.print(" ");
      //      Serial.print(p/wm[leg][0]);
      //      Serial.print(pwm[/leg][1]);
      //Control statements for feedback based motion
      if ((error1) <= 5 && (error1) >=  -5 )
      {
        //hardstop(relay[leg][0], relay[leg][1]);
        analogWrite(pwm[leg][0], 0);
        hardstop(brake[leg][0]);
        flag[0][leg] = 0;
        Serial.print(pwm[leg][0]);
        Serial.println("L1 stop");

      }
      else
      {
        flag[0][leg] = 1;
        Serial.println("L1 start");

      }
      if ((error2) <= 5 && (error2) >= -5 )
      {
        analogWrite(pwm[leg][1], 0);
        hardstop(brake[leg][1]);
        flag[1][leg] = 0;
        Serial.print(pwm[leg][1]);
        Serial.println("L2 stop");

      }
      else
      {
        flag[1][leg] = 1;
        Serial.println("L2 start");

      }

      if (fb1 < T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          //          forward(relay[leg][0], relay[leg][1]);
          backward(driver[leg][0], brake[leg][0]);
          Serial.print("link one increase angle"); Serial.print(" "); Serial.print (driver[leg][0]); Serial.print(" "); Serial.print (driver[leg][1]);
        }
        if (flag[1][leg] == 1)
        {
          backward(driver[leg][1], brake[leg][1]);
          Serial.print("link two  increase angle"); Serial.print(" "); Serial.print (driver[leg][2]); Serial.print(" "); Serial.print (driver[leg][3]);
        }
      }
      else if (fb1 < T[0][leg] && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          //          forward(driver[leg][0], driver[leg][1]);
          backward(driver[leg][0], brake[leg][0]);
          Serial.print("link one  increase angle"); Serial.print(" "); Serial.print (driver[leg][0]); Serial.print(" "); Serial.print (driver[leg][1]);
        }
        if (flag[1][leg] == 1)
        {
          forward(driver[leg][1],  brake[leg][1]);
          Serial.print("link two decrease angle"); Serial.print(" "); Serial.print (driver[leg][2]); Serial.print(" "); Serial.print (driver[leg][3]);
        }
      }
      else if (fb1 > T[0][leg] && fb2 < T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          //          backward(driver[leg][0], driver[leg][1]);
          forward(driver[leg][0], brake[leg][0]);
          Serial.print("link one decrease angle"); Serial.print(" "); Serial.print (driver[leg][0]); Serial.print(" "); Serial.print (driver[leg][1]);
        }
        if (flag[1][leg] == 1)
        {
          backward(driver[leg][1], brake[leg][1]);

          Serial.print("link two  increase angle"); Serial.print(" "); Serial.print (driver[leg][2]); Serial.print(" "); Serial.print (driver[leg][3]);
        }
      }
      else if (fb1 > T[0][leg]  && fb2 > T[1][leg])
      {
        if (flag[0][leg] == 1)
        {
          //          backward(driver[leg][0], driver[leg][1]);
          forward(driver[leg][0], brake[leg][0]);
          Serial.print("link one decrease angle"); Serial.print(" "); Serial.print (driver[leg][0]); Serial.print(" "); Serial.print (driver[leg][1]);
        }
        if (flag[1][leg] == 1)
        {
          forward(driver[leg][1], brake[leg][1]);
          Serial.print("link two  decrease angle"); Serial.print(" "); Serial.print (driver[leg][2]); Serial.print(" "); Serial.print (driver[leg][3]);
        }
      }
      Serial.print("flag");
      Serial.print(flag[0][leg]);
      Serial.print(flag[1][leg]);
    }
    //*************************//
    //back forward and stop functions

    void backward(int l1, int l2)
    {
      // actuator opening
      digitalWrite(l2, LOW);
      digitalWrite(l1, LOW);

    }

    void forward(int l1, int l2)
    {
      // actuator closing
      digitalWrite(l2, LOW);
      digitalWrite(l1, HIGH);

    }

    void hardstop(int l1)
    {
      digitalWrite(l1, HIGH);
    }
    void check_point()
    {
      //      Serial.println("IN CHECKPOINT");
      //if (flag[0][0] == 0 && flag[1][0] == 0 && flag[0][1] == 0 && flag[1][1] == 0 && flag[0][2] == 0 && flag[1][2] == 0 && flag[0][3] == 0 && flag[1][3] == 0 )
      {
        //        Serial.println("NEXT POINT");
        pointer++;
        //Serial.println("####################################################################");
        //        delay(1000);
        Serial.print("    pointer   " );
        Serial.println(pointer);
        if (pointer >  no_pointer - 1 )
        {
          pointer = 0;
        }
        gotopos(points[pointer][0], points[pointer][1]);
      }
    }
    float average(int val, int leg)
    {

      //      Serial.println();
      //      for (int o = 0 ; o < 2; o++)
      //      {
      //        for (int p = 0; p < 10; p++)
      //        {
      //          Serial.print(" "); Serial.print(readings[o][p]);
      //        }
      //        Serial.println();
      //      }
      total[leg] = total[leg] - readings[leg][readIndex[leg]];
      // read from the sensor:
      readings[leg][readIndex[leg]] = val;
      // add the reading to the total:
      total[leg] = total[leg] + readings[leg][readIndex[leg]];
      // advance to the next position in the array:
      readIndex[leg] = readIndex[leg] + 1;

      // if we're at the end of the array...
      if (readIndex[leg] >= numReadings) {
        // ...wrap around to the beginning:
        readIndex[leg] = 0;
      }

      // calculate the average:
      return (total[leg] / numReadings);
    }
    //*************************//
};




//*****************************************************************************************************************************//

//Leg leg1 = Leg(0, kfx11, kfy11, kfx12, kfy12, points_leg1);
//Leg leg2 = Leg(1, kfx21, kfy21, kfx22, kfy22, points_leg2);
Leg leg[4] = {Leg(0, kfx11, kfy11, kfx12, kfy12, points_leg1),
              Leg(1, kfx21, kfy21, kfx22, kfy22, points_leg2), Leg(2, kfx31, kfy31, kfx32, kfy32, points_leg3), Leg(3, kfx41, kfy41, kfx42, kfy42, points_leg4)
             };
//Leg leg3 = Leg(2);
//Leg leg4 = Leg(3);


//Setup function to setup baud rate pinModes

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  for (int i = 0 ; i < 4; i++)
  {
    for (int j = 0 ; j < 2; j++)
    {
      pinMode(driver[i][j], OUTPUT);
    }
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      pinMode(mpu[i][j], OUTPUT);
      digitalWrite(mpu[i][j], LOW);
    }
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      pinMode(brake[i][j], OUTPUT);
    }
  }
  for (int i = 0 ; i < 4; i++)
  {
    for (int j = 0 ; j < 2; j++)
    {
      pinMode(pwm[i][j], OUTPUT);
    }
  }




  digitalWrite(mpu[0][0], HIGH); digitalWrite(mpu[0][1], LOW); digitalWrite(mpu[1][0], LOW); digitalWrite(mpu[1][1], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.print("l1l1        ");
  Serial.print(mpu[0][0]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float  avg1, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[0].kfx.updateEstimate(ax);
    az = leg[0].kfy.updateEstimate(az);

    //    Serial.print("Leg1   an/gle=");
    //      Serial.print(ax);
    //      Serial.print(" ");
    angle = 180 * atan2(ax, az) / PI;

    fb1 = abs(angle) - 5.5 ; // fb1=180- abs(angle) -5 ;
    //    Serial.print(fb1/);
    avg1 = leg[0].average(fb1, 0);
  }


  digitalWrite(mpu[0][1], HIGH); digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[1][0], LOW); digitalWrite(mpu[1][1], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.println("l1l2     ");
  Serial.print(mpu[0][1]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[0].kfx1.updateEstimate(ax);
    az = leg[0].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle/=");
    //      Serial.print(ax);
    //    Serial.print(" "/);
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    avg2 = leg[0].average(fb2, 1);
  }

  //
  digitalWrite(mpu[1][0], HIGH); digitalWrite(mpu[0][1], LOW); digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[1][1], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.print("l2l1    ");
  Serial.print(mpu[1][0]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float  avg1, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[1].kfx.updateEstimate(ax);
    az = leg[1].kfy.updateEstimate(az);

    //    Serial.print("Le/g1   angle=");
    //      Serial.print(ax);
    //      Serial.print(" ");
    angle = 180 * atan2(ax, az) / PI;

    fb1 = abs(angle) - 5.5 ; // fb1=180- abs(angle) -5 ;
    //   / Serial.print(fb1);
    //    /avg1 = leg2.average(fb1, 0);
  }

  digitalWrite(mpu[1][1], HIGH);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.print("l2l2    ");
  Serial.print(mpu[1][1]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[1].kfx1.updateEstimate(ax);
    az = leg[1].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle=");/
    //      Serial.print(ax);
    //    Serial.print(" ")/;
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    ///avg2 = leg2.average(fb2, 1);
  }

  digitalWrite(mpu[1][1], LOW);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], HIGH); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.print("l3l1    ");
  Serial.print(mpu[2][0]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[2].kfx1.updateEstimate(ax);
    az = leg[2].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle=");/
    //      Serial.print(ax);
    //    Serial.print(" ")/;
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    ///avg2 = leg2.average(fb2, 1);
  }

  digitalWrite(mpu[1][1], LOW);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], HIGH); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);
  Serial.print("l3l2    ");
  Serial.print(mpu[2][1]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[2].kfx1.updateEstimate(ax);
    az = leg[2].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle=");/
    //      Serial.print(ax);
    //    Serial.print(" ")/;
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    ///avg2 = leg2.average(fb2, 1);
  }

  digitalWrite(mpu[1][1], LOW);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], HIGH); digitalWrite(mpu[3][1], LOW);
  Serial.print("l4l1    ");
  Serial.print(mpu[3][0]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[3].kfx1.updateEstimate(ax);
    az = leg[3].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle=");/
    //      Serial.print(ax);
    //    Serial.print(" ")/;
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    ///avg2 = leg2.average(fb2, 1);
  }

  digitalWrite(mpu[1][1], LOW);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], HIGH);
  Serial.print("l4l2    ");
  Serial.print(mpu[3][1]);
  accelgyro.initialize();
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  for (int a = 0; a <= 9; a++)
  {
    float fb2, avg2, angle;
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    ax = leg[3].kfx1.updateEstimate(ax);
    az = leg[3].kfy1.updateEstimate(az);
    //    Serial.print("Leg2   angle=");/
    //      Serial.print(ax);
    //    Serial.print(" ")/;
    angle = 180 * atan2(ax, az) / PI;

    fb2 =  abs(angle);
    fb2 = fb2 - fb1;

    ///avg2 = leg2.average(fb2, 1);
  }
  digitalWrite(mpu[1][1], LOW);  digitalWrite(mpu[0][1], LOW);  digitalWrite(mpu[1][0], LOW);  digitalWrite(mpu[0][0], LOW); digitalWrite(mpu[2][0], LOW); digitalWrite(mpu[2][1], LOW); digitalWrite(mpu[3][0], LOW); digitalWrite(mpu[3][1], LOW);



  //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  Serial.print(" "); Serial.print(mpu[0][0]); Serial.print(" "); Serial.print(mpu[0][1]); Serial.print(" "); Serial.print(mpu[1][0]); Serial.print(" "); Serial.print(mpu[1][1]);

  Serial.println("start");


  // initialize timer1

  noInterrupts();           // disable all interrupts

  TCCR1A = 0 ;

  TCCR1B = 0;

  TCNT1  = 0;

  OCR1A = 31250;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS12);    // 256 prescaler

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  //  Serial.print("noint");
  interrupts();             // enable all interrupts
  Serial.println("Set points");

  leg[l].gotopos(1, 50);
  leg[m].gotopos(-20, 60);
  leg[n].gotopos(-20, 60);
  leg[o].gotopos(1, 60);
  //leg2.gotopos(20, 60);

  Serial.println("done with this ");
  //  leg2.gotopos(-20, 60);
  //  leg3.gotopos(-20, 60);
  //  leg4.gotopos(-20, 60);

}
//*************************//
//ISR

SIGNAL(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{

  cli();
  OCR1A = 31250;
  leg[l].check_point();
  //leg[m].check_point();
  //leg[n].check_point();
  //leg[o].check_point();
  sei();

}
//*************************//
//loop function


void loop()
{
  Serial.println("IN LOOP");
  //Serial.println(a);

  leg[l].choose_fn();
  leg[m].choose_fn();
  leg[n].choose_fn();
  leg[o].choose_fn();
  leg[l].chosen_fun();
  leg[m].chosen_fun();
  leg[n].chosen_fun();
  leg[o].chosen_fun();



  //leg2.chosen_fun();
  //*************************//
}
