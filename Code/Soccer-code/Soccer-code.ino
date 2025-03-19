// CODIGO DE MOVIMIENTO PARA ROBOT SOCCER

#define PWMa 3  //Se define las variables a utilizar
#define AIN1 4
#define AIN2 5
#define STBY 6
#define BIN1 7
#define BIN2 8
#define PWMb 9

int instruction = "0";  //Se define la variable que almacena la instruccion

const int speedA = 255;  //Define la velocidad de los motores del par A
const int speedB = 255;  //Define la velocidad de los motores del par B

void setup() {
  Serial.begin(9600);  //Activa la comunicacion UART a 9600 baudios
  pinMode(PWMa, 1);   //Inicializan los pines de salida
  pinMode(AIN1, 1);
  pinMode(AIN2, 1);
  pinMode(STBY, 1);
  pinMode(BIN1, 1);
  pinMode(BIN2, 1);
  pinMode(PWMb, 1);

  digitalWrite(STBY,1);  //Inicializa el puente H
  analogWrite(PWMa, speedA);  //Establece la velocidad de los motores 
  analogWrite(PWMb, speedB);
}

void loop() {
  if(Serial.available()>0){  //Verifica si hay datos disponibles
    instruction = Serial.read();  //Lee la instrucción recibida
  }

  if(instruction == "1"){  //Instrucción para ADELANTE
    Move(1, 1, 0, 0);   
  }

  if(instruction == "2"){  //Instrucción para ATRÁS
    Move(0, 0, 1, 1);   
  }

  if(instruction == "3"){  //Instrucción para DERECHA
    Move(1, 0, 0, 1);  
  }

  if(instruction == "4"){  //Instrucción para IZQUIERDA
    Move(0, 1, 1, 0); 
  }

  if(instruction == "5"){  //Instrucción para ESTATICO
    Move(0, 0, 0, 0);
  }
}
//Funcion principal de MOVIMIENTO, basado en parámetros
void Move(const int SA1, const int SB1, const int SA2,const int SB2){
  digitalWrite(AIN1, SA1);
  digitalWrite(BIN1, SB1);
  digitalWrite(AIN2, SA2);
  digitalWrite(BIN2, SB2);
}