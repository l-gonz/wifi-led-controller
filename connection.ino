#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "html/index.h"

WiFiServer Server(80);

void setupConnection()
{
    connect();
    
    // Server.begin();
}

void loopConnection()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("--Lost connection--");
        delay(CONNECT_PERIOD);
        return;
    }

    // WiFiClient client = Server.available();
    // if (client)
    // {
    //     readRequest(client);
    //     writeResponse(client);
    // }
}

void connect()
{
    WiFi.begin(SSID, PASSWORD);

    Serial.println();
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(CONNECT_PERIOD);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected to wifi. My address: ");
    Serial.println(WiFi.localIP());
}

// String readRequest(WiFiClient client)
// {
//     while (!client.available())
//         delay(1);

//     String request = client.readStringUntil('\r\n');
//     Serial.println(request);

//     client.flush();

//     return request;
// }

// void writeResponse(WiFiClient client)
// {
//     client.println("HTTP/1.1 200 OK");
//     client.println(MAIN_PAGE);
// }
