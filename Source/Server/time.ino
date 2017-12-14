

#include <WiFiUdp.h>


unsigned int localPort = 2390;      // local port to listen for UDP packets
IPAddress timeServerIP;
const char* ntpServerName = "nl.pool.ntp.org";
const int NTP_PACKET_SIZE = 48;
byte packetBuffer[ NTP_PACKET_SIZE];
WiFiUDP udp;

String getTimeString()
{
  displayCurrentTime();
  String Time =  String(hour()) + ":" + String(minute());
  Serial.println("Time:"+Time);
  return Time;
}

void displayCurrentTime() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.println();
}

void getAndSetTime()
{
  udp.begin(localPort);
  WiFi.hostByName(ntpServerName, timeServerIP); 

  sendNTPpacket(timeServerIP);
  delay(10000);
  
  int cb = udp.parsePacket();
  if (!cb) {
    delay(1);
  }
  else {
    udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears;
    Serial.print("UNX");
    Serial.println(epoch);
     setTime(epoch);  
     adjustTime(60*60*1);
     displayCurrentTime();
  }
 // Serial.println(epoch);
//  delay(10000);
}

unsigned long sendNTPpacket(IPAddress& address)
{
  Serial.println("sending NTP packet...");
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
  udp.beginPacket(address, 123);
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}
