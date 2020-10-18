/*
 * R3 Training 1 Software
 * @author Alec Lin
 * @date Oct 18, 2020 1:50 AM
 * 
 * This program allows 4 DIP switches and a potentiometer to control 2 motors
 * DIP switch 1 drives forward
 * DIP switch 2 drives backwards
 * DIP switch 3 turns right
 * DIP switch 4 turns left
 */
 
/* Wiring
 * D2: DIP Switch 1
 * D3: L293D Input 1
 * D4: DIP Switch 2
 * D5: L293D Input 2
 * D7: DIP Switch 3
 * D8: DIP Switch 4
 * D9: L293D Input 3
 * D10: L293D Input 4
 * A0: 250K Potentiometer
 */

#define DIP1 2
#define DIP2 4
#define DIP3 7
#define DIP4 8
#define POTPIN 0

#define L293D1 3
#define L293D2 5
#define L293D3 9
#define L293D4 10

float potVal;                         // Variable to store the potentiometer value   
float outputSpeed;                    // Variable to store the calculated pwm value
int stopSpeed = 0;                    // Variable to store pwm value for motor stop

void drive();                         // Prototype Function for the drive logic

void setup()
{
  /* 
   * Set the pins for the DIP switches to input pullup mode.
   * INPUT_PULLUP activates the Arduino's built in pull up resistor
   * 
   * Set the pins connected to the L293D to output mode
   */
  pinMode(DIP1, INPUT_PULLUP); 
  pinMode(DIP2, INPUT_PULLUP);
  pinMode(DIP3, INPUT_PULLUP);
  pinMode(DIP4, INPUT_PULLUP);
  pinMode(L293D1, OUTPUT);
  pinMode(L293D2, OUTPUT);
  pinMode(L293D3, OUTPUT);
  pinMode(L293D4, OUTPUT);
}

void loop()
{
  potVal = analogRead(POTPIN);        // Reads the analog value from the potentiometer
  outputSpeed = (potVal/1023) * 255;  // Converts the analog pot value to a decimal percentage, then converts the percentage to a range within 0-255
  drive();                            // Function containing drive logic
}

void drive()                          // Drive logic
{
  if (digitalRead(DIP1) == LOW)       // Drive straight when DIP switch 1 is activated
  {
    analogWrite(L293D1, outputSpeed); // Outputs a PWM signal with a duty cycle equal to outputSpeed to input pin 1 on the L293D
    analogWrite(L293D2, stopSpeed);   // Outputs a PWM signal with a duty cycle equal to stopSpeed (0) to input pin 2 on the L293D
    analogWrite(L293D3, stopSpeed);   // Outputs a PWM signal with a duty cycle equal to stopSpeed (0) to input pin 3 on the L293D
    analogWrite(L293D4, outputSpeed); // Outputs a PWM signal with a duty cycle equal to outputSpeed to input pin 4 on the L293D
  }
  else if (digitalRead(DIP2) == LOW)  // Drive backwards when DIP switch 2 is activated
  {
    analogWrite(L293D1, stopSpeed);
    analogWrite(L293D2, outputSpeed);
    analogWrite(L293D3, outputSpeed);
    analogWrite(L293D4, stopSpeed);
  }
  else if (digitalRead(DIP3) == LOW)  // Turn right when DIP switch 3 is activated
  {
    analogWrite(L293D1, outputSpeed);
    analogWrite(L293D2, stopSpeed);
    analogWrite(L293D3, outputSpeed);
    analogWrite(L293D4, stopSpeed);
  }
  else if (digitalRead(DIP4) == LOW)  // Turn left when DIP switch 4 is activated
  {
    analogWrite(L293D1, stopSpeed);
    analogWrite(L293D2, outputSpeed);
    analogWrite(L293D3, stopSpeed);
    analogWrite(L293D4, outputSpeed);
  }
  else                                // When no DIP switch is set, the motors will stop
  {
    analogWrite(L293D1, stopSpeed);
    analogWrite(L293D2, stopSpeed);
    analogWrite(L293D3, stopSpeed);
    analogWrite(L293D4, stopSpeed);
  }
}
