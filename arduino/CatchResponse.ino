/*
Arduino program to capture the PulsOx output graph data points, i.e.
the Divital Volume Pulse.
*/

/* constants: */
int green = A1;
int blue = A2;

/* variables to catch a data reading */
int timestamp = 0;
int greenThis = 0;
int greenPrevious = 0;
int blueValuesPrevious[10];
int blueValues[10];
int i = 0;
int carouselStopped = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  i = 0;
  greenPrevious = analogRead(green);
  
  do {
    blueValuesPrevious[i] = analogRead(blue);
    greenThis = analogRead(green);
    if (greenThis > 50 * (greenPrevious + 1)) {
      timestamp = millis();
      blueValues[0] = analogRead(blue);
      blueValues[1] = analogRead(blue);
      blueValues[2] = analogRead(blue);
      blueValues[3] = analogRead(blue);
      blueValues[4] = analogRead(blue);
      blueValues[5] = analogRead(blue);
      blueValues[6] = analogRead(blue);
      blueValues[7] = analogRead(blue);
      blueValues[8] = analogRead(blue);
      blueValues[9] = analogRead(blue);
      break;
    }
    greenPrevious = greenThis;
    i += 1;
    if (i > 9)
      i = 0;
  
  } while(true);
  Serial.print(timestamp);
  carouselStopped = i;
  i++;
  while (i != carouselStopped) {
    Serial.print(' ');
    Serial.print(blueValuesPrevious[i]);
    i += 1;
    if (i > 9)
      i = 0;
  }
  
  for (i = 0; i < 10; i++) {
    Serial.print(' ');
    Serial.print(blueValues[i]);
  }
  Serial.print('\n');
}
