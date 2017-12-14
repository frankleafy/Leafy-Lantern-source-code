#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ESP32WebServer.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <Preferences.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <strings.h>
#include "leafy.h"

/*fill your ssid and password here */
String ssid = "";
String password = "";
int led = 2;


Preferences preferences;
ESP32WebServer server ( 80 );

String Argument_Name;


void handleRoot() 
{
  //clearSettings();
  String defaultIp ="192.168.4.1";
  if(!WiFi.localIP())
  {
    server.send ( 200, "text/html", loadHomePage() );
  }
  else
  {

    //connected to wifi
    //("access-control-allow-origin", "*")
    server.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
    
   server.sendHeader("Access-Control-Allow-Origin", "*");

    server.send ( 200, "text/html", loadDemo() );//loadDashboard()
  }
  Serial.print(server.args()); // Display the argument
  getQueryString();
 
}
const int analogPin = 33;
void getTemp()
{ 
  int  sensorValue = 500;//analogRead(analogPin);
  server.send ( 200, "text/plain", String(sensorValue) );//loadDashboard()
}

void getManifest()
{
  String manifest = "CACHE MANIFEST \n \
NETWORK: \n \
*";
  server.send ( 200, "text/plain", manifest );//loadDashboard()
}

void handleTime()
{
  char DateAndTimeString[20];
  sprintf(DateAndTimeString, "%4d-%02d-%02d %d:%02d:%02d", year(), month(), day(), hour(), minute(), second());
  server.send ( 200, "text/html",DateAndTimeString  );
}

void handleReset()
{
  clearSettings();
  server.send ( 200, "text/html", "Settings reset");
}

void handleNotFound() 
{
  server.send ( 404, "text/plain", load404(server) );
}

void createRequest()
{
    String message = "started";
    WiFiClientSecure client;
    const int httpPort = 443;
    const char* host = "www.google.com";
          String reply = "";
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
         server.send ( 200, "text/html", "connection failed" );
        return;
    }
    else
    {

      String url = "/search?q=esp32";

          client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                  "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.13+ (KHTML, like Gecko) Version/5.1.7 Safari/534.57.2\r\n" +
                 "Connection: close\r\n\r\n");
                  unsigned long timeout = millis();
                  while (client.available() == 0) 
                  {
                      if (millis() - timeout > 5000) 
                      {
                          Serial.println(">>> Client Timeout !");
                          client.stop();
                          return;
                      }
                  }

                  // Read all the lines of the reply from server and print them to Serial
                  while(client.available()) 
                  {
                      String line = client.readStringUntil('\r');
                      Serial.print(line);
                      reply +=  line;
                  }

              Serial.println();
              Serial.println("closing connection");
    }

    server.send ( 200, "text/html", reply );
}

void setup ( void ) 
{
  pinMode ( led, OUTPUT );
  digitalWrite ( led, 0 );
  Serial.begin ( 9600 );
  
  getSettings();
  if(ssid == "none" || password == "none")
  {
    startAccessPoint();
    //instellen tijd handmatig
    
  }
  else
  {
    connectToWifi();
    getAndSetTime();
  }
  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );



  server.on ("/", handleRoot);
  server.on ("/reset" ,handleReset);
  server.on ("/time", handleTime);
  server.on ("/request", createRequest);
  server.on ("/timer", startTimer);
  server.on ("/step",  rotateplants);
  server.on ("/getTemp",  getTemp);
  server.on ("/manifest", getManifest);
  server.on ( "/inline", []() { server.send ( 200, "text/plain", "this works as well" ); } );
  server.onNotFound ( handleNotFound );
  server.begin();
  Serial.println ( "HTTP server started" );
}




void loop ( void ) 
{
  server.handleClient();
}




