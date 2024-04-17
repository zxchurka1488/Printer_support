#include <Stepper.h>
#include <Servo.h>
int s = 0;
int enPin_x = 38;
int enPin_y =  56;
int enPin_z = 62;
int x_cords = 0;
int y_cords = -35;
const int stepsPerRevolution = 13000;
const int stepsForP = 13000;


Stepper stepper_x(stepsPerRevolution, 55, 54);
Stepper stepper_y(stepsPerRevolution, 61, 60);
Stepper stepper_z(stepsForP, 48, 46);
Servo servo;

int datafromUser=0;

void setup() {
  pinMode(enPin_x, OUTPUT);
  digitalWrite(enPin_x, LOW);
  pinMode(enPin_y, OUTPUT);
  digitalWrite( enPin_y, LOW);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);

  servo.attach(4); 
  servo.write(0);

  Serial.begin(9600);
  delay(1000);
  digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      delay(5000);
      digitalWrite(8, LOW);
   digitalWrite(7, LOW);      
   digitalWrite(9, LOW);
    digitalWrite(10, LOW);         
}

void loop() {

  if(Serial.available() > 0)
  {
    datafromUser=Serial.read();
    s = 0;

    if(datafromUser == '8')
    {
      stepper_x.step(stepsPerRevolution*2);
      x_cords = x_cords + 2;
    }

    else if(datafromUser == '9')
    {
      stepper_x.step(stepsPerRevolution*6);
      x_cords = x_cords + 6;
    }

    else if(datafromUser == '0')
    { 
        
     servo.write(0);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
    
       
      }
  } 
    else if(datafromUser == '1')
  {
     servo.write(80);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }

    else if(datafromUser == '2')
  {
     servo.write(40);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }

    else if(datafromUser == '3')
  {
     servo.write(125);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }
      

    else if(datafromUser == '4')
  {
     servo.write(20);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }

    else if(datafromUser == '5')
  {
     servo.write(105);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }
    else if(datafromUser == '6')
  {
     servo.write(60);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }
    else if(datafromUser == '7')
  {
     servo.write(150);
      if (x_cords >= y_cords)
      {
        s=1;
        while (y_cords < x_cords + 50)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords++;
            }
      }
      else if (y_cords > x_cords && s==0) 
      {
        while (y_cords > x_cords - 50)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords--;
        }
       
      }
  }

  }
