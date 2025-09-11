int sensorMax1;
int sensorMax2;
int sensorMin2;
int sensorMin1;
int sensorValue1;
int sensorValue2;
int timeFin;
int timeBegin;
int baseValue2;
int baseValue1;


void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);


  sensorValue2 = analogRead(A5);
  sensorValue1 = analogRead(A3);
  sensorMax1 = sensorMin1 = analogRead(A3);
  sensorMax2 = sensorMin2 = analogRead(A5);






  while (millis() < 1000) {


    // record the maximum sensor value
    if (sensorValue1 > sensorMax1) {
      sensorMax1 = sensorValue1;
    }


    // record the minimum sensor value
    if (sensorValue1 < sensorMin1) {
      sensorMin1 = sensorValue1;
    }
    if (sensorValue2 > sensorMax2) {
      sensorMax2 = sensorValue2;
    }


    // record the minimum sensor value
    if (sensorValue2 < sensorMin2) {
      sensorMin2 = sensorValue2;
    }
  }


  baseValue1 = (sensorMin1 + sensorMax1) / 2;
  Serial.println(baseValue1);
  baseValue2 = (sensorMin2 + sensorMax2) / 2;
  Serial.println(baseValue2);
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("a5 "); Serial.print(analogRead(A5));
  //Serial.print("  a3: "); Serial.println(analogRead(A3));
  analogRead(A5);
  analogRead(A3);
  bool trigger;
  // Serial.println(analogRead(A5));


  if (analogRead(A5) < (baseValue2 - 50)) {
    timeBegin = millis();
    trigger = true;
  }






  if (analogRead(A3) < (baseValue1 - 50) && trigger == true) {


    timeFin = millis();


    int speedTime = timeFin - timeBegin;


    //1.5cm
    Serial.println(1.5 / speedTime);  // * 1000) / 27.778);
    trigger = false;




    while (analogRead(A5) < (baseValue2 - 50)) Serial.println("waiting..................................................");
  }
}
