#include <Arduino.h>
#include <AccelStepper.h>

const byte stepX = 2;
const byte dirX = 5;
const byte enPin = 8; 

AccelStepper motorX(stepX , dirX);

const int stepPerRev = 200;
const int maxSpeed = 200;
const int acceleration = 100;

void setup() {
    Serial.begin(115200);

    motorX.setMaxSpeed(maxSpeed);
    motorX.setAcceleration(acceleration);
    motorX.moveTo(50);

    pinMode(stepX , OUTPUT); 
    pinMode(dirX , OUTPUT); 
    pinMode(enPin , OUTPUT); 

    digitalWrite(enPin , LOW);
    digitalWrite(dirX , HIGH);

}

void demiTour2() {
    if (motorX.distanceToGo() == 0) {
        motorX.moveTo(-motorX.currentPosition());
    }
    motorX.run();
}

void demiTour() {
    digitalWrite(dirX, HIGH);
    Serial.println("sens horaire");

    for(int i = 0 ; i < stepPerRev ; i++) {
        digitalWrite(stepX, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepX, LOW);
        delayMicroseconds(1000);
    }
    delay(1000);
    digitalWrite(dirX, LOW);
    Serial.println("sens anti-horaire");
    for(int i = 0 ; i < stepPerRev ; i++) {
        digitalWrite(stepX, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepX, LOW);
        delayMicroseconds(1000);
    }
    delay(1000);
}

void loop() {
    demiTour2();
}