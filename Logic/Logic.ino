#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

int switchNext = 9;
int switchStart = 8;
int filePosition = 0;
boolean menuOn = true;
boolean lastStart = LOW;
boolean currentStart = LOW;
boolean lastNext = LOW;
boolean currentNext = LOW;
String categories[] = {"Biology", "French", "Art"};
String words[3][3] = {
  {"Frog", "Lizard", "Elephant"},
  {"Bonjour", "Madam", "Jambon"},
  {"Monet", "Renoir", "Rembrandt"}
};

void setup() {
lcd.begin(16,2);
pinMode(switchStart, INPUT);
pinMode(switchNext, INPUT);

}

int centerValue(String clue) {
return (16 - clue.length()) / 2;
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
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Category"); //change to "file"?
  lcd.setCursor(centerValue(categories[selectedFile]), 1);
  lcd.print(categories[selectedFile]);
}

//void playGame(int selectedFile) {
//  lcd.clear();
//  for (int i = 0, i < words[selectedFile][i].length(); i++){
//  lcd.setCursor(centerValue(words[selectedFile][i]), 1);
//  }
//  
//}

void loop() {
  if (menuOn) {
 menu(filePosition);
 currentNext = debounce(lastNext, switchNext);
 if (currentNext == HIGH && lastNext == LOW && filePosition < (sizeof(categories) / sizeof(String) - 1)) {
  filePosition++;
 } else if (currentNext == HIGH && lastNext == LOW && filePosition >= (sizeof(categories) / sizeof(String) - 1)) {
  filePosition = 0;
 }
  } else {
 lcd.clear();
 lcd.setCursor(1, 0);
 lcd.print("Main Loop ");
 lcd.print(filePosition);
  }
  
 currentStart = debounce(lastStart, switchStart);
 if (currentStart == HIGH && lastStart == LOW) {
  menuOn = false;
 }

 delay(100);

}
