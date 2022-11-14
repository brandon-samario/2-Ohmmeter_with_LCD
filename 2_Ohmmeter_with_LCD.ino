/*
  The purpose of this program  is to further understand how an lcd works, and use it to display resistance such as a ohmmeter.
  Using a seperate resistance than the known resistor (3.3k),
  this program provides the ability to read the resitance value of the unknown resistor using the anolog input pin (A0).
  Thus, it uses the coversion formula for resistance, converting the analog value (analogread (A0)) into a resistance value,
  which is then displayed on the lcd determining the resistance value of the unknown resistor (R2).
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // rs, e, d4, d5, d6, d7

// resistance setup
int Vin = 5; // voltage at 5V pin of arduino uno
float Vout = 0; // voltage at A0 pin of arduino uno
float R1 = 3300; // resistance value of known resistor (3.3k)
float R2 = 0; // resistance value of unknown resistor
int analogvalue = 0;
float buffer = 0;

// the setup function runs once when you press reset or power the board
void setup()
{

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("OHMMETER"); // print text on lcd

}

// the loop function runs over and over again forever
void loop()
{

  analogvalue = analogRead(A0); // read value on analog pin A0

  if (analogvalue)

  {

    buffer = analogvalue * Vin;
    Vout = (buffer) / 1024.0; //Conversion formula for resistance
    buffer = Vout / (Vin - Vout);
    R2 = R1 * buffer;

    Serial.print("R = "); // print text in serial monitor
    Serial.println(R2); // print value of resistance of unknown resistor (R2) in serial monitor

    lcd.setCursor(0, 1); // position of text on lcd (will show on 2nd colomn)
    lcd.print("Ohms = "); // print text on lcd
    lcd.print(R2); // print value of resistance of unknown resistor (R2) on lcd
    delay(300); // wait time

  }

}