//https://github.com/lacour-vincent/wifi-car-esp8266/blob/master/wifi_car_esp8266_AP/wifi_car_esp8266_AP.ino

void startWebServer (){
  server.on("/move", HTTP_GET, handleMoveRequest);
  server.on("/action", HTTP_GET, handleActionRequest);
  server.onNotFound(handleNotFound);
  server.begin();
}

void handleMoveRequest() {
  if (!server.hasArg("dir")) {
    server.send(404, "text / plain", "Move: undefined");
    return;
  }
  String direction = server.arg("dir");
  if (direction.equals("F")) {
    goStraight();
    server.send(200, "text / plain", "Move: forward");
  }
  else if (direction.equals("B")) {
    goBack();
    server.send(200, "text / plain", "Move: backward");
  }
  else if (direction.equals("S")) {
    goStop();
    server.send(200, "text / plain", "Move: Stop");
  }
  else  if (direction.equals("L")) {
    goLeft();
    server.send(200, "text / plain", "Turn: Left");
  }
  else  if (direction.equals("R")) {
    goRight();
    server.send(200, "text / plain", "Turn: Right");
  }
  else {
    server.send(404, "text / plain", "Move: undefined");
  }
}


void handleActionRequest() {
  if (!server.hasArg("type")) {
    server.send(404, "text / plain", "Action: undefined");
    return;
  }
  String type = server.arg("type");
  if (type.equals("1")) {
    fSpeed = 500;
    server.send(200, "text / plain", "Action 1");
  }
  else if (type.equals("2")) {
    fSpeed = 600;
    server.send(200, "text / plain", "Action 2");
  }
  else if (type.equals("3")) {
    fSpeed = 700;
    server.send(200, "text / plain", "Action 3");
  }
  else if (type.equals("4")) {
    fSpeed = 800;
    server.send(200, "text / plain", "Action 4");
  }
  else if (type.equals("5")) {
    fSpeed = 900;
    server.send(200, "text / plain", "Action 5");
  }
  else if (type.equals("6")) {
    fSpeed = 1000;
    server.send(200, "text / plain", "Action 6");
  }
  else if (type.equals("7")) {
    // TODO : Action 7
    server.send(200, "text / plain", "Action 7");
  }
  else if (type.equals("8")) {
    // TODO : Action 8
    server.send(200, "text / plain", "Action 8");
  }
  else {
    server.send(404, "text / plain", "Action: undefined");
  }
}


void handleNotFound() {
  server.send(404, "text / plain", "404: Not found");
}
