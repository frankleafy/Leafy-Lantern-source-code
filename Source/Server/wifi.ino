void startAccessPoint()
{
      //start access point
    WiFi.mode(WIFI_AP);
    WiFi.softAP("leafy", "leafylantern");
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    Serial.println ( "" );
    if ( MDNS.begin ( "leafy" ) ) 
    {
      Serial.println ( "MDNS responder started" );
    }
    
}

void connectToWifi()
{
   //connect to wifi
    const char *pwc = password.c_str();
    const char *ssidc = ssid.c_str();
 
    WiFi.begin ( ssidc, pwc );
    // Wait for connection
    int waited = 0;
    while ( WiFi.status() != WL_CONNECTED ) 
    {
      delay ( 500 );
      Serial.print ( "." );
      waited++;
      if(waited > 20)
      {
        clearSettings();
        startAccessPoint();
        break;
      }
    }
      if ( MDNS.begin ( "leafy" ) ) 
      {
        Serial.println ( "MDNS responder started" );
      }
  
}

