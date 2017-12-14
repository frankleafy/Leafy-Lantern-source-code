//2Do refactor
void getQueryString()
{
    if (server.args() > 0 )
    { 
     
      // Arguments were received
      for ( uint8_t i = 0; i < server.args(); i++ ) 
      {
        Serial.print(server.argName(i)); // Display the argument
        
        Argument_Name = server.argName(i);
        
        if (server.argName(i) == "ssid_input") 
        {
          Serial.print("ssid: ");
          Serial.println(server.arg(i));
          setSSIDSetting(server.arg(i));
       }
        
        if (server.argName(i) == "pw_input") 
        {
          Serial.print("pw was: ");
          Serial.println(server.arg(i));
          setPWSetting(server.arg(i));
          // e.g. range_maximum = server.arg(i).toInt();   // use string.toInt()   if you wanted to convert the input to an integer number
          // e.g. range_maximum = server.arg(i).toFloat(); // use string.toFloat() if you wanted to convert the input to a floating point number
        }
        
        //esp_restart
        
        if (server.argName(i) == "reset_input") 
        {
          Serial.print("reset was: ");
          if(server.arg(i)=="reset")
          {
            clearSettings();
          }
        }
      }
    }
}

