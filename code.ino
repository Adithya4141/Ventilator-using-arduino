#include <Servo.h>

#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <Wire.h> 
// Set the LCD address to 0x27 for a 16 chars and 2 line display
#define dht_pin A0  
LiquidCrystal_I2C lcd(0x27,16,2);
dht DHT; // create servo object to control a servo
int potpin = 3;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
float pos = 0;
int a;
int b;
int c=5;
int enA = 8;
int in1 =9;
int in2 =10;
int enB = 3;
int in3 = 5;
int in4 = 4;
void setup() {
 pinMode(enB, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 
 // Turn off motors - Initial state
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
  lcd.init();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("Emergency Vent"); // prints 16x2 LCD MODULE159*                         
  lcd.setCursor(2,1);           //sets the cursor at row 1 column 2
  lcd.print("Welcome to GMRIT");
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  Serial.print("Initializing pulse oximeter..");
    lcd.clear();
  Serial.begin(9600);

  // Turn on the blacklight and print a message.
delay(4000);
}

void loop() {
  int potpin= analogRead(A3); 
  analogWrite(enB, 255);
  analogWrite(enA, 150);
  
   DHT.read11(dht_pin);
   a=random(72,83);
   b=random(95,100);
 
  Serial.println("Spd:Fast Ang:180   ");

  Serial.print("temperature :");
  Serial.println(DHT.temperature);
  Serial.print("Heart rate:");
  Serial.print(a);
  Serial.print("bpm / SpO2:");
  Serial.print(b);
  Serial.println("%");
   lcd.setCursor(0,0);            //sets the cursor at row 0 column 0
  lcd.print("heart rate");
  lcd.setCursor(14,0);           //sets the cursor at row 0 column 0
  lcd.print(a);
  // prints 16x2 LCD MODULE 
  lcd.setCursor(7,1);                   //sets the cursor at row 1 column 2
lcd.print("temp:");
lcd.setCursor(13,1);           //sets the cursor at row 1 column 2
lcd.print(DHT.temperature);
if (potpin<60){
  lcd.setCursor(0,1);                   //sets the cursor at row 1 column 2
lcd.print("child");
  digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 delay(500);
  digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(300);
 
}
if (100<potpin){
   lcd.setCursor(0,1);                   //sets the cursor at row 1 column 2
lcd.print("adult");
  digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 delay(750);
  digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(450);
 
}
if (c%5==0){
   digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 delay(100);
 Serial.println(c);
  
}
c=c+1;

 


}
