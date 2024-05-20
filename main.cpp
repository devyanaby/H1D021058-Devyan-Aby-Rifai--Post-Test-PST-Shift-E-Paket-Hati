#include <Arduino.h>
#include <Servo.h>

// Mendefinisikan pin untuk LED merah, LED hijau, dan servo
const int redLedPin = 7;
const int greenLedPin = 8;
const int servoPin = 9;

// Interval waktu dalam milidetik (5 detik)
const unsigned long interval = 5000;

Servo myServo; // Membuat objek servo

bool isRedLedOn = true; // Variabel untuk melacak status LED merah
unsigned long previousMillis = 0; // Variabel untuk melacak waktu sebelumnya

void setup() {
  // Mengatur pin LED sebagai output
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // Menghubungkan servo ke pin yang telah ditentukan
  myServo.attach(servoPin);
  myServo.write(0); // Mengatur posisi awal servo ke 0 derajat

  // Menyalakan LED merah dan mematikan LED hijau pada awalnya
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}

void loop() {
  // Mendapatkan waktu saat ini dalam milidetik
  unsigned long currentMillis = millis();

  // Mengecek apakah interval waktu telah berlalu
  if (currentMillis - previousMillis >= interval) {
    // Menyimpan waktu saat ini sebagai waktu sebelumnya
    previousMillis = currentMillis;

    // Jika LED merah sedang menyala, matikan LED merah dan nyalakan LED hijau
    if (isRedLedOn) {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
    } else {
      // Jika LED hijau sedang menyala, nyalakan LED merah dan matikan LED hijau
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
    }

    // Mengatur posisi servo berdasarkan status LED merah
    myServo.write(isRedLedOn ? 90 : 0);

    // Membalik status LED merah
    isRedLedOn = !isRedLedOn;
  }
}
