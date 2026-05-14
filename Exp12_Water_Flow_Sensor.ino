// Water Flow Sensor with Arduino
// Sensor: YF-S201

volatile int flow_frequency; // Measures flow sensor pulses
float l_minute; // Litres/minute
unsigned char flowsensor = 2; // Sensor connected to pin 2
unsigned long currentTime;
unsigned long cloopTime;

void flow () // Interrupt function
{
   flow_frequency++;
}

void setup()
{
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH);

   Serial.begin(9600);

   attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING);

   currentTime = millis();
   cloopTime = currentTime;
}

void loop ()
{
   currentTime = millis();

   // Calculate flow rate every 1 second
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime;

      // Pulse frequency to litres/minute conversion
      l_minute = (flow_frequency / 7.5);

      Serial.print("Flow Rate: ");
      Serial.print(l_minute);
      Serial.println(" L/min");

      flow_frequency = 0;
   }
}
