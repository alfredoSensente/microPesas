#define pinled5 5
#define btn_chicharra 2
int resultado=1;
signed long tiempo=millis();
void setup() {
  // put your setup code here, to run once:
  pinMode(pinled5,OUTPUT);
  pinMode(btn_chicharra,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btn_chicharra)==HIGH and tiempo+1000<millis())
  {
    resultado=resultado*-1;
  }
  
  if (resultado==-1)
    {
      digitalWrite(pinled5,HIGH);  
    } else
    {
      digitalWrite(pinled5,LOW);
    }
    
  
}
