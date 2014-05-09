/*
 * File:   main.c
 * Author: Ramazan Subasi (subram)
 *
 * Created on 22 Ocak 2014 Carsambai, 17:00
 */

#include <xc.h>

#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#define _XTAL_FREQ 4000000
#define ap GPIO0
#define bp GPIO1
#define cp GPIO2
#define dp GPIO4
#define ep GPIO5
int a, b, c, d, e, g;
int Intcount;

void interrupt t0() {

    if (Intcount < 255) {
        if (Intcount == a) {
            ap = 0;
        }
        if (Intcount == b) {
            bp = 0;
        }
        if (Intcount == c) {
            cp = 0;
        }
        if (Intcount == d) {
            dp = 0;
        }
        if (Intcount == e) {
            ep = 0;
        }

    } else if (Intcount == 255) {
        Intcount = 0;
        ap = 1;
        bp = 1;
        cp = 1;
        dp = 1;
        ep = 1;

    }
    Intcount++;
    TMR0 = 255;
    T0IF = 0;
}

int main() {
    CMCON = 0x07;
    ANSEL = 0x00;
    TRISIO = 0x00;
    OPTION_REG = 0b00000000;
    INTCON = 0b10100000;
    a = 40;
    b = 80;
    c = 120;
    d = 160;
    e = 200;
    Intcount = 0;
    while (1) {
    }

}

