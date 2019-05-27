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
int contOk=0, contNo=0;
bool voto1=false,voto2=false,voto3=false;
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
  //////////////////////////////////////////////////////////////////Primer Juez
    //Boton OK
    val1_ok = digitalRead(btn_juez1_ok);
    if ((val1_ok==HIGH && old_val1_ok==0) || (val1_ok==LOW && old_val1_ok==1))
    {
      antirebote(val1_ok,old_val1_ok,state1_ok); 
      old_val1_ok = val1_ok;
      encenderLed(state1_ok,luz_juez1_ok,luz_juez1_no);
      votar(state1_ok,voto1); 
    }
    //Boton NO
    val1_no = digitalRead(btn_juez1_no);
    if ((val1_no==HIGH && old_val1_no==0) || (val1_no==LOW && old_val1_no==1))
    {
      antirebote(val1_no,old_val1_no,state1_no); 
      old_val1_no = val1_no;
      encenderLed(state1_no,luz_juez1_no,luz_juez1_ok);
      votar(state1_no,voto1); 
    }
    
  //////////////////////////////////////////////////////////////////Segundo Juez
    //Boton OK
    val2_ok = digitalRead(btn_juez2_ok);
    if ((val2_ok==HIGH && old_val2_ok==0) || (val2_ok==LOW && old_val2_ok==1))
    {
      antirebote(val2_ok,old_val2_ok,state2_ok); 
      old_val2_ok = val2_ok;
      encenderLed(state2_ok,luz_juez2_ok,luz_juez2_no);
      votar(state2_ok,voto2); 
    }
    //Boton NO
    val2_no = digitalRead(btn_juez2_no);
    if ((val2_no==HIGH && old_val2_no==0) || (val2_no==LOW && old_val2_no==1))
    {
      antirebote(val2_no,old_val2_no,state2_no); 
      old_val2_no = val2_no;
      encenderLed(state2_no,luz_juez2_no,luz_juez2_ok);  
      votar(state2_no,voto2); 
    }

  ////////////////////////////////////////////////////////////////////Tercer Juez
    //Boton OK
    val3_ok = digitalRead(btn_juez3_ok);
    if ((val3_ok==HIGH && old_val3_ok==0) || (val3_ok==LOW && old_val3_ok==1))
    {
      antirebote(val3_ok,old_val3_ok,state3_ok); 
      old_val3_ok = val3_ok;
      encenderLed(state3_ok,luz_juez3_ok,luz_juez3_no);
      votar(state3_ok,voto3); 
    }
}

int antirebote(int valor, int old_valor, bool &estado){
  if (valor==HIGH && old_valor==LOW)
  {
    estado=1-estado;
    delay(500);
  }
  
}

int encenderLed(bool estado, int led, int otroLed){
  if (estado==true && digitalRead(otroLed)==LOW)
  {
    digitalWrite(led,HIGH);
  }
}

int apagarOtro(int led,bool &estado, int &valor, int &oldvalor){
  digitalWrite(led,LOW);
  estado=false;
  valor=0;
  oldvalor=0;
}

int votar(bool &estado,bool &voto){
  if (voto==false)
  {
    if (estado==true)
    {
      voto=true;
      if (voto1==true && voto2==true && voto3==true)
      {
        Serial.println("La chicharra suena");
        delay(5000);
        Serial.println("La chicharra se apaga");
        voto1=false;
        voto2=false;
        voto3=false;
        apagarOtro(luz_juez1_ok,state1_ok,val1_ok,old_val1_ok);
        apagarOtro(luz_juez2_ok,state2_ok,val2_ok,old_val2_ok);
        apagarOtro(luz_juez3_ok,state3_ok,val3_ok,old_val3_ok);
        apagarOtro(luz_juez1_no,state1_no,val1_no,old_val1_no);
        apagarOtro(luz_juez2_no,state2_no,val2_no,old_val2_no);
        apagarOtro(luz_juez3_no,state3_no,val3_no,old_val3_no);
      }
    }
  }
}