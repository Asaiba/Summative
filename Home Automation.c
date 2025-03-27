#include <IRremote.h>

#define IR_PIN 2       // IR receiver connected to pin 2
#define RELAY_PIN 7    // Relay module connected to pin 7

bool lightState = false; // Track light state (OFF by default)

IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); // Light off initially
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); // Print IR code to Serial Monitor

        // Example: Adjust based on your remote's button codes
        if (results.value == 0xFF30CF) { // Example: Button 1 toggles the light
            lightState = !lightState;
            digitalWrite(RELAY_PIN, lightState ? HIGH : LOW);
        }

        irrecv.resume(); // Receive the next IR signal
    }
}
