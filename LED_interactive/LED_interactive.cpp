#include <LED_interactive.h>

LED_interactive::LED_interactive(Adafruit_NeoPixel *leds){
	strip=leds; //Se le asigna al objeto la dirección de los LEDS
}
LED_interactive::~LED_interactive(){}

int LED_interactive::Leer_DatoI(){ //leer los datos enteros
	    int Dato;
	    while (Serial.available() == 0);//Espera a que exista un valor en el monitor
	    Dato = Serial.parseInt();//Lee el dato como entero
	    return Dato;   //Regresa el dato
}

float LED_interactive::Leer_DatoF(){//Lee los datos en flotante
	    float Dato;
	    while (Serial.available() == 0);//Espera a que exista un valor en el monitor
	    Dato = Serial.parseFloat();//Lee el dato como flotante
	    return Dato;  //Regresa el dato
	}

int* LED_interactive::Numero_pixeles(){//Menú para número de píxeles
    int resta, suma;
    static int F[]={0,0,0};
    Serial.println("¿Cuántos píxeles del color 1?");
    F[0]=Leer_DatoI();
    delay(50);
    Serial.print("Color 1: ");
    Serial.println(F[0]);
    delay(100);
    Serial.println("¿Cuántos píxeles del color 2?");
    F[1]=Leer_DatoI();
    Serial.print("Color 2: ");
    Serial.println(F[1]);
    delay(100);
    Serial.println("¿Cuántos píxeles del color 3?");
    F[2]=Leer_DatoI();
    Serial.print("Color 3: ");
    Serial.println(F[2]);
    suma = F[0] + F[1] + F[2];//Suma los pÃ­xeles
    delay(100);// Espera
    Serial.print("SUMA: ");
    Serial.println(suma);//Muestra la suma
    Serial.println(" ");
    Serial.println(" ");
    if (suma < 18) {//Compara si es menor a 18 
      resta = 18 - suma;
      Serial.print("Sobran: ");
      Serial.print(resta);//Muestra cuantos pÃ­xeles faltan
      Serial.println(" píxeles. Ingrese de nuevo los valores");
      Serial.println(" ");
      Serial.println(" ");
      Numero_pixeles();//Llama a la funciÃ³n para modificar el nÃºmero de pÃ­xeles
    }
    return F;
}

int* LED_interactive::Cambio_color1(){//Modifica los valores para el color 1
  static int ColorA[]={0,0,0};
  Serial.println("COLOR 1");
  for (int i = 0; i < 3; i++) {
    if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
    if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
    if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
    ColorA[i] = Leer_DatoI();
    Serial.println(ColorA[i]);//Muestra el valor
  }
  Serial.println(" ");
  return ColorA;
}

int* LED_interactive::Cambio_color2(){//Modifica los valores para el color 2
  static int ColorB[]={0,0,0};
  Serial.println("COLOR 2");
  for (int i = 0; i < 3; i++) {
    if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
    if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
    if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
    ColorB[i] = Leer_DatoI();
    Serial.println(ColorB[i]);//Muestra el valor
  }
  Serial.println(" ");
  return ColorB;
}

int* LED_interactive::Cambio_color3(){//Modifica los valores para el color 3
    static int ColorC[]={0,0,0};
    Serial.println("COLOR 3");
    for (int i = 0; i < 3; i++) {
        if (i == 0)Serial.print("Green: ");//Si i es 0 se muestra Green
        if (i == 1)Serial.print("Red: ");//Si i es 1 se muestra Red
        if (i == 2)Serial.print("Blue: ");//Si i es 2 se muestra Blue
        ColorC[i] = Leer_DatoI();
        Serial.println(ColorC[i]);//Muestra el valor
    }
    Serial.println(" ");
    return ColorC;
}
  

float LED_interactive::Retardo(){//Lee el valor de la velocidad para cada píxel
    float R=0.0;
    Serial.println("Ingresa la velocidad en segundos (máximo 2 segundos)");
    R=Leer_DatoF(); //Lee el dato de tipo flotante
    Serial.print(R);//Muestra el valor
	Serial.println(" Segundos");
	R = R * 1000;//Multiplica el valor por 1000 
	                //0.5*1000 = 500 , delay(500)=0.5seg
	return R;//Regresa el valor de segundos
}

void LED_interactive::Revolver(int A, int B, int C, int velocidad,int *Color1,int *Color2,int *Color3){
  int NP; //número del pixel
  int espera = 17; //variable para ciclo

  Serial.println("-_-_-_-_-_-_  INICIADO C: -_-_-_-_-_-_  ");
  Serial.println("-------->> Colores... \(^.^)/ ");
  Serial.println(" ");
  while (espera != 0) { //inicio de ciclo
    if (A > 0) { //Si A es mayor o igual que cero
      NP = random(0, 18); //Genera un nÃºmero aleatorio en la variable nÃºmero de pixel
      strip->setPixelColor(NP, strip->Color(Color1[0], Color1[1], Color1[2])); //Coloca el color en el pixel
      A = A - 1; //Decrementa la cantidad del color 1
      strip->show(); //Actualiza
      delay(velocidad);
    } //Espera
    if (B > 0) { //Si B es mayor o igual que cero
      NP = random(0, 18); //Genera un nÃºmero aleatorio en la variable nÃºmero de pixel
      strip->setPixelColor(NP, strip->Color(Color2[0], Color2[1], Color2[2])); //Coloca el color en el pixel
      B = B - 1; //Decrementa la cantidad del color 2
      strip->show(); //Actualiza
      delay(velocidad);
    } //Espera
    if (C > 0) { //Si C es mayor o igual que cero
      NP = random(0, 18); //Genera un nÃºmero aleatorio en la variable nÃºmero de pixel
      strip->setPixelColor(NP, strip->Color(Color3[0], Color3[1], Color3[2])); //Coloca el color en el pixel
      C = C - 1; //Decrementa la cantidad del color 2
      strip->show(); //Actualiza
      delay(velocidad);
    } //Espera
    espera = espera - 1; //Decrementa la variable espera
  }
  strip->clear(); //Pone todos los pixeles en la memoria a cero
  strip->show();  //Actualiza
}
