  
  
  void setup(){

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(115200);
  pinMode(A2, INPUT);
  pinMode(7,INPUT);
}

void loop(){
char ln[64];
snprintf(ln, sizeof(ln), "%d %d %d %d", analogRead(A0), analogRead(A1),analogRead(A2),digitalRead(7));
Serial.println(ln);
delay(50);

}
