#define m1 3  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 6  //Left Motor MB1
#define m4 9  //Left Motor MB2

#define s1 A2  // Left Sensor
#define s2 A5  // Middle Sensor
#define s3 A3  // Right Sensor
void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  Serial.begin(9600);
}
void Forward() {
  analogWrite(m1, 80);
  analogWrite(m2, 0);
  analogWrite(m3, 80);
  analogWrite(m4, 0);
}

void Right() {
  analogWrite(m1, 0);
  analogWrite(m2, 80);
  analogWrite(m3, 80);
  analogWrite(m4, 0);
}

void Left() {
  analogWrite(m1, 80);
  analogWrite(m2, 0);
  analogWrite(m3, 0);
  analogWrite(m4, 80);
}


void Stop() {
  analogWrite(m1, 0);
  analogWrite(m4, 0);
  analogWrite(m3, 0);
  analogWrite(m2, 0);
}



void loop() {


  int IR1 = digitalRead(s1);
  int IR2 = digitalRead(s2);
  int IR3 = digitalRead(s3);
  // Serial.print("Reading of sensor1 is : ");
  // Serial.println(IR1);
  // Serial.print("Reading of sensor2 is : ");
  // Serial.println(IR2);
  // Serial.print("Reading of sensor3 is : ");
  // Serial.println(IR3);

  if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH)  // T-intersection
  {
    Left();
    delay(250);
  } else if (IR1 == LOW && IR2 == HIGH && IR3 == HIGH)  //Right Intersection
  {
    Stop();
    delay(20);
    Forward();
    delay(10);
    if (digitalRead(s1) == LOW && digitalRead(s2) == LOW && digitalRead(s3) == LOW) {
      Right();
      delay(250);
    }
  } else if (IR1 == LOW && IR2 == HIGH && IR3 == LOW)  //Straight Path
  {
    Forward();
    delay(10);
  }

  else if (IR1 == HIGH && IR2 == HIGH && IR3 == LOW)  //Left T Intersection
  {
    Left();  // As Left is possible
    delay(250);
  }

  else if (IR1 == HIGH && IR2 == LOW && IR3 == LOW)  //Left Deviated
  {
    Left();
    delay(20);
  }

  else if (IR1 == LOW && IR2 == LOW && IR3 == HIGH)  //Right Deviated
  {
    Right();
    delay(20);
  }

  else if (IR1 == LOW && IR2 == LOW && IR3 == LOW)  //Dead End
  {
    Forward();
    delay(100);
    Left();  //As no other direction is possible
    delay(250);
  }
}