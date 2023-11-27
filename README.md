# HW11
 
This week's homework is to create a password machine. I used a potentiometer, a photoresistor, and a button for password input. 

## Ideation
In my password machine, the potentiometer controls 3 blue LEDs and the photoresistor controls 1 yellow LED. As I turn the potentiometer from very left to very right, the 3 blue LEDs light up one by one. The yellow LED turns on when the photoresistor is not exposed to strong enough light. 

Each button press will input a password into the system. Upon 3 button presses, the password machine will validate the password sequence. If the sequence is correct, the green LED will light up. Else, the red LED will light up. Below is the password sequence I designed: 

* Turn on the yellow LED. Turn on the 1st blue LED. Press the button. 
* Turn off the yellow LED. Turn on the 1st and 2nd blue LEDs. Press the button.
* Turn on the yellow LED. Turn on all the blue LEDs. Press the button.

![](./imgs/correct-password-sequence.jpg)

Below is the Finite State Machine of my password machine. 

![](./imgs/FSM.jpg)

Below is the Circuit Diagram of my password machine. 

![](./imgs/circuit-diagram.jpg)

## Implementation


## Circuit Images
<p align="center">
  <img alt="Light" src="./imgs/1.jpg" width="45%">
&nbsp; &nbsp; &nbsp; &nbsp;
  <img alt="Dark" src="./imgs/2.jpg" width="45%">
</p>
<p align="center">
  <img alt="Light" src="./imgs/3.jpg" width="45%">
&nbsp; &nbsp; &nbsp; &nbsp;
  <img alt="Dark" src="./imgs/4.jpg" width="45%">
</p>
<p align="center">
  <img alt="Light" src="./imgs/5.jpg" width="45%">
</p>

## Video
<div align="center" style="width:50%;">
      <a href="https://www.youtube.com/watch?v=GPBdwgR1eQE">
         <img src="https://img.youtube.com/vi/GPBdwgR1eQE/0.jpg" style="width:50%;">
      </a>
</div>
