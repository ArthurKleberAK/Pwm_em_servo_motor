#include <stdio.h> 
#include "pico/stdlib.h"
#include "pico/time.h" 
#include "hardware/pwm.h" 

//definição dos pinos e valores
#define SERVO_PIN 12
#define CLOCK_DIV 64.0 
#define TPWM 20000.0    
#define WRAP 39063

uint volatile slice_numero;

//Calcula o valor do duty cycle correspondente ao tempo T_ON
uint16_t calculate_duty_cycle(float T_ON){
    return (uint16_t)((T_ON / TPWM) * WRAP); //Converte T_ON para um valor proporcional ao WRAP.
}

//Converte o tempo T_ON em ciclo ativo e configura o PWM no pino do servo.
void servo_angulo(uint slice, float T_ON){
    uint16_t duty = calculate_duty_cycle(T_ON);
    pwm_set_gpio_level(SERVO_PIN, duty);      //define o ciclo ativo (Ton) 
}


int main(){
     stdio_init_all(); 

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
    slice_numero = pwm_gpio_to_slice_num(SERVO_PIN); //obter o canal PWM da GPIO


    pwm_set_clkdiv(slice_numero, CLOCK_DIV);
    pwm_set_wrap(slice_numero, WRAP);
    pwm_set_enabled(slice_numero, true);
   
    for(float ESTADO_TON = 500; ESTADO_TON <= 2400; ESTADO_TON += 5){
        servo_angulo(slice_numero, ESTADO_TON);
        sleep_ms(10);
    }
    printf("Angulo do servo motor em 180 graus");
    sleep_ms(1000);
    for(float ESTADO_TON = 2400; ESTADO_TON >= 1470; ESTADO_TON -= 5){
        servo_angulo(slice_numero, ESTADO_TON);
        sleep_ms(10);
    }
    printf("Angulo do servo motor em 90 graus");
    sleep_ms(1000);
    for(float ESTADO_TON = 1470; ESTADO_TON >= 500; ESTADO_TON -= 5){
        servo_angulo(slice_numero, ESTADO_TON);
        sleep_ms(10);
    }
    sleep_ms(1000);
    servo_angulo(slice_numero,500);

    printf("Angulo do servo motor em 0 graus");

    while(1){

        for(float ESTADO_TON = 500; ESTADO_TON <= 2400; ESTADO_TON += 5){
            servo_angulo(slice_numero, ESTADO_TON);
            sleep_ms(10);
        }

        for(float ESTADO_TON = 2400; ESTADO_TON >= 500; ESTADO_TON -= 5){
            servo_angulo(slice_numero, ESTADO_TON);
            sleep_ms(10);
        }
    }
}