**Nina Eye Animation System – README**



**Overview**



This project implements Nino-style eye animation logic on Nina hardware using an ESP8266 (NodeMCU) and a 1.8" ST7735 TFT display.

The animation reproduces Nino’s characteristic eye behavior, including shutter-based blinking, smooth opening, and masked gaze transitions.



**Hardware Requirements**



* ESP8266 NodeMCU



* 1.8" SPI TFT Display (ST7735)



* USB cable



* Arduino IDE



* Hardware Connections



Ensure that Nina’s ESP8266 is wired to the ST7735 display exactly as shown below:



**ST7735 Pin**      	**NodeMCU Pin**	   **GPIO**	        **Function**

VCC	                   3V3	            —	        Power

GND	                   GND	            —	        Ground

CS	                   D8	         GPIO 15	Chip Select

RESET	                   D0	         GPIO 16 	Reset

A0 (DC)   	           D4	         GPIO 2	        Data / Command

SDA (MOSI)                 D7	         GPIO 13	SPI Data

SCK	                   D5	         GPIO 14	SPI Clock

LED	                   3V3	           —	        Backlight



**Software Requirements**



* Arduino IDE



* TFT\_eSPI library



**Software Configuration**

**Step 1:** Install Arduino IDE



Download and install Arduino IDE from the official Arduino website.



**Step 2:** Install TFT\_eSPI Library



Open Arduino IDE



**Go to Sketch → Include Library → Manage Libraries**



Search for TFT\_eSPI



Install the library by Bodmer



**Step 3:** Configure User\_Setup.h



The TFT\_eSPI library requires manual configuration.



Navigate to the following path on your system:



Arduino\\libraries\\TFT\_eSPI\\





Locate the file:



User\_Setup.h





Replace or modify User\_Setup.h using the provided User\_Setup.h file configured for:



* ST7735 driver



* ESP8266 (NodeMCU)



Pin mappings exactly as listed in the hardware table



⚠️ This step is mandatory.

The code will not work correctly without proper User\_Setup.h configuration.



**Step 4:** Open the Source Code



Open Arduino IDE



Create a new sketch



Paste the provided C++ source code into the editor



**Step 5:** Board and Port Selection



Go to Tools → Board



Select NodeMCU 1.0 (ESP-12E Module)



Go to Tools → Port



Select the correct COM port for your ESP8266



**Step 6:** Upload the Code



Click Upload



Wait for compilation and flashing to complete



The display should start showing the eye animation automatically



**Eye Animation Logic (Nino Replica)**



The animation logic on Nina is a direct behavioral replica of Nino’s eye system.



**Bottom-to-Top Shutter Close**



The eye closes by lifting a shutter upward



Simulates a mechanical shutter concealing the pupil



**Diameter-Out Open**



The eye opens from the center outward



Creates a smooth and natural reveal motion



**Teleport Transition Masking**



During gaze changes (Center ↔ Left ↔ Right):



* Eye fully closes



* Screen remains white for 500 ms



This hides discrete jumps and creates an illusion of continuous motion



**Display Orientation**



The code is optimized for horizontal (landscape) orientation



Resolution: 160 × 128



**Notes**



Ensure power stability to avoid display flicker



Do not modify SPI pins unless you update User\_Setup.h



Animation timings can be adjusted inside the source code if required



**Result**



After successful upload:



The eye will blink smoothly



Gaze will shift between center, left, and right



Transitions will appear continuous and mechanical, matching Nino’s visual behavior

