#include <ESP8266WiFi.h>

#include "html/index.h"

const char* SSID = "";
const char* PASSWORD = "";
const int CONNECT_PERIOD = 500;
const int LED_PERIOD = 1000;
const int LOOP_PERIOD = 1;

WiFiServer Server(80);
int counter = 0;
bool isLedOn = false;

void setup()
{
    Serial.begin(115200);
    connect();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("--Lost connection--");
        delay(LOOP_PERIOD);
        return;
    }

    WiFiClient client = Server.available();
    if (client)
    {
        String request = readRequest(client);
        int response = processRequest(request);
        writeResponse(client, response);
    }

    driveLED();

    delay(LOOP_PERIOD);
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

    Server.begin();
}

String readRequest(WiFiClient client)
{
    while (!client.available())
        delay(1);

    String request = client.readStringUntil('\r\n');
    Serial.println(request);

    client.flush();

    return request;
}

int processRequest(String request)
{
    // TODO Respond to the address on the http request
    return 0;
}

void writeResponse(WiFiClient client, int response)
{
    client.println("HTTP/1.1 200 OK");
    client.println(MAIN_PAGE);
}

void driveLED()
{
    if (counter >= LED_PERIOD)
    {
        counter = 0;
        if (isLedOn)
            digitalWrite(LED_BUILTIN, LOW);
        else
            digitalWrite(LED_BUILTIN, HIGH);
        isLedOn = !isLedOn;
    }
    else
        counter += LOOP_PERIOD;
}
