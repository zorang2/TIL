#define NUM_LED 5
#define TIME_DELAY 1000 

const byte pinLED[NUM_LED] = {13, 12, 11, 10, 9};

void setup() {
  int i;
  for (i=0; i<NUM_LED; i++)
    pinMode(pinLED[i] , OUTPUT);
}

void loop() {
  int i;
  for (i=0;i<NUM_LED;i++) {
    digitalWrite(pinLED[i] , HIGH);
    delay(TIME_DELAY);
  }
  for (i=NUM_LED-1; i>=0; i--) {
    digitalWrite(pinLED[i], LOW);
    delay(TIME_DELAY);
  }
}
