

 

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6, 7, 8);
const int sensor= 0 ;
float sensabiliter =185; 
float somme =0;
float readvaleur;
float A;
float Energie[3]; 
float E[3];

void setup(){
  lcd.init();
 lcd.backlight(); 
 lcd.begin(16,2);
 Serial.begin(9600);
 myRTC.setDS1302Time(0, 22, 21, 7, 11, 6, 2021); 
 pinMode(sensor,INPUT);
 

}
void loop(){
float i = myRTC.seconds ;
float j = myRTC.seconds ;
 for(int i=0; i<3;i++){
    float voltage = analogRead(sensor);
    float courant= ((voltage*5.0/1023))/185;
    E[i]=courant ;
    delay(1000);
    Serial.println("le courant est " );
    Serial.println(E[i]);
     
    }
 for (int j=0;j<3;j++){
     Energie[j] =  E[j] *220  ;
  
    Serial.println("l'energie consommer en seconde est ");
    Serial.println(Energie[j]);
  
   }
    
 for (int k=0;k<3;k++){
    somme+=Energie[k]/3;
    
   }
   
   Serial.println("la consomation du maison par heure est:");
   Serial.println(somme);
   Serial.println("KWh");
   lcd.setCursor(0,0);
   lcd.print("consomation KWh:");
   lcd.setCursor(0,1);
   lcd.print(somme);}
    
   
  
