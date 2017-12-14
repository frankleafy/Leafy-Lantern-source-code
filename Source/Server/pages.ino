
 
String loadHomePage()
{
  String page = "<html>\
    <head>\
      <title>Leafy Lantern</title>\
      <style>\
        body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
      </style>\
    </head>\
    <body>\
      <h1>Welkom to your Leafy Lantern configuration - time: {0}</h1>\
      <h2>Please configure your wifi, after connecting to your wifi, your Leafy Lantern will be available on leafy.local</h2>\
      <form action=\"http://192.168.4.1/\" method=\"POST\">\
      Please enter your SSID: <input type=\"text\" name=\"ssid_input\"><BR>\
      Please enter your Password: <input type=\"text\" name=\"pw_input\"><BR>\
      <input type=\"submit\" value=\"Enter\"><BR>\
      </form>\
    </body>\
  </html>";

  return page;
}

String loadDashboard()
{
  String page = "<html>\
    <head>\
      <title>Leafy Lantern</title>\
      <style>\
        body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
      </style>\
    </head>\
    <body>\
      <h1>Welcome to your Leafy Lantern dashboard - time: {0}</h1>\
            <form action=\"http://leafy.local/\" method=\"POST\">\
      Please enter reset: <input type=\"text\" name=\"reset_input\"><BR>\
      <input type=\"submit\" value=\"Enter\"><BR>\
      </form>\
    </body>\
  </html>";

 page.replace("{0}",getTimeString());
  return page;
}

String load404(ESP32WebServer server )
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }
  return message;
}

String loadDemo()
{
   String page = " <html>\
  <head>\
     <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script>\
     <!--Load javascript for demo-->\
     <script type=\"text/javascript\" src=\"https://drive.google.com/uc?export=download&id=1y24e6GznAgqWXXBg62RrNtBZhO1NR-7J\"></script>\
  </head>\
  <body>\
  </body>\
</html>\
";
return page;
}

String loadGauge()
{
 String page = " <html>\
  <head id=\"head\">\
   <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\
   <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js\"></script>\
    <script type=\"text/javascript\" src=\"https://drive.google.com/uc?export=download&id=107AU61hsJd6a-KmGqkaPWW_QrPeXdFRp\"></script>\
    <script type=\"text/javascript\" src=\"https://drive.google.com/uc?export=download&id=1ZT2-cm6g6s1a2M5P0mI3EtMIMApcWZ4I\"></script>\
  </head>\
  <body>\
    <div id=\"chart_div\" style=\"width: 400px; height: 120px;\"></div>\
    <p/>&nbsp;<p/>&nbsp;<p/>&nbsp;<p/>\
     <div id=\"includedContent\"></div>\
  </body>\
</html>\
";
return page;
}
