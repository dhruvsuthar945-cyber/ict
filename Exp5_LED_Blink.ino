int ledpin = 13;

void setup() {
    pinMode(ledpin, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    digitalWrite(ledpin, HIGH);
    Serial.println("LED ON");
    delay(500);

    digitalWrite(ledpin, LOW);
    Serial.println("LED OFF");
    delay(1000);
}
