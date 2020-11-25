/*
  Código desenvolvido por Lílian Teixeira, para o projeto ForGirls. 
 */
 
// incluir biblioteca
#include <LiquidCrystal.h>

//Declaramos as variaveis necessarias
int numero=0;
int auxnumero=0;
int sensorPinLDR = A0;
int valorLDR = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Declaramos os pinos que usa nosso LCD(RS,E,D4D5,D6,D7)

void setup() {
  
  lcd.begin(16, 2);//Iniciamos a tela a informamos o numero de caracteres e linhas
  
  lcd.setCursor(5, 0);//Situamos o lugar onde vai começar a escrita
  lcd.print("ForGirls");//Escrevemos ForGirls
  delay (2000);//Esperamos dois segundos
  lcd.clear();//Limpamos a tela
  lcd.setCursor(0, 0);
  lcd.print("Engenharia");
  delay (2000);
  lcd.setCursor(5, 1);
  lcd.print("Acessível");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Contador com");
  delay (2000);
  lcd.setCursor(3, 1);
  lcd.print("Barreira Laser");
  delay (3000);
  lcd.clear();
  
  
}

void loop() {
  
  valorLDR = analogRead(sensorPinLDR);// Lemos o valor do LDR e o guardamos na variavel valorLDR
  lcd.setCursor(0, 0);//Situamos o lugar onde escreveremos
  lcd.print("CONTADOR");//Escrevemos contador
  lcd.setCursor(10, 1);
  lcd.print(numero);//Apresentamos a variavel numero
  
  auxnumero=0;//A variavel auxnumero nos ajuda a contar 1 cada vez que entremos no loop abaixo
  
  while(valorLDR<600){//Entramos no loop se valorLDR é menor que 600. Isto ocorre quando o laser não incide sobre o LDR.
    valorLDR = analogRead(sensorPinLDR);// Lemos o valor do LDR e o guardamos em valorLDR
    if(auxnumero==0){// Entramos no if se auxnumero é 0. Isto so ocorre a primera vez que passamos pelo while.
    numero++;//Somamos 1 a variavel numero
    auxnumero=1;//Colocamos auxnumero=1, para que so some uma vez o numero 1, a variavel numero quando estamos dentro do while.
      }
    }  
}
