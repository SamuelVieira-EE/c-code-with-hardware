#include <LiquidCrystal.h>

int tempPin = 0;
int buttonPin1 = 2;


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {

  lcd.begin(16, 2); 

  pinMode(buttonPin1, INPUT_PULLUP); 

}

void loop() {


  int tempReading = analogRead(tempPin);// Thermistor dosent read temperature it changes resistance based on temperature which then leads to voltage change
  //The pin A0 will read that volatge change as a number between 0-1023

  //Using the number we would have to calculate temperature using The Steinhart-Hart equation (converts thermistors voltage reading into actual temperature)
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );//temp kelvin


  float tempC = tempK - 273.15;//temp celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; //temp fahrenheit
  
  int currentButtonState = digitalRead(buttonPin1);  //button high or low

  lcd.setCursor(0, 0);
  if (currentButtonState == LOW) { //if button pressed show fahrenheit if not show celcius
    lcd.print("Temp:" + String(tempF, 2) + " F   ");
    delay(500);
  } else {
    lcd.print("Temp:" + String(tempC, 2) + " C   ");
  }



  delay(500);
}
