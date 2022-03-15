#include <Adafruit_NeoPixel.h>

#define LED_PIN 5 //D1
#define LED_NUM 18 
#define cambio_color 4 //D2

int velocidad = A0;
int FA,FB,FC;
int j=1;

Adafruit_NeoPixel strip(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(cambio_color), colores, RISING);  
  strip.begin(); //Inicializa Neopixel
  strip.show(); //Apaga todos los pixeles
  strip.setBrightness(100); //Modifica el brillo de los pixeles
}

void loop() {
  
  while(j>0){
    secuencia(7,6,3); //Llama a la función secuencia y envía el valor de los colores
    j=j-1;
  }
  

}

void secuencia(int A,int B, int C){ //Funcion secuencia
  int NP; //número del pixel
  int espera=17; //variable para ciclo 
  
  while(espera>0){ //inicio de ciclo
  
  if(A>=0){ //Si A es mayor o igual que cero
    NP=random(0,17); //Genera un número aleatorio en la variable número de pixel
    strip.setPixelColor(NP, strip.Color(255, 36, 175)); //Coloca el color en el pixel
    A=A-1; //Decrementa la cantidad del color 1
    strip.show(); //Actualiza 
    delay(1000);
  } //Espera

  if(B>=0){ //Si A es mayor o igual que cero
    NP=random(0,17); //Genera un número aleatorio en la variable número de pixel
    strip.setPixelColor(NP, strip.Color(61, 243, 255)); //Coloca el color en el pixel
    B=B-1; //Decrementa la cantidad del color 2
    strip.show(); //Actualiza
    delay(1000);
  } //Espera

  if(C>=0){ //Si C es mayor o igual que cero
    NP=random(0,17); //Genera un número aleatorio en la variable número de pixel
    strip.setPixelColor(NP, strip.Color(255, 255, 65)); //Coloca el color en el pixel
    C=C-1; //Decrementa la cantidad del color 2
    strip.show(); //Actualiza
    delay(1000);
  } //Espera

  strip.clear(); //Pone todos los pixeles en la memoria a cero
  strip.show();  //Actualiza
  espera=espera-1; //Decrementa la variable espera
  }
  
}
