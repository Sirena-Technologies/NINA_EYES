// =======================================================
// User_Setup.h for NodeMCU ESP8266 + ST7735 1.8" 128x160
// Wiring:
// SCK  -> D5
// MOSI -> D7
// DC   -> D4
// CS   -> D8
// RST  -> D0
// BL   -> 3V3
// =======================================================

#define USER_SETUP_INFO "ESP8266_NodeMCU_ST7735_128x160"

// ---------------- DISPLAY DRIVER ----------------
#define ST7735_DRIVER

// ---------------- DISPLAY SIZE ------------------
#define TFT_WIDTH   128
#define TFT_HEIGHT  160

// ---------------- ST7735 TAB TYPE ---------------
#define ST7735_BLACKTAB

// ---------------- ESP8266 SPI PINS --------------
#define TFT_MOSI  PIN_D7   // GPIO13
#define TFT_SCLK  PIN_D5   // GPIO14

#define TFT_CS    PIN_D8   // GPIO15
#define TFT_DC    PIN_D4   // GPIO2
#define TFT_RST   PIN_D0   // GPIO16

// ---------------- SPI SPEED ---------------------
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000

// ---------------- FONTS -------------------------
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

// ---------------- END OF FILE -------------------
