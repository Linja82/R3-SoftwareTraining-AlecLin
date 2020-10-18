# R3-SoftwareTraining-AlecLin
Software Training Module 1 for R3

# Hardware
[Tinkercad Circuit](https://www.tinkercad.com/things/4NrpbiozkF0)
![alt text](https://github.com/Linja82/R3-SoftwareTraining-AlecLin/blob/main/Images/Tinkercad%20Software%20Training%201.jpg)
Arduino controlled motor driver circuit.

This circuit uses an Arduino Uno to take input from the DIP switch and ouput to the L293D motor driver IC.  
- When no DIP switch is activated, the Arduino will send a stop signal to all 4 input pins of the IC  
  
- When DIP switch 1 is activated the Arduino will send a signal proportional to the potentiometer value to input pins 1 and 4 of the IC  
  
- When DIP switch 2 is activated the Arduino will send a signal proportional to the potentiometer value to input pins 2 and 3 of the IC  
  
- When DIP switch 3 is activated the Arduino will send a signal proportional to the potentiometer value to input pins 1 and 3 of the IC  
  
- When DIP switch 4 is activated the Arduino will send a signal proportional to the potentiometer value to input pins 2 and 4 of the IC
# Software

## ## Motor Speed Calculation
<img src="https://render.githubusercontent.com/render/math?math=/dfrac{Potentiometer Reading}{Potentiometer Max Value} * 255 = PWM Value">
  
