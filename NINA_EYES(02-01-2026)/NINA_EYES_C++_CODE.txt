#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite eye = TFT_eSprite(&tft);

#define ORIENTATION_MODE 1 // 1 = Horizontal (Landscape 160x128)

int SCREEN_W, SCREEN_H;
int cx, cy;
int maxRadius = 40;

void setup() {
  tft.init();
  tft.setRotation(1);

  SCREEN_W = tft.width();
  SCREEN_H = tft.height();
  cx = SCREEN_W / 2;
  cy = SCREEN_H / 2;

  tft.fillScreen(TFT_WHITE);
  eye.createSprite(SCREEN_W, SCREEN_H);
}

void renderShutterClose(int shutterY, int lookX) {
  eye.fillSprite(TFT_WHITE);
  eye.fillEllipse(cx + lookX, cy, maxRadius, maxRadius, TFT_BLACK);
  eye.fillRect(0, cy + maxRadius - shutterY, SCREEN_W, SCREEN_H, TFT_WHITE);
  eye.pushSprite(0, 0);
}

void renderDiameterOpen(int openDist, int lookX) {
  eye.fillSprite(TFT_WHITE);
  eye.fillEllipse(cx + lookX, cy, maxRadius, maxRadius, TFT_BLACK);
  eye.fillRect(0, 0, SCREEN_W, cy - openDist, TFT_WHITE);
  eye.fillRect(0, cy + openDist, SCREEN_W, SCREEN_H, TFT_WHITE);
  eye.pushSprite(0, 0);
}

void ninoMagicMove(int currentX, int nextX) {
  renderDiameterOpen(maxRadius, currentX);
  delay(1800);

  for (int s = 0; s <= maxRadius * 2; s += 5) {
    renderShutterClose(s, currentX);
    delay(12);
  }

  eye.fillSprite(TFT_WHITE);
  eye.pushSprite(0, 0);
  delay(500);

  for (int d = 0; d <= maxRadius; d += 2) {
    renderDiameterOpen(d, nextX);
    delay(18);
  }
}

void loop() {
  int lookDist = 35;
  ninoMagicMove(0, lookDist);  
  ninoMagicMove(lookDist, 0);  
  ninoMagicMove(0, -lookDist);  
  ninoMagicMove(-lookDist, 0);  
}
