const int ledPin = 13;
const int buzzerPin = 8;

String correctOTP = "123456";

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("EV Charging Station Ready");
  Serial.println("Enter OTP:");
}

void loop() {

  if (Serial.available() > 0) {

    String enteredOTP = Serial.readStringUntil('\n');
    enteredOTP.trim();

    if (enteredOTP == correctOTP) {

      Serial.println("OTP Verified");
      Serial.println("Charging Started");

      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, LOW);
    }

    else {

      Serial.println("Wrong OTP");

      digitalWrite(ledPin, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(500);
      digitalWrite(buzzerPin, LOW);
    }

    Serial.println("\nEnter OTP:");
  }
}
