//If you're using the built-in LED for testing, remember that it works with inverted logic
//(HIGH=LOW, and LOW=HIGH)
int RED = 2;
int GREEN = 3;  // the pin that the LED is attached to
int sensor = 12;              // the pin that the sensor is attached to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial

  delay(1000);
  Serial.println("ATH");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("RCWL-0516 Microwave Radar activated ");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000); //  918789646289
}

void loop() {
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH)
  {




    if (state == LOW)
    {
      digitalWrite(RED, 0);
      digitalWrite(GREEN, 1);
      Serial.println("Motion detected!");

      Serial.println("ATH");    //Sets the GSM Module in Text Mode
      delay(1000);
      Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
      delay(1000);  // Delay of 1000 milli seconds or 1 second
      Serial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace x with mobile number
      delay(1000);
      Serial.println("Alert!!! Motion Detected ");// The SMS text you want to send
      delay(100);
      Serial.println((char)26);// ASCII code of CTRL+Z
      delay(3000); //  918789646289 919344752333
      Serial.println("ATD +919344752333");// ASCII code of CTRL+Z
      delay(3000);
      state = HIGH;
    }
  }
  else {


    if (state == HIGH) {
      digitalWrite(RED, 1);
      digitalWrite(GREEN, 0);
      Serial.println(" NO Motion detected!");
      state = LOW;       // update variable state to LOW
    }
  }
}
