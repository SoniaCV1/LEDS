//LIBRERIAS
#include <Adafruit_NeoPixel.h>
#include <LED_interactive.h>


// CONSTAMTES
#define LED_PIN 5 //D1
#define LED_NUM 18

//VARIABLES Y APUNTADORES
float velocidad = 0;
int *ColorA;
int *ColorB;
int *ColorC;
int *Frec;
int band = 0, var = 0;

//Declara la tira de LED's
Adafruit_NeoPixel strip(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);
LED_interactive fun(&strip);//Manda la dirección de la tira de LEDS

void setup() {
  Serial.begin(9600);//Comienza el puerto serial
  strip.begin(); //Inicializa Neopixel
  strip.show(); //Apaga todos los pixeles
  strip.setBrightness(250); //Modifica el brillo de los pixeles
}

void loop() {
  if (band == 0) {
    Serial.println("_-_-_-_-_-_-_-_-_-_-   BIENVENID@ :D _-_-_-_-_-_-_-_-_-_-");
    Frec = fun.Numero_pixeles(); //Llama a la función para modificar el número de píxeles
    ColorA = fun.Cambio_color1(); //Llama a la función para cambiar color
    ColorB = fun.Cambio_color2();
    ColorC = fun.Cambio_color3();
    velocidad = fun.Retardo(); //Modificación de velocidad
    fun.Revolver(Frec[0], Frec[1], Frec[2], velocidad, ColorA, ColorB, ColorC); //Llama a la función revolver y envía el número de píxeles
    band = 1;

  } else {
    Serial.println("¿Qué acción quieres realizar?");//Inicia menú
    Serial.println("1. Ingresar el número de pixeles");
    Serial.println("2. Cambiar colores");
    Serial.println("3. Cambiar velocidad");
    Serial.println("4. Ver LED's");
    Serial.println(" ");
    var =fun.Leer_DatoI();//Lee el dato
    
    switch (var) { //Compara el dato y llama a la función
      case 1:
        Frec = fun.Numero_pixeles(); //Llama a la función para modificar el número de píxeles
        break;
      case 2:
        ColorA = fun.Cambio_color1(); //Llama a la función para cambiar color
        ColorB = fun.Cambio_color2();
        ColorC = fun.Cambio_color3();
        break;
      case 3:
        velocidad = fun.Retardo();
      case 4:
        fun.Revolver(Frec[0], Frec[1], Frec[2], velocidad, ColorA, ColorB, ColorC);
      default: //En caso de ingresar otro número muestra el mensaje
        Serial.println("Opción no válida :'v");
        Serial.println(" ");
        break;
    }

  }

}
