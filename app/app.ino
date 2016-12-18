#define TRIG_PIN 4
#define ECHO_PIN 3

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  char line [100];
  int i = 0;
  while (Serial.available()) {
    line[i] = Serial.read();
    i++;
  }
  if (i > 0 && line[0] == 'D') {
    long distance = 0;
    detect_dist(&distance, TRIG_PIN, ECHO_PIN);
    String res = "D:" + String(distance);
    Serial.println(res); 
  }
}

void detect_dist(long *dist, int trigPin, int echoPin) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  *dist = (duration/2)/29.1;
}

