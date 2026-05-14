int s = 7;
int x;
int led = 8;

void setup() {

    Serial.begin(9600);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
}

void loop() {

    x = digitalRead(s);
    Serial.println(x);

    if (x == 0) {

        digitalWrite(8, LOW);
    }
    else {

        digitalWrite(8, HIGH);
    }
}
