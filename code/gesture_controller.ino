
/*
  Gesture-Based Media Controller using Ultrasonic Sensors
  Author: A. Shashank
*/

#define trigPin1 9
#define echoPin1 10
#define trigPin2 11
#define echoPin2 12

long duration1, distance1;
long duration2, distance2;

int threshold = 20;  // cm

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  Serial.begin(9600); // Communication with PC or Python
}

void loop() {
  distance1 = getDistance(trigPin1, echoPin1);
  distance2 = getDistance(trigPin2, echoPin2);

  if (distance1 < threshold && distance2 > threshold) {
    Serial.println("NEXT");  // Swipe Right
    delay(1000);
  } else if (distance2 < threshold && distance1 > threshold) {
    Serial.println("PREV");  // Swipe Left
    delay(1000);
  } else if (distance1 < threshold && distance2 < threshold) {
    Serial.println("PLAY_PAUSE");  // Hold Both
    delay(1500);
  }
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}
