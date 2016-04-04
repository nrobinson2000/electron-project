#include "application.h"
#include "LiquidCrystal.h"

// Make sure to update these to match how you've wired your pins.
// pinout on LCD [RS, EN, D4, D5, D6, D7];
// pin nums LCD  [ 4,  6, 11, 12, 13, 14];
// Shield Shield [RS, EN, D4, D5, D6, D7];
// Spark Core    [D3, D5, D2, D4, D7, D8];
LiquidCrystal lcd(D0, D1, C3, C2, C1, C0);

int printHandler(String args)
{
lcd.clear();
 lcd.setCursor(0, 0);
for (unsigned int i = 0; i < args.length(); i++)
{
  if (i >= 16)
  {
  lcd.setCursor(i - 16 ,1);
  lcd.print(args.charAt(i));
  }
  else
  {
    lcd.setCursor(i, 0);
    lcd.print(args.charAt(i));
  }
}

return 1;
}

void setup()
{
Particle.function("print", printHandler);
lcd.begin(16,2);

}

void loop()
{

}
