//https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-4-driving-multiple-leds
//https://www.arduino.cc/en/pmwiki.php?n=Serial/read
//https://create.arduino.cc/projecthub/BitteristSquash/how-to-get-string-data-from-computer-via-serial-port-2ca228
int incomingByte = 0;   // for incoming serial data


int ledPins[] = {2,3,4,5,6};

int motorPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  Serial.print("start\r\n");

  
  for(int index = 0; index < 5; index++){
    pinMode(ledPins[index],OUTPUT);
    digitalWrite(ledPins[index], LOW);

  }
  
  pinMode(motorPin,OUTPUT);
  digitalWrite(motorPin, HIGH);

}

void loop() {
  
    // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                String str = Serial.readString();
                if(str == "0"){
                   for(int index = 0; index < 5; index++){
                      digitalWrite(ledPins[index], LOW);
                   }
                }
                else if(str == "1"){
                    digitalWrite(motorPin, HIGH);
                    delay(2000);
                    digitalWrite(ledPins[0],HIGH);
                    digitalWrite(ledPins[1],HIGH);
                    digitalWrite(ledPins[2],LOW);
                    digitalWrite(ledPins[3],LOW);
                    digitalWrite(ledPins[4],LOW);
                  }
                else if(str=="2"){
                    digitalWrite(ledPins[0],LOW);
                    digitalWrite(ledPins[1],HIGH);
                    digitalWrite(ledPins[2],LOW);
                    digitalWrite(ledPins[3],LOW);
                    digitalWrite(ledPins[4],LOW);
                  }
                else if(str=="3"){ 
                    digitalWrite(ledPins[0],LOW);
                    digitalWrite(ledPins[1],LOW);
                    digitalWrite(ledPins[2],HIGH);
                    digitalWrite(ledPins[3],LOW);
                    digitalWrite(ledPins[4],LOW);
                  }
                else if(str=="4"){
                    digitalWrite(ledPins[0],LOW);
                    digitalWrite(ledPins[1],LOW);
                    digitalWrite(ledPins[2],LOW);
                    digitalWrite(ledPins[3],HIGH);
                    digitalWrite(ledPins[4],HIGH);
                  }
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
}
