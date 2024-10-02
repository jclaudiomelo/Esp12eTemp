#include <Arduino.h>
#include "DisplayConfig.h"
#include "SensorConfig.h"

void setup() {
  // Inicializando o monitor serial
  Serial.begin(115200);

  // Inicializando o display e o sensor
  setupDisplay();
  setupSensor();
}

void loop() {
  // Leitura de temperatura e umidade
  float h = readHumidity();
  float t = readTemperature();

  // Verificando se houve erro ao ler o sensor
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Falha ao ler o sensor DHT!"));
    return;
  }

  // Exibindo os valores no monitor serial
  Serial.print(F("Umidade: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C"));

  // Exibindo os valores no display OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(F("Umidade: "));
  display.print(h);
  display.print(F("%"));

  display.setCursor(0, 16);
  display.print(F("Temp: "));
  display.print(t);
  display.print(F(" C"));

  display.display(); // Atualiza o display

  // Esperar 2 segundos antes da próxima leitura
  delay(2000);
}
