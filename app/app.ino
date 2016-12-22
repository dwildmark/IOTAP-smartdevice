#define TRIG_PIN 4
#define ECHO_PIN 3
#define LED_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  char line [100];
  int i = 0;
  while (Serial.available()) {
    line[i] = Serial.read();
    i++;
  }
  if (i > 0 ) {
    switch(line[0])
    {
    case 'D':
      {
        long distance = 0;
        detect_dist(&distance, TRIG_PIN, ECHO_PIN);
        String res = "D:" + String(distance);
        Serial.println(res);
        break;
      }
    case 'A':
      flash_light();
      break;
    default:
      break;
    }
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
  *dist = (duration / 2) / 29.1;
}

//Method called from other device...
void flash_light(){
  digitalWrite(LED_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_PIN, LOW);
}

