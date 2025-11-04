void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(A0));
  int motSpd;
  int input = (pulseIn(A4, HIGH, 25000));
  int revMax = 2013;
  int revMin;
  int forMax;
  int forMin;
  int revSpd;
  int forSpd;
  //1522 to
  //min 995
  //max 2013



  if (input != 0) { //removes zero from the inputs of pwm
    //Serial.println(pulseIn(A4, HIGH, 25000));

   // revSpd = map(input, 1522, 2013, 90, 255); //when input in range of 1522-2013 it will change to 90 - 255 so speed controls are proper
    //forSpd = map(input, 995, 1478 , 90, 255);


    //map(value, fromLow, fromHigh, toLow, toHigh)
    revSpd = map(input, 1592, 2073, 80, 255); //when input in range of 1522-2013 it will change to 90 - 255 so speed controls are proper
    forSpd = map(input, 1570 - 22,1070 , 80, 255);

    //Serial.println(revSpd);
    //Serial.println(forSpd);

  }



  if (input > 1570+22) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    motSpd = revSpd;
  }

  //  Serial.println(analogRead(A4));



  if (input < 1570-22) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    motSpd = forSpd;
  }

  if (1570-40 < input && 1595 > input) motSpd = 0; //stops motor when trigger isn't held
  //scale from 995 to 1478 to 90 to 255
  //1522 to 2013
  //min 995
  //max 2013

  Serial.println(input);

  analogWrite(5, motSpd) ;
  analogWrite(6, motSpd);


}
