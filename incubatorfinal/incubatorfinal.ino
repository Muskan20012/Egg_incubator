#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(5000);
    return;
  }
  

    lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("temperature: "); lcd.print((int)temperature);
   lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("humidity: ");
  lcd.print((int)humidity);
  lcd.print("%");
  delay(5000);

 if(temperature>37)
 {
  digitalWrite(13, HIGH);
 }
else
{
   digitalWrite(13, LOW);
}

if(humidity<60)
 {
   digitalWrite(9, HIGH);
 }
else
{
 digitalWrite(9, LOW);
}





  
}
