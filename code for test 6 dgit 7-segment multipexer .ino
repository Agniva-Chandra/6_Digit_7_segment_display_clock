use this code for test multipex

// Define the segment pins
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

// Define the digit control pins (for 2 digits)
int digit1 = 9;  // Control for the first (left) digit
int digit2 = 10;
int digit3 = 11; // Control for the second (right) digit
int digit4 = 12;
int digit5 = A0;
int digit6 = A1;

void setup() {
  // Set all the segment pins and digit control pins as OUTPUT
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(digit6, OUTPUT);
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
  // Example: Display number 42 (4 on the first digit, 2 on the second digit)
  // Multiplexing: Turn on one digit at a time

  // Display '4' on the first digit
  digitalWrite(digit1, LOW);  // Activate first digit
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);  // Deactivate second digit
  displayDigit(8);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching digits
  clearSegments();

  // Display '2' on the second digit
  digitalWrite(digit1, HIGH); // Deactivate first digit
  digitalWrite(digit2, LOW); 
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);  // Activate second digit
  displayDigit(5);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching back
  clearSegments();

  
  // Display '2' on the second digit
  digitalWrite(digit1, LOW); // Deactivate first digit
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);   // Activate second digit
  displayDigit(0);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching back
  clearSegments();

   // Display '2' on the second digit
  digitalWrite(digit1, LOW); // Deactivate first digit
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, HIGH);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, LOW);   // Activate second digit
  displayDigit(9);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching back
  clearSegments();

  
   // Display '2' on the second digit
  digitalWrite(digit1, LOW); // Deactivate first digit
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, HIGH);
  digitalWrite(digit6, LOW);   // Activate second digit
  displayDigit(2);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching back
  clearSegments();

  
   // Display '2' on the second digit
  digitalWrite(digit1, LOW); // Deactivate first digit
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);
  digitalWrite(digit6, HIGH);   // Activate second digit
  displayDigit(6);
  delay(5);  // Short delay for persistence of vision

  // Clear the segments before switching back
  clearSegments();
}

rewrite with proper coments and what is the result 