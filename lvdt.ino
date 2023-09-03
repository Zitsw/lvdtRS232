int analogPin = 3;
float result = 0;
void setup() {
Serial.begin(9600);

}

void loop() {
result = analogRead(analogPin);
//result = map(result, 0, 1023, 0, 100);
//result = result/1000;
Serial.println(result);
delay(100);



}
