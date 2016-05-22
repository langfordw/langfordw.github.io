//
//
// stepper_control_board_bipolar.c
// for use with stepper_control_board
//
// bipolar full stepping slave driver
// 
// Will Langford
// 04/10/13
// Updated from original code written by Neil Gershenfeld
//
// (c) Massachusetts Institute of Technology 2012
// Permission granted for experimental and personal use;
// license for commercial sale available from MIT.
//

#include <avr/io.h>
#include <util/delay.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define input(directions,pin) (directions &= (~pin))
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set

#define bridge_port PORTA // H-bridge port
#define bridge_direction DDRA // H-bridge direction
#define A2 (1 << PA1) // H-bridge output pins
#define A1 (1 << PA0) // "
#define B2 (1 << PA3) // "
#define B1 (1 << PA2) // "
#define step_port PORTB
#define step_pins PINB
#define step_direction DDRB
#define dir_port PORTB
#define dir_pins PINB
#define dir_direction DDRB
#define step_pin (1 << PB1)
#define dir_pin (1 << PB0)
#define on_delay() _delay_us(25) // PWM on time
#define off_delay() _delay_us(2) // PWM off time //@8V limits current to 470mA
#define PWM_count 35 // number of PWM cycles
#define step_count 200 // number of steps

static uint8_t count;
uint8_t step_val = 0;
int this_step = 0;

//
// A+ B+ PWM pulse
//
void pulse_ApBp() {
  clear(bridge_port, A2);
  clear(bridge_port, B2);
  set(bridge_port, A1);
  set(bridge_port, B1);
   for (count = 0; count < PWM_count; ++count) {
      set(bridge_port, A1);
      set(bridge_port, B1);
      on_delay();
      clear(bridge_port, A1);
      clear(bridge_port, B1);
      off_delay();
      }
    // set(bridge_port, A1);
    // set(bridge_port, B1);
   }
//
// A+ B- PWM pulse
//
void pulse_ApBm() {
  clear(bridge_port, A2);
  clear(bridge_port, B1);
  set(bridge_port, A1);
  set(bridge_port, B2);
   for (count = 0; count < PWM_count; ++count) {
      set(bridge_port, A1);
      set(bridge_port, B2);
      on_delay();
      clear(bridge_port, A1);
      clear(bridge_port, B2);
      off_delay();
      }
    // set(bridge_port, A1);
    // set(bridge_port, B2);
   }
//
// A- B+ PWM pulse
//
void pulse_AmBp() {
  clear(bridge_port, A1);
  clear(bridge_port, B2);
  set(bridge_port, A2);
  set(bridge_port, B1);
   for (count = 0; count < PWM_count; ++count) {
      set(bridge_port, A2);
      set(bridge_port, B1);
      on_delay();
      clear(bridge_port, A2);
      clear(bridge_port, B1);
      off_delay();
      }
   // set(bridge_port, A2);
   // set(bridge_port, B1);
   }
//
// A- B- PWM pulse
//
void pulse_AmBm() {
  clear(bridge_port, A1);
  clear(bridge_port, B1);
  set(bridge_port, A2);
  set(bridge_port, B2);
   for (count = 0; count < PWM_count; ++count) {
      set(bridge_port, A2);
      set(bridge_port, B2);
      on_delay();
      clear(bridge_port, A2);
      clear(bridge_port, B2);
      off_delay();
      }
    // set(bridge_port, A2);
    // set(bridge_port, B2);
   }
//
// clockwise step
//
void step_ccw() {
  this_step--;
  this_step = (this_step%4+4)%4;
   // pulse_ApBp();
   // pulse_AmBp();
   // pulse_AmBm();
   // pulse_ApBm();
   }
//
// counter-clockwise step
//
void step_cw() {
  this_step++;
  this_step = this_step%4;
   // pulse_ApBm();
   // pulse_AmBm();
   // pulse_AmBp();
   // pulse_ApBp();
   }

void step(step_num) {
  switch (step_num) {
    case 0:
      pulse_ApBm();
      break;
    case 1:
      pulse_AmBm();
      break;
    case 2:
      pulse_AmBp();
      break;
    case 3:
      pulse_ApBp();
      break;
  }
}

int main(void) {
   //
   // main
   //
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize bridge pins
   //
   clear(bridge_port, A1);
   output(bridge_direction, A1);
   clear(bridge_port, A2);
   output(bridge_direction, A2);
   clear(bridge_port, B1);
   output(bridge_direction, B1);
   clear(bridge_port, B2);
   output(bridge_direction, B2);

   set(dir_port, dir_pin);  // turn on pullups
   set(step_port, step_pin);
   input(dir_direction, dir_pin);
   input(step_direction, step_pin);

   //
   // main loop
   //
   while (1) {
      // set(bridge_port,B2);
      // clear(bridge_port,B1);
      // clear(bridge_port,A2);
      // clear(bridge_port,A1);
      // step_ccw();

      if (pin_test(step_pins,step_pin) != step_val) {
         step_val = pin_test(step_pins,step_pin);
        if (pin_test(dir_pins, dir_pin)) {
          step_cw();
        } else {
          step_ccw();
        }
      }
      step(this_step);
      // _delay_us(50);

      // if (pin_test(step_pins,step_pin) != step_val) {
      //    step_val = pin_test(step_pins,step_pin);
      //   if (pin_test(dir_pins, dir_pin)) {
      //     step_cw();
      //   } else {
      //     step_ccw();
      //   }
      // }
    }
  }
