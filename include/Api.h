#ifndef API_H
#define API_H
#include <Sensor.h>
#include <DisplayConfig.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

const char *ssid = "Rede_Oculta-srv"; // Coloque seu SSID
const char *password = "000000000";   // Coloque sua senha WiFi

ESP8266WebServer server(80);
void handleData()
{
    // Cria a resposta JSON
    String response = "{";
    response += "\"temperatura\": " + String(readTemperature()) + ",";
    response += "\"umidade\": " + String(readHumidity());
    response += "}";

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
    // display.clearDisplay();
    // display.setTextSize(1);
    // display.setCursor(0, 0);
    // display.print("WiFi conectado");
    // display.setCursor(0, 10);
    // display.print("IP:");
    // display.setCursor(0, 20);
    // display.print(WiFi.localIP());
    // display.display();
    // delay(5000); // Aguarda 5 segundos antes de continuar

    // Define a rota para a API de temperatura/umidade
    server.on("/dados", handleData);

    // Inicia o servidor
    server.begin();
    Serial.println("Servidor HTTP iniciado.");
}

#endif
