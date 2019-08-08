#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led_azul(LED_BLUE_L);
DigitalOut led_verm_r(LED_RED_R,!false);
DigitalOut led_verm_l(LED_RED_L,!false);
DigitalOut led_verde_r(LED_GREEN_R,!false);
DigitalOut led_verde_l(LED_GREEN_L,!false);

// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);
// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
     for(int a=0; a<20; a++)
    {
        led_azul = !led_azul;
        wait(0.1);
    }
    // Turn on red LEDs indicating motors are armed
    led_verm_r=0;
    led_verm_l=0;
    wait(1.0);

    // Test all motors with different frequencies (to make different noises)
    for(int i=0; i<3; i++)
    { 
        //Motor1
        motor_1.period(1.0/550.0);
        motor_1=0.2;
        wait(0.05);
        motor_1=0.0;
        wait(0.15);

        //Motor2
        motor_2.period(1.0/660.0);
        motor_2=0.2;
        wait(0.05);
        motor_2=0.0;
        wait(0.15);

        //Motor3
        motor_3.period(1.0/440.0);
        motor_3=0.2;
        wait(0.05);
        motor_3=0.0;
        wait(0.15);

        //Motor4
        motor_4.period(1.0/880.0);
        motor_4=0.2;
        wait(0.05);
        motor_4=0.0;
        wait(0.15);
    }

    // Turn off red LEDs indicating motors are disarmed
    led_verm_r=1;
    led_verm_l=1;

    // Blink green LEDs indicating end of program
    while(1)
    {
        led_verde_l = !led_verde_l;
        led_verde_r = !led_verde_r;
        wait(0.1);
    }
}
