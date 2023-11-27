int counter = 0;
int v2;
int v2_buffer = 0;
int pw0 = 0, pw1 = 0, pw2 = 0;

void setup() {
  pinMode(2,INPUT);
  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void state0() {
  counter = 0;
  pw0 = 0;
  pw1 = 0;
  pw2 = 0;
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void state1() {
  // Check the 1st input
  if (digitalRead(3) && digitalRead(4) && !(digitalRead(5)) && !(digitalRead(6))) {
    pw0 = 1; // If correct, set pw0 to 1
  } else {
    pw0 = 0; // If wrong, set pw0 to 0
  }
}

void state2() {
  // Check the 2nd input
  if (!digitalRead(3) && digitalRead(4) && (digitalRead(5)) && !(digitalRead(6))) {
    pw1 = 1;
  } else {
    pw1 = 0;
  }
}
void state3() {
  // Check the 3rd input
  if (digitalRead(3) && digitalRead(4) && (digitalRead(5)) && (digitalRead(6))) {
    pw2 = 1;
  } else {
    pw2 = 0;
  }

  // Check all the inputs
  if (pw0 && pw1 && pw2) {
    state4();
  } else {
    state5();
  }
  
}
void state4() {
  // Turn off all other LEDs except for the green LED
  for (int i = 3; i < 9; i++) {
    if (i != 7) {
      digitalWrite(i, LOW);
    } else {
      digitalWrite(i, HIGH);
    }    
  }
  delay(2000);
  state0();
}

void state5() {
  // Turn off all other LEDs except for the red LED
  for (int i = 3; i < 9; i++) {
    if (i != 8) {
      digitalWrite(i, LOW);
    } else {
      digitalWrite(i, HIGH);
    }    
  }
  delay(2000);
  state0();
}

void loop() {
  if (counter == 0) {
    state0();
  }
  // Get the voltage between photoresistor and resistor
  int photoresistor = analogRead(A0);
  // Serial.println(photoresistor);
  // Serial.println(counter);
  // Get potentiometer resistance indicator value (0 ~ 4095)
  int potentiometer = analogRead(A1);

  // Potentiometer controls the three blue LEDs
  for (int i = 4; i < 7; i++) {
    int potentiometerThreshold = map(i, 3, 7, 0, 4059);
    digitalWrite(i, potentiometer > potentiometerThreshold);
  }

  // Yellow LED indicates the current photoresistor's resistance
  if (photoresistor < 400) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  // Keep track of the number of button presses
  // Read the value of the D2 pin
  v2 = digitalRead(2);
  if (v2_buffer == 0 && v2 == 1) { // If a button is pressed
    counter += 1;
    Serial.println(counter);

    // For each state, do different things: 
    switch(counter) {
      // case 0: state0(); break;
      case 1: state1(); break;
      case 2: state2(); break;
      case 3: state3(); 
      // case 4: state4();
      // case 5: state5();
    }
  } 

  // Update v2_buffer value
  v2_buffer = v2;  

  delay(20);
}