int fsrPin = 0;         // the FSR and 10K pulldown are connected to a0
int fsrReading;         // the analog reading from the FSR resistor divider
unsigned long startTime;    //start time for stop watch
unsigned long elapsedTime;  //elapsed time for stop watch
int fractional;


void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);

}

void loop(void) {
  fsrReading = analogRead(fsrPin);  //read the sensor state

  if (fsrReading > 10 ) {
    elapsedTime =   millis() - startTime;              // store elapsed time

    //printing time
    Serial.print( (int)(elapsedTime / 1000L));         // divide by 1000 to convert to seconds - then cast to an int to print
    Serial.print(".");
    fractional = (int)(elapsedTime % 1000L);
    if (fractional == 0)
      Serial.print("000");      // add three zero's
    else if (fractional < 10)    // if fractional < 10 the 0 is ignored giving a wrong time, so add the zeros
      Serial.print("00");       // add two zeros
    else if (fractional < 100)
      Serial.print("0");        // add one zero

    Serial.println(fractional);  // print fractional part of time

  } else {
    startTime = millis();  //store the start time
    elapsedTime = 0;
  }

}
