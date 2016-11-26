int switchPin1 = 8;
int switchPin2 = 9;
int ledPin1 = 10;
int ledPin2 = 11;
boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;
boolean ledOn1 = false;
boolean ledOn2 = false;

void setup() {
  // put your setup code here, to run once:
pinMode(switchPin1, INPUT);
pinMode(switchPin2, INPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
}

boolean debounce1(boolean last) {
  boolean current = digitalRead(switchPin1);
  if (last != current){
    delay(5);
    current = digitalRead(switchPin1);
  }
  return current;
}
boolean debounce2(boolean last) {
  boolean current = digitalRead(switchPin2);
  if (last != current){
    delay(5);
    current = digitalRead(switchPin2);
  }
  return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton1 = debounce1(lastButton1);
if (currentButton1 == HIGH  && lastButton1 == LOW) {
ledOn1 = !ledOn1;
}
lastButton1 = currentButton1;
  digitalWrite(ledPin1, ledOn1);
  
    currentButton2 = debounce2(lastButton2);
if (currentButton2 == HIGH  && lastButton2 == LOW) {
ledOn2 = !ledOn2;
}
lastButton2 = currentButton2;
  digitalWrite(ledPin2, ledOn2);
}
