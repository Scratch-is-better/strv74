#include <WiFi.h>
#include <WiFiUdp.h>
#include <stdint.h>


int localPort = 8888;
WiFiUDP Udp;

const char* ssid = "piAp";
const char* pass = "password";


const int ena=;
const int enb=;
const int in1=;
const int in2=;
const int in3=;
const int in4=;
const int servoPin;
const int ledPin= 32;


void setup() {

  Serial.begin(115200);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 pinMode(ledPin, OUTPUT);
  // Set Static IP address
  IPAddress local_IP(192, 168, 5, 2);
  IPAddress gw_IP(192, 168, 5, 1);
  IPAddress subnet(255, 255, 255, 0);

  Serial.begin(115200);

  delay(1000);
  if (!WiFi.config(local_IP, gw_IP, subnet)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.mode(WIFI_STA); //Optional
  WiFi.begin(ssid, pass);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  Udp.begin(localPort);

}


void loop() {
int t = 5;
  int packetSize = Udp.parsePacket();

  uint8_t rx[6]; // 0 to 255

  if (packetSize == sizeof(rx)) {

    Udp.read(rx, sizeof(rx));

    if (rx[0] < 76+t && rx[0] > 76-t)analogWrite(ena, 0);
    
    else() analogWrite(ena, rx[0]);

    if (rx[1] < 77+t && rx[1] > 77-t)analogWrite(enb, 0;
    
    else()analogWrite(enb, rx[1]);
  
    digitalWrite(in1, rx[2]);
    digitalWrite(in2, !rx[2]);

    digitalWrite(in3, rx[3]);
    digitalWrite(in4, !rx[3]);

    for (int x : rx)
      Serial.printf("%d ", x);
    Serial.println();


    digitalWrite(ledPin, rx[4]);
    analogWrite(servoPin, rx[5];

  }

}

