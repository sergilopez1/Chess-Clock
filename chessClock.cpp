#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Wire.h> 

const int pinBoto1 = 12;
const int pinBoto2 = 13;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},     // A --> to modify white's time/(press 'D' before to modify increment)
  {'4', '5', '6', 'B'},     // B --> to modify black's time/(press 'D' before to modify increment)
  {'7', '8', '9', 'C'},     // C --> pause/resume
  {'*', '0', '#', 'D'}      // D --> turn on/off increment modifier (when a player moves a piece gains time)
};                          // * --> if you select this option, the numbers you insert after will be the increment in seconds
                            // # --> if you select this option, the numbers you insert after will be the increment in minutes
//characters '*' and '#' can only be used to modify the increment
//to modify time just press 'A' or 'B' button and if you want to set white's time to 3:00 minute match insert the numbers '3' '0' '0' with the membrane switch

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);

bool statusPause = true;
bool turn = true;  //starts with white turn
bool gameOver = false;
bool incCondition;
bool modifyingIncrement = false;
bool modifyingWhiteIncrement = false;
bool modifyingBlackIncrement = false;
bool modifyingWhite = false;
bool modifyingBlack = false;

double whiteTime=183000;  //when you turn on the clock, the default time is 3:02 minutes with 2 seconds of increment
double blackTime=183000;
double WhiteIncrement = 2;
double BlackIncrement = 2;
double whiteDifference = millis();
double blackDifference = millis();  

int whiteSeconds=0;
int blackSeconds=0;
int whiteMinutes=0;
int blackMinutes=0;
int statusButton;
int laststatusButton = LOW;
int multiplicador = 1;
int contDesenes = 1;
int contadorXifres; 

char customKey;
char oldCustomKey;
char lastKey;

unsigned long lastDebounceTime = 0;  //due to its a pushbutton and not a switch, we need to use a debounce
unsigned long debounceDelay = 50;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(pinBoto1, INPUT);
  pinMode(pinBoto2, INPUT);
  UpdateWhiteTime();
  UpdateBlackTime();
}
  
void loop(){
  
  if(gameOver == false){
    customKey = customKeypad.getKey();
    if(customKey == 'C'){
       statusPause = !statusPause;
       Serial.println(customKey);
    }
    if(statusPause == true){  
      whiteDifference = millis();
      blackDifference = millis();
      if(customKey == 'D'){
        Serial.println(customKey);
        incrementJugada();
      }
      if(customKey == 'A' || customKey == 'B'){
        oldCustomKey = customKey;
        Serial.println(customKey);  
        modifyTime();
      }
      
    }
    while(statusPause == false){
      int reading = 0;
      if(digitalRead(pinBoto1) == 1 || digitalRead(pinBoto2) == 1){
        reading = 1;
      }
      if (reading != laststatusButton) {
        lastDebounceTime = millis();
      }
      if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != statusButton) {
          statusButton = reading;
          if(statusButton == HIGH){
            turn = !turn;
          }
          else if(statusButton == LOW){
            if(turn == true){
              whiteTime += WhiteIncrement*1000;
            }
            else if(turn == false){
              blackTime += BlackIncrement*1000;
            }
          }
        }
      }
      if(turn == true){
        UpdateWhiteTime();
        blackDifference = millis();
        
      }
      if(turn == false){
        UpdateBlackTime();
        whiteDifference = millis();
      }
      if(gameOver == true){
        break;
      }
      customKey = customKeypad.getKey();
      if(customKey == 'C'){
        statusPause = !statusPause;
        Serial.println(customKey);
      }
      laststatusButton = reading;
      
    }
  }
}


void UpdateWhiteTime(){
  lcd.setCursor(10,0);
  lcd.print("White");
  lcd.setCursor(11, 1);
  
  whiteTime -= (millis()-whiteDifference);
  whiteDifference = millis();
  
  
  whiteMinutes = floor(whiteTime / 60000);
  whiteSeconds = floor(whiteTime / 1000) - whiteMinutes * 60;
  
  lcd.print(whiteMinutes);
  lcd.print(":");
  if (whiteSeconds < 10) {
    lcd.print(0);
  }
  lcd.print(whiteSeconds);
  if(whiteTime<= 0){
    gameOver = true;
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("GAME OVER");
    lcd.setCursor(1,1);
    lcd.print("Black wins");
    return;
  }
}    

void UpdateBlackTime(){ 
    lcd.setCursor(0,0);
    lcd.print("Black");
    lcd.setCursor(1, 1);
    
    blackTime -= (millis()-blackDifference);
    blackDifference = millis();
    
    blackMinutes = floor(blackTime/ 60000);
    blackSeconds = floor(blackTime / 1000) - blackMinutes * 60;
    
    lcd.print(blackMinutes);
    lcd.print(":");
    if (blackSeconds < 10) {
       lcd.print(0);
    }
    lcd.print(blackSeconds);
    if(blackTime<= 0){
      gameOver = true;
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("GAME OVER");
      lcd.setCursor(1,1);
      lcd.print("White wins");
      return;
    }
}

void incrementJugada(){
    lastKey = 'x';
    Serial.println(customKey);
    modifyingIncrement = true;
    while(modifyingIncrement == true){
      customKey = customKeypad.getKey();
      
      if(customKey == 'A'){
        Serial.println(customKey);
        incCondition = false;
        modifyingWhiteIncrement = true;
        while(modifyingWhiteIncrement == true){
          WhiteIncrement = 0;
          customKey = customKeypad.getKey();
          
          if(customKey == '*'){
            Serial.println(customKey);
            multiplicador = 1;
            incCondition = true;
            modifyingWhiteIncrement = false;
          }
          else if(customKey == '#'){
            Serial.println(customKey);
            multiplicador = 60;
            incCondition = true;
            modifyingWhiteIncrement = false;
          }
          while(incCondition == true){
            
            customKey = customKeypad.getKey();
            if(customKey != lastKey && (customKey >= '0' && customKey <= '9' )){
              Serial.println(customKey);
              Serial.println(lastKey);
              WhiteIncrement = WhiteIncrement*contDesenes;
              WhiteIncrement += floor(customKey - '0');
              if(contDesenes < 10){
                contDesenes = contDesenes * 10;
              }
              
            }
            if(customKey == 'D'){
              
              Serial.println(customKey);
              modifyingIncrement = false;
              modifyingWhiteIncrement == false;
              customKey = 'x'; //caracter qualsevol per que no es repeteixi el bucle inicial
              incCondition = false;
            }
            lastKey = customKey;
          }
        }
        WhiteIncrement = WhiteIncrement * multiplicador;
        contDesenes = 1;
      }
      
      else if(customKey == 'B'){
        Serial.println(customKey);
        incCondition = false;
        modifyingBlackIncrement = true;
        while(modifyingBlackIncrement == true){
          BlackIncrement = 0;
          customKey = customKeypad.getKey();
          
          if(customKey == '*'){
            Serial.println(customKey);
            multiplicador = 1;
            incCondition = true;
            modifyingBlackIncrement = false;
          }
          else if(customKey == '#'){
            Serial.println(customKey);
            multiplicador = 60;
            incCondition = true;
            modifyingBlackIncrement = false;
          }
          while(incCondition == true){
            
            customKey = customKeypad.getKey();
            if(customKey != lastKey && (customKey >= '0' && customKey <= '9' )){
              Serial.println(customKey);
              Serial.println(lastKey);
              BlackIncrement = BlackIncrement*contDesenes;
              BlackIncrement += floor(customKey - '0');
              if(contDesenes < 10){
                contDesenes = contDesenes * 10;
              }
              
            }
            if(customKey == 'D'){
              Serial.println(customKey);
              modifyingIncrement = false;
              modifyingBlackIncrement == false;
              customKey = 'x'; //random char to avoid repeating the instruction
              incCondition = false;
            }
            lastKey = customKey;
          }
        }
        BlackIncrement = BlackIncrement * multiplicador;
        contDesenes = 1;
        Serial.println(BlackIncrement);
      }
      
    } 
}

void modifyTime(){  //to change each player's time
  if(oldCustomKey == 'A'){
    Serial.println(customKey); 
    modifyingWhite = true;
    contadorXifres = 0;
    whiteTime = 0;
    while(modifyingWhite == true){
      customKey = customKeypad.getKey();
      if(customKey >= '0' && customKey <= '9'){  // only runs this part if the last key entered on the keyboard is a numbre between 0 and 9 
        Serial.println(customKey);               // as the number is a char, we need to keep an eye to the ASCII table to realize that the order is 0, 1, 2, 3 ... therefore we can use the comparison above
        contadorXifres++;
        if(contadorXifres == 1){
          whiteTime += double(floor(customKey - '0')*60000);
        }
        else if(contadorXifres == 2){
          whiteTime += double(floor(customKey - '0')*10000);
        }
        else if(contadorXifres == 3){
          whiteTime += double(floor(customKey - '0')*1000);
        }
        else if(contadorXifres == 4){
          whiteTime = whiteTime*10;
          whiteTime += double(floor(customKey - '0')*1000);
        }
        Serial.println(whiteTime);
        customKey = 'x'; 
      }
      if(customKey == 'D'){
        modifyingWhite = false;
        Serial.println(customKey); 
        customKey = 'x';   
        whiteDifference = millis();
        whiteTime += 1000;
        UpdateWhiteTime();
      }
    }
  }
  else if(oldCustomKey == 'B'){
    Serial.println(customKey); 
    modifyingBlack = true;
    contadorXifres = 0;
    blackTime = 0;
    while(modifyingBlack == true){
      customKey = customKeypad.getKey();
      if(customKey >= '0' && customKey <= '9'){  
        Serial.println(customKey); 
        contadorXifres++;
        if(contadorXifres == 1){
          blackTime += double(floor(customKey - '0')*60000);
        }
        else if(contadorXifres == 2){
          blackTime += double(floor(customKey - '0')*10000);
        }
        else if(contadorXifres == 3){
          blackTime += double(floor(customKey - '0')*1000);
        }
        else if(contadorXifres == 4){
          blackTime = blackTime*10;
          blackTime += double(floor(customKey - '0')*1000);
        }
        Serial.println(blackTime);
        customKey = 'x'; 
      }
      if(customKey == 'D'){
        modifyingBlack = false;
        Serial.println(customKey); 
        customKey = 'x';   
        blackDifference = millis();
        blackTime += 1000;
        UpdateBlackTime();
      }
    }
  }
}