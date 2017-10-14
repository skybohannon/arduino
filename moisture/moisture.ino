const int moistInput = A0;
const int threshold = 550;

const int ledPin1 = 13;
const int ledPin2 = 12;

void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);

}

void massDigitalWrite(unsigned char pins[], unsigned char length, unsigned char state)
{
 unsigned char i;
 for (i = 0; i < length; i++)
   digitalWrite(pins, state);
}

void loop() {

  int sensorValue = analogRead(moistInput);
  
 if (sensorValue > threshold) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
  }

  
  Serial.println(sensorValue);
  delay(100);
}
