#ifndef SENSOR_CONFIG_H
#define SENSOR_CONFIG_H

#include <DHT.h>

// Definições do sensor DHT
#define DHTPIN D4     // Pino conectado ao DHT11
#define DHTTYPE DHT11 // Definindo o tipo do sensor (DHT11)

DHT dht(DHTPIN, DHTTYPE);

void setupSensor() {
  // Inicializando o sensor DHT
  dht.begin();
}

float readHumidity() {
  return dht.readHumidity();
}

float readTemperature() {
  return dht.readTemperature();
}

#endif
