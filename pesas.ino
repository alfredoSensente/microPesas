#define luz_juez1_ok 2
#define luz_juez1_no 3
#define luz_juez2_ok 4
#define luz_juez2_no 5
#define luz_juez3_ok 6
#define luz_juez3_no 7

#define btn_juez1_ok 8
#define btn_juez1_no 9
#define btn_juez2_ok 10
#define btn_juez2_no 11
#define btn_juez3_ok 12
#define btn_juez3_no 15

#define chicharra 16

int val1_ok = 0, val1_no = 0,val2_ok = 0, val2_no = 0,val3_ok = 0, val3_no = 0; //val se emplea para almacenar el estado del boton
bool state1_ok= false, state1_no = false, state2_ok =false, state2_no = false, state3_ok = false, state3_no = false; // 0 LED apagado, mientras que 1 encendido
int old_val1_ok = 0, old_val1_no = 0, old_val2_ok = 0, old_val2_no = 0, old_val3_ok = 0, old_val3_no = 0; // almacena el antiguo valor de val
void setup() {
  // put your setup code here, to run once:
  pinMode(luz_juez1_ok,OUTPUT);
  pinMode(luz_juez1_no,OUTPUT);
  pinMode(btn_juez1_ok,INPUT);
  pinMode(btn_juez1_no,INPUT);

  pinMode(luz_juez2_ok,OUTPUT);
  pinMode(luz_juez2_no,OUTPUT);
  pinMode(btn_juez2_ok,INPUT);
  pinMode(btn_juez2_no,INPUT);

  pinMode(luz_juez3_ok,OUTPUT);
  pinMode(luz_juez3_no,OUTPUT);
  pinMode(btn_juez3_ok,INPUT);
  pinMode(btn_juez3_no,INPUT);
  Serial.begin(9600);
}

void loop() {
    //Primer Juez
    //Boton OK
    val1_ok = digitalRead(btn_juez1_ok);
    if ((val1_ok==HIGH && old_val1_ok==0) || (val1_ok==LOW && old_val1_ok==1))//
    {
      Serial.println("valor:");
      Serial.println(val1_ok);
      Serial.println("old val:");
      Serial.println(old_val1_ok);
      antirebote(val1_ok,old_val1_ok,state1_ok); 
      old_val1_ok = val1_ok;
      encenderLed(state1_ok,luz_juez1_ok);
      apagarOtro(luz_juez1_no,state1_no,val1_no,old_val1_no); 
    }
    //Boton NO
    val1_no = digitalRead(btn_juez1_no);
    if ((val1_no==HIGH && old_val1_no==0) || (val1_no==LOW && old_val1_no==1))//
    {
      Serial.println("valor_no:");
      Serial.println(val1_no);
      Serial.println("old val_no:");
      Serial.println(old_val1_no);
      antirebote(val1_no,old_val1_no,state1_no); 
      old_val1_no = val1_no;
      encenderLed(state1_no,luz_juez1_no);
      apagarOtro(luz_juez1_ok,state1_ok,val1_ok,old_val1_ok);  
    }
}

int antirebote(int valor, int old_valor, bool &estado){
  if (valor==HIGH && old_valor==LOW)
  {
    estado=1-estado;
    delay(500);
  }
  
}
int encenderLed(bool estado, int led){
  if (estado==true)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}

int apagarOtro(int led,bool &estado, int &valor, int &oldvalor){
  digitalWrite(led,LOW);
  estado=false;
  valor=0;
  oldvalor=0;
}
