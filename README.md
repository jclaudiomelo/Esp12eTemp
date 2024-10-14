# Projeto ESP8266 com Sensor DHT11 e Display OLED

Este projeto utiliza um ESP8266 para ler a temperatura e umidade de um sensor DHT11 e exibi-los em um display OLED 0.96". Além disso, uma API RESTful é criada para permitir a consulta dos dados via web.

## Requisitos

Criar um arquivo COnfig.h
#ifndef CONFIG_H
#define CONFIG_H

const char *ssid = " Coloque seu SSID"; 
const char *password = "Coloque sua senha WiFi";   

#endif

http://<IP_DO_DISPOSITIVO>/dados
{
  "temperatura": 25.0,
  "umidade": 60.0
}
![image](https://github.com/user-attachments/assets/6b78f112-34ff-49da-92d8-4de1d9c1da5a)
![image](https://github.com/user-attachments/assets/6f67910f-7e63-4b30-bd9e-246dc0d119a3)
