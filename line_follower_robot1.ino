// IR sensor pins
#define LEFT_MOST 2
#define LEFT 3
#define CENTER 4
#define RIGHT 5
#define RIGHT_MOST 6

// Motor driver pins
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

void setup() {
    pinMode(LEFT_MOST, INPUT);
    pinMode(LEFT, INPUT);
    pinMode(CENTER, INPUT);
    pinMode(RIGHT, INPUT);
    pinMode(RIGHT_MOST, INPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    int s1 = digitalRead(LEFT_MOST);
    int s2 = digitalRead(LEFT);
    int s3 = digitalRead(CENTER);
    int s4 = digitalRead(RIGHT);
    int s5 = digitalRead(RIGHT_MOST);

    // Move forward when the center sensor detects the line
    if (s3 == 1) {
        moveForward();
    }
    // Slight right if right sensor detects the line
    else if (s4 == 1) {
        turnRight();
    }
    // Sharp right if extreme right sensor detects the line
    else if (s5 == 1) {
        sharpRight();
    }
    // Slight left if left sensor detects the line
    else if (s2 == 1) {
        turnLeft();
    }
    // Sharp left if extreme left sensor detects the line
    else if (s1 == 1) {
        sharpLeft();
    }
    // Stop if no sensor detects the line
    else {
        stopMotors();
    }
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void sharpRight() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void sharpLeft() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
