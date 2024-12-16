const int buzzerPin = 12;  // บัซเซอร์
const int ledCount = 10;    // จำนวน LED

int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };   // LED เชื่อมต่อกับ Arduino

// ความถี่ของเมโลดี้ (Do, Re, Mi, Fa, Sol, La, Ti, Do)
const int melody[] = { 261, 293, 329, 349, 392, 440, 493, 523 };
const int melodyLength = sizeof(melody) / sizeof(melody[0]);

void setup() {

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // เล่นแต่ละความถี่ในเมโลดี้
  for (int i = 0; i < melodyLength; i++) {
    int frequency = melody[i];
    tone(buzzerPin, frequency);

    // เปลี่ยนสี LED Bar Graph ตามความถี่
    changeLEDs(frequency);

    delay(500);
    noTone(buzzerPin);
    delay(500);
  }
}


void changeLEDs(int frequency) {

  int ledLevel = map(frequency, 261, 523, 0, ledCount);

  // เปิด LED ตามระดับที่คำนวณ
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
