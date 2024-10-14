#ifndef NETWORK_H
#define NETWORK_H
#include <SensorConfig.h>
#include <DisplayConfig.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include "config.h"


ESP8266WebServer server(80); // Servidor HTTP na porta 80

// Função para lidar com a requisição de dados
void handleData()
{
    // Cria a resposta JSON com os dados do sensor
    String response = "{";
    response += "\"temperatura\": " + String(readTemperature(), 2) + ","; // 2 casas decimais
    response += "\"umidade\": " + String(readHumidity(), 2);
    response += "}";

    // Envia a resposta
    server.send(200, "application/json", response);
}

void ConectaWifi()
{
    // Conecta-se ao WiFi
    WiFi.begin(ssid, password);
    Serial.print("Conectando ao WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    // Exibe no display o IP e que o WiFi está conectado
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("WiFi conectado");
    display.setCursor(0, 10);
    display.print("IP:");
    display.setCursor(0, 20);
    display.print(WiFi.localIP());
    display.display();
    delay(5000); // Aguarda 5 segundos antes de continuar

    // Define a rota para a API de temperatura/umidade
    server.on("/api/dados", handleData);

    // Inicia o servidor
    server.begin();
    Serial.println("Servidor HTTP iniciado.");
}
#endif
