#define lb 3      
#define lf 5     
#define rb 6     
#define rf 9     

#define LB A2     
#define RF A5      
#define LF A3       
#define RB A4
void setup ()
{
  pinMode(LB, INPUT);
  pinMode(RF, INPUT);
  pinMode(LF, INPUT);
  pinMode(RB, INPUT);

  pinMode(lb, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(rf, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  if(LB > 100)
  digitalWrite(lb,HIGH);
  if(RF > 100)
  digitalWrite(rf,HIGH);
  if(LF > 100)
  digitalWrite(lf,HIGH);
  if(RB > 100)
  digitalWrite(rb,HIGH);
}
