//LIBRERIAS
#include <Adafruit_NeoPixel.h>
// CONSTAMTES
#define LED_PIN 5 //D1
#define LED_NUM 18

//VARIABLES
float velocidad = 0;
int ColorA[] = {0, 0, 0};
int ColorB[] = {0, 0, 0};
int ColorC[] = {0, 0, 0};
int F[] = {0, 0, 0};
int CC = 0;
int band = 0, var = 0;

//inicializando la tira de LED's
Adafruit_NeoPixel strip(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin(); //Inicializa Neopixel
  strip.show(); //Apaga todos los pixeles
  strip.setBrightness(250); //Modifica el brillo de los pixeles
}

void loop() {
  if (band == 0) {
    Serial.println("_-_-_-_-_-_-_-_-_-_-   BIENVENID@ :D _-_-_-_-_-_-_-_-_-_-");
    numero_pixeles();//Llama a la función para modificar el número de píxeles
    cambio_color();//Llama a la función para cambiar color
    velocidad = Retardo(); //Modificación de velocidad
    revolver(F[0], F[1], F[2]);//Llama a la función revolver y envía el número de píxeles
    band = 1;

  } else {
    Serial.println("¿Qué acción quieres realizar?");//Inicia menú
    Serial.println("1. Ingresar el número de pixeles");
    Serial.println("2. Cambiar colores");
    Serial.println("3. Cambiar velocidad");
    Serial.println("4. Ver LED's");
    Serial.println(" ");
    while (Serial.available() == 0);//Espera a que exista un dato ingresado en el monitor
    var = Serial.parseInt();//Lee el dato
    switch (var) { //Compara el dato y llama a la función
      case 1:
        numero_pixeles();
        break;
      case 2:
        cambio_color();
        break;
      case 3:
        velocidad = Retardo();
      case 4:
        revolver(F[0], F[1], F[2]);
      default: //En caso de ingresar otro número muestra el mensaje
        Serial.println("Opción no válida :'v");
        Serial.println(" ");
        break;
    }

  }

}

//-_-_-_-_-_-_-_-_-_-_-  NUMERO DE PIXELES _-_-_-_-_-_-_-_-_-_-
void numero_pixeles() {//Lee los datos del no. de píxeles
  int resta, suma;
  Serial.println("¿Cuantos pixeles del color 1?");
  while (Serial.available() == 0);
  F[0] = Serial.parseInt();
  delay(50);
  Serial.print("Color 1: ");
  Serial.println(F[0]);
  delay(100);
  Serial.println("¿Cuantos píxeles del color 2?");
  while (Serial.available() == 0);
  F[1] = Serial.parseInt();
  Serial.print("Color 2: ");
  Serial.println(F[1]);
  delay(100);
  Serial.println("¿Cuantos píxeles del color 3?");
  while (Serial.available() == 0);
  F[2] = Serial.parseInt();
  Serial.print("Color 3: ");
  Serial.println(F[2]);
  suma = F[0] + F[1] + F[2];//Suma los píxeles
  delay(100);// Espera
  Serial.print("SUMA: ");
  Serial.println(suma);//Muestra la suma
  Serial.println(" ");
  Serial.println(" ");
  if (suma < 18) {//Compara si es menor a 18 
    resta = 18 - suma;
    Serial.print("Sobran: ");
    Serial.print(resta);//Muestra cuantos píxeles faltan
    Serial.println(" pixeles ingrese de nuevo los valores");
    Serial.println(" ");
    Serial.println(" ");
    numero_pixeles();//Llama a la función para modificar el número de píxeles
  }

}
//_-_-_-_-_-_-_-_-_-_- CAMBIO DE COLOR _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void cambio_color() {
  Serial.println("CAMBIAR COLOR");
  Serial.println(" ");
  Serial.println("Color 1");//Inicio para ingresar valores de Color 1
  for (int i = 0; i < 3; i++) {
    if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
    if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
    if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
    while (Serial.available() == 0); //Espera un valor en el monitor serie
    ColorA[i] = Serial.parseInt();//Lee el valor
    Serial.println(ColorA[i]);//Muestra el valor
  }
  Serial.println(" ");
  Serial.println("Color 2");//Inicio para ingresar valores de Color 2
  for (int i = 0; i < 3; i++) {
    if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
    if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
    if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
    while (Serial.available() == 0);//Espera un valor en el monitor serie
    ColorB[i] = Serial.parseInt();//Lee el valor
    Serial.println(ColorB[i]);//Muestra el valor
  }
  Serial.println(" ");
  Serial.println("Color 3");//Inicio para ingresar valores de Color 3
  for (int i = 0; i < 3; i++) {
    if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
    if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
    if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
    while (Serial.available() == 0);//Espera un valor en el monitor serie
    ColorC[i] = Serial.parseInt();//Lee el valor
    Serial.println(ColorC[i]);//Muestra el valor
  }
  Serial.println(" ");
}
//_-_-_-_-_-_-_-_-_-_- CAMBIO DE VELOCIDAD _-_-_-_-_-_-_-_-_-_-
float Retardo() { //Inicia función para ingresar la velocidad
  float R;
  Serial.println("Ingresa la velocidad en segundos (máximo 2 segundos)");
  while (Serial.available() == 0);//Espera un valor en el monitor serie
  R = Serial.parseFloat();//Lee el valor
  Serial.print(R);//Muestra el valor
  Serial.println(" Segundos");
  Serial.println(" ");
  R = R * 1000;//Multiplica el valor por 1000 
               //0.5*1000 = 500 , delay(500)=0.5seg
  return R;//Regresa el valor de segundos
}

//_-_-_-_-_-_-_-_-_-_- REVOLVER _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void revolver(int A, int B, int C) { //Funcion secuencia
  int NP; //número del pixel
  int espera = 17; //variable para ciclo

  Serial.print("-_-_-_-_-_-_  INICIADO C: -_-_-_-_-_-_  ");
  Serial.println("Colores...");
  Serial.println(" ");
  Serial.println(F[0]);
  Serial.println(F[1]);
  Serial.println(F[2]);
  while (espera != 0) { //inicio de ciclo
    if (A > 0) { //Si A es mayor o igual que cero
      NP = random(0, 18); //Genera un número aleatorio en la variable número de pixel
      strip.setPixelColor(NP, strip.Color(ColorA[0], ColorA[1], ColorA[2])); //Coloca el color en el pixel
      A = A - 1; //Decrementa la cantidad del color 1
      strip.show(); //Actualiza
      delay(velocidad);
    } //Espera
    if (B > 0) { //Si B es mayor o igual que cero
      NP = random(0, 18); //Genera un número aleatorio en la variable número de pixel
      strip.setPixelColor(NP, strip.Color(ColorB[0], ColorB[1], ColorB[2])); //Coloca el color en el pixel
      B = B - 1; //Decrementa la cantidad del color 2
      strip.show(); //Actualiza
      delay(velocidad);
    } //Espera
    if (C > 0) { //Si C es mayor o igual que cero
      NP = random(0, 18); //Genera un número aleatorio en la variable número de pixel
      strip.setPixelColor(NP, strip.Color(ColorC[0], ColorC[1], ColorC[2])); //Coloca el color en el pixel
      C = C - 1; //Decrementa la cantidad del color 2
      strip.show(); //Actualiza
      delay(velocidad);
    } //Espera
    espera = espera - 1; //Decrementa la variable espera
  }
  strip.clear(); //Pone todos los pixeles en la memoria a cero
  strip.show();  //Actualiza
}
