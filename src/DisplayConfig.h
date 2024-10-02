#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Definições do display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Usar pino de reset (-1 se não usar)

// Definição dos pinos I2C (SDA: GPIO14, SCL: GPIO12)
#define OLED_SDA 14
#define OLED_SCL 12

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupDisplay() {
  // Inicializando os pinos I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // Inicializando o display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Endereço I2C do display OLED
    Serial.println(F("Falha ao inicializar o display SSD1306"));
    for (;;); // Para o programa em caso de falha
  }

  // Limpar o buffer do display
  display.clearDisplay();
}

#endif
