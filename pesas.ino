#define pinled5 5

void setup() {
  // put your setup code here, to run once:
  pinMode(pinled5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinled5,HIGH);
  delay(700);
  digitalWrite(pinled5,LOW);
  delay(700);
}
