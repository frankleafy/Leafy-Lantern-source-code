void clearSettings()
{
  preferences.begin("leafy", false);
  preferences.clear();
  preferences.end();
}

void getSettings()
{
  preferences.begin("leafy", false);
  //preferences.clear();
  ssid = preferences.getString("ssid", "none");
  password = preferences.getString("wifipw", "none");
  preferences.end();
}

void setSSIDSetting(String newssid )
{
  preferences.begin("leafy", false);
  preferences.putString("ssid", newssid);
  preferences.end();
}

void setPWSetting( String newpw )
{
  preferences.begin("leafy", false);
  preferences.putString("wifipw", newpw);
  preferences.end();
}
