const int buttonPin = 2;    
const int motorPin = 3;     
int motorState = 0;         
int buttonState;             
int lastButtonState = LOW;   
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;   

void setup() {
  pinMode(motorPin, INPUT);
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
        motorState = !motorState;
      }
    }
  }
  analogWrite(motorPin, motorState);
  buttonState = 0;
if (buttonState < 255)
    buttonState += 50;
}
