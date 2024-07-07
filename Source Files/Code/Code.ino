// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
const int motorpin1 = 10;
// defines variables

long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(motorpin1, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance:");
  Serial.println(distance);
  digitalWrite(motorpin1, LOW);
  if (distance <= 90 && distance != 0){
    digitalWrite(motorpin1, HIGH);
    delay (10000);
    digitalWrite(motorpin1, LOW);
    delay (2000);
  }

  // Prints the distance on the Serial Monitor
