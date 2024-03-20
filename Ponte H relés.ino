/* C++ code
 *
 * Creamos un codigo para poder controlar o xiro do motor mediante unha ponte H simulada por relés.
 * No esquema tamén controlaremos a velocidade do motor, pero a nivel de código non se ten en conta
 * xa que actua directamente no motor físicamente.
 * Para que xire en un sentido activaranse os relés 1 e 4 (estado 2), para o outro sentido o 2 e 3
 * (estado 1), por ultimo para que estea parado, ningun relé se activa.
 *
 * Autor: Francisco Mos.
 * Data: Marzo 2024.
 *
*/ 

//Definimos entradas.
#define INT1 4
#define INT2 5
#define INT3 6
#define INT4 7

//Definimos salidas.
#define S1 8
#define S2 9
#define S3 10
#define S4 11

//Variables.
bool estado1 = 0;
bool estado2 = 0;


void setup(){
  //Declaramos as entradas.
  pinMode(INT1, INPUT);
  pinMode(INT2, INPUT);
  pinMode(INT3, INPUT);
  pinMode(INT4, INPUT);
  //Declaramos as salidas.
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  //Iniciamos o monitor serie.
  Serial.begin(9600);
}


void loop(){
  //Escribense contantemente os valores das variables.
  digitalWrite(S2, estado1);
  digitalWrite(S3, estado1);
  digitalWrite(S1, estado2);
  digitalWrite(S4, estado2);
  //Printeamos polo monitor serie os valores dos estados.
  Serial.print("estado1:"),Serial.println(estado1);
  Serial.print("estado2:"),Serial.println(estado2);
  //Canbio de valor das variables segun a posicion dos microruptores.
  if (digitalRead(INT1) == 0 && digitalRead(INT2) == 1 && digitalRead(INT3) == 1 && digitalRead(INT4) == 0){
    estado1 = 1;
    estado2 = 0;
  }
  if (digitalRead(INT1) == 1 && digitalRead(INT2) == 0 && digitalRead(INT3) == 0 && digitalRead(INT4) == 1){
    estado1 = 0;
    estado2 = 1;
  }
  if (digitalRead(INT1) == 0 && digitalRead(INT2) == 0 && digitalRead(INT3) == 0 && digitalRead(INT4) == 0){
    estado1 = 0;
    estado2 = 0;
  }
}
