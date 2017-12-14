String loadHomePage();
String loadGauge();
void  getQueryString();
void getSettings();
void setSettings(String, String);
void startAccesPoint();
void clearSettings();
void connectToWifi();
String load404(ESP32WebServer);
String loadDashboard();
void getAndSetTime();
void startTimer();
void rotateplants();
String getTimeString();

#define ANALOGLIGHTPIN1 1 // number of outgoing bytes to buffer for Serial1

