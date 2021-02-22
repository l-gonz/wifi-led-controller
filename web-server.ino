#include <ESP8266WebServer.h>
#include "html/webserver.h"

ESP8266WebServer server(80);

// Function handlers
void handleRoot();
void redirectHome();
void handlePalettePost();
void handleColorPost();
void handleIntensityPost();

void setupServer()
{
    registerHandlers();
    server.begin();
    Serial.println("HTTP server started");
}

void loopServer()
{
    server.handleClient();
}

void registerHandlers()
{
    server.on("/", HTTP_GET, handleRoot);
    server.on("/palette", HTTP_POST, handlePalettePost);
    server.on("/color", HTTP_POST, handleColorPost);
    server.on("/intensity", HTTP_POST, handleIntensityPost);
    server.onNotFound(redirectHome);
}

void printUri()
{
    Serial.print("Received ");
    Serial.println(server.uri());
}

void handleRoot()
{
    printUri();
    // Serve index page
    server.send(200, "text/html", FORMS);
}

void redirectHome()
{
    printUri();
    // Redirect to /
    server.sendHeader("Location", "/");
    server.send(303); 
}

void handlePalettePost()
{
    printUri();
    // Change palette according to form
    if (!server.hasArg("id") || server.arg("id") == NULL)
    {
        server.send(400, "text/plain", "Error: Invalid Request");
        return;
    }

    int id = server.arg("id").toInt();
    if (id < 0 or id > MAX_PALETTE)
    {
        server.send(400, "text/plain", "Error: Palette out of bounds");
        return;
    }

    //ledController.setPalette(id);

    redirectHome();
}

void handleColorPost()
{
    printUri();
    // Change palette according to form
    redirectHome();
}

void handleIntensityPost()
{
    printUri();
    // Change palette according to form
    redirectHome();
}
