/*
  UNIVERSIDAD DEL VALLE DE GUATEMNALA
  DEPARTAMENTO DE INGENIERIA MECATRONICA, ELECTRONICA & BIOMEDICA
  ELECTRONICA DIGITAL 2
  LABORATORIO No.5 - JUEGO DE CARRERAS CON TIVA C.
  DANIEL GONZALEZ 
*/

// DEFINICIONES Y VARIABLES

#define J1_WIN PD_6   // DEFINIMOS LA EL PIN PD_6 COMO LA SALIDA PARA EL LED QUE MUESTRA LA VICTORIA DEL J1.       
#define J2_WIN PC_7   // DEFINIMOS LA EL PIN PD_6 COMO LA SALIDA PARA EL LED QUE MUESTRA LA VICTORIA DEL J2.

uint8_t a = 0;      // VARIABLE UTILIZADA COMO INDICE DEL ARREGLO DE LOS LEDs DEL J1.
uint8_t b = 0;      // VARIABLE UTILIZADA COMO INDICE DEL ARREGLO DE LOS LEDs DEL J2.
//uint8_t P1;
//uint8_t P2;
  
int J_1[] = {0, PA_6, PA_5, PB_4, PE_5, PE_4, PB_1, PB_0, PB_5};   // ARREGLO CON LAS SALIDAS PARA LOS LEDS DEL J1.
int J_2[] = {0, PB_2, PE_0, PC_4, PB_7, PB_6, PA_4, PA_3, PA_2};   // ARREGLO CON LAS SALIDAS PARA LOS LEDS DEL J2.

  
//------------------------- RUTINA DE CONFIGURACIONES -------------------------//  
void setup() {                
  
  // initialize the digital pin as an output:
  pinMode(RED_LED,   OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(J1_WIN,    OUTPUT);
  pinMode(J2_WIN,    OUTPUT);  

  for (uint8_t i = 0; i < 9; i++){
    pinMode(J_1[i], OUTPUT);}

  for (uint8_t e = 0; e < 9; e++){
    pinMode(J_2[e], OUTPUT);}

  // Configurando los botones como entradas con pullup:  
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);

  // RUTINA DE INCIO DE SEMAFORO:
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                   // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(GREEN_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(RED_LED, LOW);
  
  digitalWrite(GREEN_LED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                   // wait for a second
  digitalWrite(GREEN_LED, LOW);
}

//-------------------------- RUTINA DE LOOP INFINITO --------------------------//  
void loop() {

  while(a<9 && b<9){             // MIENTRAS NINGUNO DE LOS JUGADORES GANE
    digitalWrite(J_1[a], HIGH);  // ENCENDEMOS EL LED CONECTADO A LA SALIDA POSICIONADA EN J_1[a].
    digitalWrite(J_2[b], HIGH);  // ENCENDEMOS EL LED CONECTADO A LA SALIDA POSICIONADA EN J_2[b].

    if(digitalRead(PUSH1)== 0){        // REVISAMOS SI EL PULSADOR 1 ESTA PRESIONADO.
      delay(200);                      
      digitalWrite(J_1[a], LOW);       // APAGAMOS EL LED QUE ESTABA ENCENDIDO ANTERIORMENTE.
      if(a==8){                        // REVISAMOS SI EL JUGADOR 1 HA GANADO.
        digitalWrite(J1_WIN, HIGH);}   // ENCENDEMOS EL LED DE VICTORIA DEL J1.  
      a++;}                            // INCREMENTAMOS EL INDICE a.
    
    if(digitalRead(PUSH2)== 0){        // REVISAMOS SI EL PULSADOR 2 ESTA PRESIONADO.
      delay(200);                      
      digitalWrite(J_2[b], LOW);       // APAGAMOS EL LED QUE ESTABA ENCENDIDO ANTERIORMENTE.
      if(b==8){                        // REVISAMOS SI EL JUGADOR 2 HA GANADO.  
        digitalWrite(J2_WIN, HIGH);}   // ENCENDEMOS EL LED DE VICTORIA DEL J2.
      b++;}                            // INCREMENTAMOS EL INDICE b.  
      
      /*  
    if(digitalRead(PUSH1)== 0){ 
      delay(2);
      P1 = 1;
      if(digitalRead(PUSH1)== 1 && P1==1){       
        digitalWrite(J_1[a], LOW);
        if(a==8){
          digitalWrite(J1_WIN, HIGH);}
        a++;
        P1=0;}
      }
  
    if(digitalRead(PUSH2)== 0){ 
      delay(2);
      P2 = 1;
      if(digitalRead(PUSH2)== 1 && P2==1){       
        digitalWrite(J_2[b], LOW);
        if(b==8){
          digitalWrite(J2_WIN, HIGH);}
        b++;
        P2=0;}
      }*/
  }
}
