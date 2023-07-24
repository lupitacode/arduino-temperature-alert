/*codigo del termometro digital*/
#include <LiquidCrystal.h> //Librería del LCD 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pines del LCD(RS, Enable, D4, D5, D6, D7) 
int lm35 = A0; // Entrada analógica A0 para leer sensor 
float temp=0; 
char grados = '°C';
int ledPin=13;
int buzzer=10;                                                                                             
byte grado[8] =
{
0b00001100, // Los definimos como binarios 0bxxxxxxx
0b00010010,
0b00010010,
0b00001100,
0b00000000,
0b00000000,
0b00000000,
0b00000000
};

void setup() {
 
  lcd.setCursor(2, 1);
  //Escribir un mensaje
  lcd.print("BIENVENIDOS!");
  delay(2000);
  //Borrar la pantalla
  lcd.clear();
  lcd.print("ING.SISTEMAS 4 B");
  delay(2000);
  //Borrar la pantalla
  lcd.clear();
  lcd.createChar(1, grado);
  lcd.begin(16, 2); //tipo de lcd que es de 2*16 x*y
   
 pinMode(ledPin, OUTPUT);/*pinMode (pin,modo) configura el pin como salida*/
 pinMode(buzzer, OUTPUT);

 

}

void loop() {
  temp=analogRead(lm35); // lectura del sensor 
  temp=(500.0 * temp)/1023; // conversion de la lectura 

if(temp > 30.0){
  
digitalWrite (ledPin, HIGH);//envia un valor al pin 13 ya se alto que es 5v o bajo que es 0v
tone (buzzer,440);
delay (500);
tone (buzzer,250);
lcd.setCursor(0,0); 

lcd.print("TEMPERATURA ALTA");
lcd.setCursor(0,1);
lcd.print(temp);

lcd.setCursor(6,1);
lcd.write(1);
lcd.print(grados); 
}else{
  
  if(temp < 30.0){


lcd.setCursor(2,0); 
lcd.print("TEMPERATURA");
lcd.setCursor(0,1);
lcd.print(temp);
lcd.setCursor(6,1);
lcd.write(1);
lcd.print(grados); 

  }

} 

digitalWrite (ledPin, LOW);
 noTone (buzzer);
 
delay(1000); // pausa de de 1 segundo para la siguiente lectura 



}
