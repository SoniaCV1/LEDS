#include <Adafruit_NeoPixel.h>

#define LED_PIN 5 //D1
#define LED_NUM 18 //Número de pixeles
#define BA 14 //D5
#define BR 12 //D6

int Colores[13][3] = {{235, 12, 12},
                      {235, 135, 12},
                      {247, 241, 22},
                      {175, 247, 22},
                      {12, 197, 9},
                      {21, 236, 142},
                      {21, 236, 203},
                      {19, 180, 234},
                      {8, 29, 213},
                      {144, 8, 213},
                      {246, 28, 174},
                      {246, 28, 112},
                      {248, 64, 99}};
int num_pix = 0; //Numero de pixel
int boton_avanzar,boton_retroceder; 
int i = 0, contador_avanza,contador_retrocede;
Adafruit_NeoPixel strip(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);       //Inicializa el puerto serial
  pinMode(BA, INPUT);       //Declara pin como entrada
  pinMode(BR, INPUT);       //Declara pin como entrada
  strip.begin();            //Inicializa Neopixel
  strip.show();             //Apaga todos los pixeles
  strip.setBrightness(250); //Modifica el brillo de los pixeles
}

void loop() {
  //................Avanzar...................
  boton_avanzar = digitalRead(BA);      //Lee el valor del pin 
  delay(200);                           //Retardo
  if (boton_avanzar == HIGH) {          //Si el botón es presionado
    contador_avanza++;                  //Aumenta contador
    Serial.println(contador_avanza);    //Muestra el valor del contador
  }else if(boton_avanzar==LOW){         //Si se deja de presionar el botón
    contador_avanza=0;                  //Manten el contador en cero
  }
  if(contador_avanza==1){               //Si el contador es 1 
     Avanzar();                         //Llama a la función avanza
  }else if(contador_avanza>1){          //Si el contador es mayor a 1 
     Cambiar_color();                   //Llama a la función para cambiar color del pixel
  }
  //.............. Retroceder................
  boton_retroceder = digitalRead(BR);   //Lee el valor del pin 
  delay(200);                           //Retardo
  if (boton_retroceder == HIGH) {       //Si el botón es presionado
    contador_retrocede++;               //Aumenta contador
    Serial.println(contador_retrocede); //Muestra el valor del contador
  }else if(boton_retroceder==LOW){      //En caso de no presional el boton
    contador_retrocede=0;               //Manten el contador en cero 
  }
  if(contador_retrocede==1){            //Si el contador vale uno
     Retroceder();                      //Llama a la función retrocede
  }else if(contador_retrocede>1){       //En caso de que el contador sea mayor a uno
     Cambiar_color();                   //Llama a la función para cambiar color del pixel
  }
  
  Parpadear();
}

void Avanzar() {
  Serial.println("Avanza");                                                                 //Muestra Avanza en el monitor serial
  strip.setPixelColor(num_pix, strip.Color(Colores[i][0], Colores[i][1], Colores[i][2]));   //Coloca en pixel el color
  strip.show();                                                                             //Muestra en el pixel el color
  num_pix++;                                                                                //Incrementa el número de pixel
  if (num_pix == 19) {                                                                      //Si el pixel es 19 
     num_pix = 0;                                                                           //Regresa al pixel cero
     strip.clear();                                                                         //Limpia el color de los pixeles
     strip.show();                                                                          //Muestra en los pixeles
  }
}

void Retroceder() {
  Serial.println("Retrocede");                                                              //Muestra Retrocede en el monitor serial
  strip.setPixelColor(num_pix, strip.Color(Colores[i][0], Colores[i][1], Colores[i][2]));   //Coloca en pixel el color
  strip.show();                                                                             //Muestra en el pixel el color
  num_pix--;                                                                                //Decrementa el número de pixel
  if (num_pix==0) {                                                                         //Si el pixel es 0
     num_pix = 17;                                                                          //Regresa al último pixel 
     strip.clear();                                                                         //Limpia el color de los pixeles
     strip.show();                                                                          //Muestra en los pixeles
  }
}

void Cambiar_color() {
  Serial.println("Cambio de color");                                                        //Muestra Cambio de color en el monitor serial
  if (i == 13) {                                                                            //Si el elemento es 13 en la matriz
    i = 0;                                                                                  //Pon el elemento 0
  } else {                                                                                  //De lo contrario
    strip.setPixelColor(num_pix, strip.Color(Colores[i][0], Colores[i][1], Colores[i][2])); //Pon el color en el pixel
    strip.show();                                                                           //Muestra el color
    delay(700);                                                                             //Espera
    i++;                                                                                    //Incrementa para el color siguiente
  }
}

void Parpadear(){
  strip.setPixelColor(num_pix, strip.Color(Colores[i][0], Colores[i][1], Colores[i][2]));   //Coloca el color en el pixel
  strip.show();                                                                             //Muestra el color
  delay(250);                                                                               //Espera 
  strip.setPixelColor(num_pix, strip.Color(0,0,0));                                         //Coloca el pixel sin color
  strip.show();                                                                             //Muestra el pixxel apagado
  delay(250);                                                                               //Espera
}
