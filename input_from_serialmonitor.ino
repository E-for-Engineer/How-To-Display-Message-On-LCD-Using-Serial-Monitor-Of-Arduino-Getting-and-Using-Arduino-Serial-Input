#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Enter your name.");
  lcd.setCursor(0,0);
  lcd.print("Enter Your Name");
  }

char rx_byte = 0;
String rx_str = "";

void loop() {
  if (Serial.available() > 0) {    
    rx_byte = Serial.read();       
    
    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.println(rx_str);
      lcd.setCursor(0,1);
      lcd.print(rx_str);
      rx_str = "";                
      Serial.println("");
      Serial.println("Enter your name.");
    }
  }  
}
