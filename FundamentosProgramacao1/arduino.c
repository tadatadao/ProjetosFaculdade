int Sensor = A0;
float valorLuz = 0;
int pushbutton = A1;
float button_value;
float tara = 0;
float divisao_tara = 20;
float verde;
float amarelo_3;
float amarelo_2;
float amarelo_1;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(Sensor,INPUT);
  // abre a porta serial a 5000 bps:
  Serial.begin(5000);
}//setup

void loop()
{
  valorLuz = analogRead(Sensor);
  /*Serial.println(valorLuz);*/

  button_value = analogRead(pushbutton);
  /*Serial.println(button_value);*/

  valorLuz = (valorLuz - 6) / 6.73;
  /*converte em escala de 0 a 100*/

if(button_value > 0){
  tara = 100 - analogRead(Sensor);
  divisao_tara = tara / 5;
}//if buttun pull down

  verde = tara + divisao_tara;
  amarelo_3 = tara + 2 * divisao_tara;
  amarelo_2 = tara + 3 * divisao_tara;
  amarelo_1 = tara + 4 * divisao_tara;

  if(valorLuz >= tara && valorLuz <= verde){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }//verde
  else if(valorLuz > verde && valorLuz <= amarelo_3){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }//amarelo 3
  else if(valorLuz > amarelo_3 && valorLuz <= amarelo_2){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }//amarelo 2
  else if(valorLuz > amarelo_2 && valorLuz <= amarelo_1){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }//amarelo 1
  else if(valorLuz > amarelo_1 && valorLuz <= 100){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }//vermelho

}//loop
