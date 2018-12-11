# sk8bms
### Skate board (electric) Battery Management System
copyright: Micah Martin / Airworthy, LLC 2018

### Development 

Uses platformio.

Shell commands located in the arduino/bin directory simply tasks 

After the first compile fails (missing SHI.h file) edit .piolibdeps/ssd1306_ID1904/src/ssd1306_hal/UserSettings.h.  Comment out the line:

    #define CONFIG_PLATFORM_SPI_ENABLE
    
### Features

 * Sense battery voltages
 * Balance cells (passive, active is feasible)
 * Measure load current
 * Measure charge current
 * Sense pack temperature
 * State of charge
 * Overvoltage protection
    * charge voltage too high
 * Undervoltage protection 
    * when cells reach min voltage (drained)
    * tolerates temporary voltage dip on high loads
 * Overcurrent protection
    * draw too much current
 * Overcharge protection
    * charge doesn't stop on time
 * Overheat protection    
      
    