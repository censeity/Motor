
const int buttonPin = 2;    
const int motorPin = 9;      
int motorState = HIGH;       
int buttonState;             
int lastButtonState = LOW;   
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, motorState);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        motorState += 50;
       if(motorState>255){
        motorState =0;
       }
      }
    }
  }
  analogWrite(motorPin, motorState);
  lastButtonState = reading;
}
