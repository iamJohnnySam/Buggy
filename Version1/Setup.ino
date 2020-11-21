void setupPins (){
  pinMode(M1p, OUTPUT);
  pinMode(M1n, OUTPUT);
  pinMode(M2p, OUTPUT);
  pinMode(M2n, OUTPUT);
  pinMode(M3p, OUTPUT);
  pinMode(M3n, OUTPUT);
  pinMode(M4p, OUTPUT);
  pinMode(M4n, OUTPUT);
  digitalWrite (M1p, LOW);
  digitalWrite (M1n, LOW);
  digitalWrite (M2p, LOW);
  digitalWrite (M2n, LOW);
  digitalWrite (M3p, LOW);
  digitalWrite (M3n, LOW);
  digitalWrite (M4p, LOW);
  digitalWrite (M4n, LOW);
}

void setupWiFi() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, ip, netmask);
  WiFi.softAP(ssid, password);
}
