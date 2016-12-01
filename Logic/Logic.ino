#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

int startStopSwitch = 8;
int nextSwitch = 9;
int filePosition = 0;
boolean lastStartStop = LOW;
boolean lastNext = LOW;
boolean currentStartStop = LOW;
boolean currentNext = LOW;
String categories[] = {"Biology", "French", "Art"};


void setup() {
lcd.begin(16,2);
pinMode(startStopSwitch, INPUT);
pinMode(nextSwitch, INPUT);

}

int centerValue(String clue) {
return 16 - sizeof(clue) / 2;
}

boolean debounce(boolean last, char button) {
  boolean current = digitalRead(button);
  if (last != current){
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void menu(int selectedFile) {
  lcd.setCursor(4, 1);
  lcd.print("Category"); //change to "file"?
  lcd.setCursor(centerValue(categories[selectedFile]), 2);
  lcd.print(categories[selectedFile]);
}

void loop() {
  
 menu(filePosition);
 currentNext = debounce(lastNext, nextSwitch);
 if (currentNext == HIGH && lastNext == LOW){
  filePosition++;
 }

}
