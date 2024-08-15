void setup() {
  // put your setup code here, to run once:
  pinMode(A5,INPUT);
  Serial.begin(9600);
}
int read;

void loop() {
  // put your main code here, to run repeatedly:
  read=analogRead(A5);
  Serial.print("Reading of sensor is : ");
  Serial.println(read);
  delay(500);
}
