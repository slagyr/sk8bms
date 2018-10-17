# sk8bms
### Skate board (electric) Battery Management System
copyright: Micah Martin / Airworthy, LLC 2018

### Development 

Uses platformio.

Shell commands located in the arduino/bin directory simply tasks 

After the first compile fails (missing SHI.h file) edit .piolibdeps/ssd1306_ID1904/src/ssd1306_hal/UserSettings.h.  Comment out the line:

    #define CONFIG_PLATFORM_SPI_ENABLE
      
    