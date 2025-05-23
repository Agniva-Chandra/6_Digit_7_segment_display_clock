// Define the segment pins
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

// Define the digit control pins (for 6 digits)
int digit1 = 9;   // Control for first digit (Hours tens)
int digit2 = 10;  // Control for second digit (Hours units)
int digit3 = 11;  // Control for third digit (Minutes tens)
int digit4 = 12;  // Control for fourth digit (Minutes units)
int digit5 = A0;  // Control for fifth digit (Seconds tens)
int digit6 = A1;  // Control for sixth digit (Seconds units)

// Define switch pins
int switch1 = A2;  // Mode selection
int switch2 = A3;  // Time increase
int switch3 = A4;  // Time decrease
int ledPin = 13;



// Variables for time
unsigned long previousMillis = 0;  // Stores last time update
int hours = 0;
int minutes = 0;
int seconds = 0;

// Mode variable (0 = hours, 1 = minutes, 2 = seconds)
int mode = 0;

// Time interval for updating the clock (1000 ms = 1 second)
const long interval = 1000;



void setup() {
  // Set all the segment pins and digit control pins as OUTPUT
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  // Set digit control pins as OUTPUT
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(digit6, OUTPUT);

  pinMode(ledPin, OUTPUT);

  // Set switch pins as INPUT with internal pull-up resistors
  pinMode(switch1, INPUT_PULLUP);  // Mode selection
  pinMode(switch2, INPUT_PULLUP);  // Time increment
  pinMode(switch3, INPUT_PULLUP);  // Time decrement
}

// Function to display a digit (0-9) on a 7-segment display
void displayDigit(int digit) {
  switch (digit) {
    case 0: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); break;
    case 1: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 2: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, LOW); break;
    case 3: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); break;
    case 4: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
    case 5: digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
    case 6: digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
    case 7: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 8: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
    case 9: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); break;
  }
}

// Function to clear all segments (turn them off)
void clearSegments() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop() {
  // Handle switch presses for time setting
  handleSwitches();
  
  // Check if 1 second has passed
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    seconds++;

    if (seconds == 60) {
      seconds = 0;
      minutes++;
    }
    if (minutes == 60) {
      minutes = 0;
      hours++;
    }
    if (hours == 24) {
      hours = 0;
    }
  }

  // Display the time on the 7-segment display using multiplexing
  displayTime(hours, minutes, seconds);
}

// Function to handle time-setting via switches
void handleSwitches() {
  // Switch 1: Mode selection
  if (digitalRead(switch1) == LOW) {
    delay(200); // Debounce delay
    mode++;
    if (mode > 2) {
      mode = 0;  // Cycle through hours, minutes, and seconds
    }
  }

  // Switch 2: Increase time
  if (digitalRead(switch2) == LOW) {
    delay(200); // Debounce delay
    if (mode == 0) {
      hours = (hours + 1) % 24;  // Increment hours
    } else if (mode == 1) {
      minutes = (minutes + 1) % 60;  // Increment minutes
    } else if (mode == 2) {
      seconds = (seconds + 1) % 60;  // Increment seconds
    }
  }

  // Switch 3: Decrease time
  if (digitalRead(switch3) == LOW) {
    delay(200); // Debounce delay
    if (mode == 0) {
      hours = (hours - 1 + 24) % 24;  // Decrement hours, wrap at 0 to 23
    } else if (mode == 1) {
      minutes = (minutes - 1 + 60) % 60;  // Decrement minutes, wrap at 0 to 59
    } else if (mode == 2) {
      seconds = (seconds - 1 + 60) % 60;  // Decrement seconds, wrap at 0 to 59
    }
  }
}

// Function to display the time on the 7-segment display
void displayTime(int hours, int minutes, int seconds) {
 


  

  // Seconds tens
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);
  digitalWrite(ledPin, HIGH);
  displayDigit(seconds / 10);
  delay(5);
  clearSegments();

  // Seconds units
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);
  displayDigit(seconds % 10);
  delay(5);
  clearSegments();

  
  // Minutes tens
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, HIGH);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);
  displayDigit(minutes / 10);
  delay(5);
  clearSegments();

  // Minutes units
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);
  displayDigit(minutes % 10);
  delay(5);
  clearSegments();

   // Hours tens
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, HIGH);
  displayDigit(hours / 10);
  delay(5);
  clearSegments();

  
  // Hours units
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, HIGH);
  digitalWrite(digit6, LOW);
  displayDigit(hours % 10);
  delay(5);
  clearSegments();

}