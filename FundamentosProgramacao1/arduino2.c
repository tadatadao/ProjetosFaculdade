int Sensor = A0;
float valorLuz = 0;
int pushbutton = A1;
float button_value;
float tara = 0;
float divisao_tara = 10;
float a,b,c,d,e,f,g,h,i;//auxiliares para intervalos de luminosidade

byte d7s[10][7] = {  //d7s = display de 7 segmentos

 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,1,0,1,1 },  //DIGITO 9

}//display

void setup(){

  //Definindo pinos como saída
  pinMode(2, OUTPUT);//a
  pinMode(3, OUTPUT);//b
  pinMode(4, OUTPUT);//c
  pinMode(5, OUTPUT);//d
  pinMode(6, OUTPUT);//e
  pinMode(7, OUTPUT);//f
  pinMode(8, OUTPUT);//g
  pinMode(Sensor,INPUT);//ldr

}//setup

void acender_display(int n){
    int m = 1;
    int p = 1;
    for(int j = 0; j < 7; j++){
        p++;
        if(d7s[n][m] == 1)
            digitalWrite(p,HIGH);
        else
            digitalWrite(p,LOW);
        m++;
    }//for
return;
}//ascender display

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
  divisao_tara = tara / 10;
}//if button pressed
  /*calculo dos intervalos*/
  a = tara + 1 * divisao_tara;
  b = tara + 2 * divisao_tara;
  c = tara + 3 * divisao_tara;
  d = tara + 4 * divisao_tara;
  e = tara + 5 * divisao_tara;
  f = tara + 6 * divisao_tara;
  g = tara + 7 * divisao_tara;
  h = tara + 8 * divisao_tara;
  i = tara + 9 * divisao_tara;

  if(valorLuz >= tara && valorLuz <= a)
    acender_display(1);//zero

  else if(valorLuz > a && valorLuz <= b)
    acender_display(2);//um

  else if(valorLuz > b && valorLuz <= c)
    acender_display(3);//dois

  else if(valorLuz > c && valorLuz <= d)
    acender_display(4);//tres

  else if(valorLuz > d && valorLuz <= e)
    acender_display(5);//quatro

  else if(valorLuz > e && valorLuz <= f)
    acender_display(6);//cinco

  else if(valorLuz > f && valorLuz <= g)
    acender_display(7);//seis

  else if(valorLuz > g && valorLuz <= h)
    acender_display(8);//sete

  else if(valorLuz > h && valorLuz <= i)
    acender_display(9);//oito

  else if(valorLuz > i && valorLuz <= 100)
    acender_display(10);//nove

}//loop
