#ifndef _LED_INTERACTIVE_H
#define _LED_INTERACTIVE_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Adafruit_NeoPixel.h"

class LED_interactive {
private:
    /*data*/
    Adafruit_NeoPixel *strip;//Se crea un apuntador 
public://Funciones que estarán disponibles para librería
	LED_interactive(Adafruit_NeoPixel *leds);
	~LED_interactive();
	int Leer_DatoI(void);
	float Leer_DatoF(void);
	int* Numero_pixeles(void);
	int* Cambio_color1(void);
	int* Cambio_color2(void);
	int* Cambio_color3(void);
	float Retardo(void);
	void Revolver(int A, int B, int C,int velocidad,int *ColorA,int *ColorB,int *ColorC);

};

#endif // !LED_interactive_H
