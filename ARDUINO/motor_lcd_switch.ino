#include<LiquidCrystal.h>
int d7=0,d6=1,d5=2,d4=3,en=4,rs=5,count=0,flag=0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 
 
void setup() {
  lcd.begin(16,2);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
}

void loop() {
if(digitalRead(10)==0&&digitalRead(11)==1&&flag==0){
  int i;
 flag++;
  for(i=6;i<=9;i++)
  {
    if(i%2!=0){
  digitalWrite(i,0);}
  else digitalWrite(i,1);
  }
  lcd.setCursor(0,0);
  lcd.println("REVERSE");
  lcd.setCursor(0,1);
  lcd.println("REVERSE");
  
  }
else if(digitalRead(11)==0&&digitalRead(10)==1&&count==0){
  int i;
  count++;
  for(i=6;i<=9;i++)
  {
    if(i%2!=0){
  digitalWrite(i,1);}
  else digitalWrite(i,0);
  lcd.setCursor(0,0);
  lcd.println("FORWARD");
  lcd.setCursor(0,1);
  lcd.println("FORWARD");
  
  }
}
else if(digitalRead(11)==0&&digitalRead(10)==0&&flag!=0&&count!=0){
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(7,1);
  digitalWrite(6,0);
  lcd.setCursor(0,0);
  lcd.println("FORWARD");
  lcd.setCursor(0,1);
  lcd.println("REVERSE");
  
  count=0;
}
else if(digitalRead(11)==1&&digitalRead(10)==1&&flag!=0&&count!=0){
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(7,0);
  digitalWrite(6,1);
  lcd.setCursor(0,1);
  lcd.println("FORWARD");
  lcd.setCursor(0,0);
  lcd.println("REVERSE");
  flag=0;
  
}
}
