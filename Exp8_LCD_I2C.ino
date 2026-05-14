#include <LCD-I2C.h>

LCD_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.begin();
    lcd.backlight();
}

void loop()
{
    lcd.print("PARUL UNIVERSITY");
    lcd.setCursor(5, 1);
    lcd.print("NAC A++");

    delay(1000);

    for (int i = 0; i < 5; i++)
    {
        lcd.backlight();
        delay(50);

        lcd.noBacklight();
        delay(50);
    }

    lcd.backlight();
    lcd.clear();

    delay(500);
}
