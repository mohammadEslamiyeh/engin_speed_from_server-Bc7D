#include <ESP8266WebServer.h>//ketab khane web server
#include <ESP8266WiFi.h>
#define ledpin 5
ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
WiFi.mode(WIFI_AP_STA);
WiFi.softAP("mohammadES","123456789");
WiFi.begin("AndroidShare_9141","941a5577c57b");
while(WiFi.status() != WL_CONNECTED){
  delay(5000);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected to Domaino");
Serial.println("Ip Address: ");
Serial.println(WiFi.localIP());
server.on("/control",control);
server.onNotFound(notfound);
server.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
delay(50);
}

void control(void){

  int Speed = server.arg("Speed").toInt();
  analogWrite(5,Speed);//0 - 1023
  server.send(200,"text/html","ok your speed id :"+String(Speed));
  
  
}
void notfound(void){
   
  server.send(404,"text/html","Error");
}
