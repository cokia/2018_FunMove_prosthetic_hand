#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial inP(6, 7);

int i = 0;
char zheld[6] = {0};

int onC = 145;
int twC = 180;
int thC = 145;
int foc = 120;
int fiC = 100;

int onO = 0;
int twO = 0;
int thO = 0;
int foO = 0;
int fiO = 0;

Servo on;
Servo tw;
Servo th;
Servo fo;
Servo fi;

void gbb();
void jip();

void setup() {
  Serial.begin(9600);
  inP.begin(9600);
  inP.write("AT");
  inP.write("AT+NAMENULL");
  inP.write("AT+PIN2002");

  on.attach(3);
  tw.attach(5);
  th.attach(9);
  fo.attach(10);
  fi.attach(11);
  
  on.write(onO);
  tw.write(twO);
  th.write(thO);
  fo.write(foO);
  fi.write(fiO);  
}

void loop() {
  while (Serial.available()>0) {
  Serial.println("")
  zheld[i] = Serial.read();
  Serial.println(zheld[i]);
  i++;
  delay(10);
  }
  while (inP.available()>0) {
    zheld[i] = inP.read();
    Serial.println(zheld[i]);
    i++;
    delay(10);
  }

    if (i == 5) {

      switch(zheld[0]) {
      case '2' :
      gbb();
      break;

      case '3' :
      jip();
      break;
      }

      if (zheld[0] == '1') on.write(onC);
      else on.write(onO);

      if (zheld[1] == '1') tw.write(twC);
      else tw.write(twO);

      if (zheld[2] == '1') th.write(thC);
      else th.write(thO);

      if (zheld[3] == '1') fo.write(foC);
      else fo.write(foO);

      if (zheld[4] == '1') fi.write(fiC);
      else fi.write(fiO);

      i = 0;
    }
}

void gbb() {
  on.write(onC);
  tw.write(twO);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);

  on.write(onC);
  tw.write(twC);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onO);
  tw.write(twO);
  th.write(thO);
  fo.write(foO);
  fi.write(fiO);
  
  delay(1000);
}

void jip() {
  on.write(onO);
  tw.write(twO);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onC);
  tw.write(twC);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onO);
  tw.write(twO);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onC);
  tw.write(twC);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onO);
  tw.write(twO);
  th.write(thC);
  fo.write(foC);
  fi.write(fiC);
  
  delay(1000);
  
  on.write(onO);
  tw.write(twO);
  th.write(thO);
  fo.write(foO);
  fi.write(fiO);
  
  delay(1000); 
}

void 