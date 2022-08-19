// TRIBUTO A DIEGO AUGUSTO E ERIVALDO JUNIOR QUE DERAM APOIO MORAL ENQUANTO EU FAZIA O CODIGO

#include <Servo.h>

Servo servo1, servo2, caneta; // servo 1, 2 e caneta de acordo com a biblioteca <Servo.h>
int tamanhoDoElo1 = 5; // tamanho do servo 1
int tamanhoDoElo2 = 8; // tamanho do servo 2
float atualAnguloDoServo1 = 0; // atual angulo do servo 1
float atualAnguloDoServo2 = 0; // atual angulo do servo 2
float resultadoDaCinematicaInversaDoServo1 = 0; // resultado da cinematica do servo 1 que varia de 0 a 180
float resultadoDaCinematicaInversaDoServo2 = 0; // resultado da cinematica do servo 2 que varia de 0 a 180
float pontosDoDesenho[]={
-9.44, 7.35,-9.38, 7.37,-9.40, 7.43,-9.31, 7.48,-9.24, 7.51,-9.17, 7.53,-9.09, 7.52,-9.01, 7.51,-8.97, 7.46,-8.90, 7.43,-8.86, 7.38,-8.78, 7.33,
-8.70, 7.25,-8.70, 7.19,-8.63, 7.17,-8.63, 7.11,-8.55, 7.09,-8.55, 7.01,-8.47, 6.97,-8.49, 6.93,-8.43, 6.87,-8.39, 6.82,-8.36, 6.75,-8.32, 6.67,
-8.28, 6.57,-8.24, 6.48,-8.20, 6.39,-8.16, 6.32,-8.09, 6.29,-8.01, 6.25,-7.93, 6.25,-7.85, 6.26,-7.78, 6.27,-7.70, 6.29,-7.62, 6.31,-7.55, 6.34,
-7.46, 6.40,-7.41, 6.41,-7.38, 6.48,-7.33, 6.49,-7.31, 6.56,-7.26, 6.57,-7.24, 6.64,-7.19, 6.72,-7.14, 6.77,-7.11, 6.84,-7.08, 6.96,-7.04, 7.07,
-7.02, 7.15,-7.02, 7.23,-7.02, 7.31,-7.01, 7.37,-7.00, 7.47,-6.99, 7.59,-6.99, 7.67,-6.99, 7.75,-6.99, 7.83,-6.99, 7.91,-6.99, 7.99,-7.01, 8.08,
-7.01, 8.15,-7.01, 8.23,-7.01, 8.31,-6.99, 8.39,-6.99, 8.47,-6.99, 8.55,-6.99, 8.63,-6.99, 8.71,-6.97, 8.78,-6.97, 8.86,-6.97, 8.94,-6.96, 9.04,
-6.95, 9.16,-6.95, 9.24,-6.95, 9.32,-6.95, 9.40,-6.92, 9.48,-6.89, 9.61,-6.84, 9.68,-6.79, 9.70,-6.77, 9.76,-6.72, 9.74,-6.70, 9.80,-6.62, 9.80,
-6.54, 9.79,-6.46, 9.74,-6.41, 9.68,-6.39, 9.60,-6.39, 9.52,-6.39, 9.44,-6.39, 9.36,-6.37, 9.28,-6.37, 9.20,-6.37, 9.12,-6.37, 9.04,-6.37, 8.96,
-6.37, 8.88,-6.37, 8.79,-6.37, 8.71,-6.37, 8.63,-6.37, 8.55,-6.37, 8.47,-6.37, 8.39,-6.37, 8.31,-6.37, 8.23,-6.37, 8.15,-6.37, 8.07,-6.35, 7.99,
-6.35, 7.92,-6.33, 7.83,-6.33, 7.75,-6.33, 7.67,-6.33, 7.59,-6.33, 7.51,-6.33, 7.43,-6.31, 7.36,-6.27, 7.30,-6.19, 7.29,-6.11, 7.32,-6.06, 7.33,
-6.06, 7.39,-6.03, 7.48,-6.00, 7.60,-5.96, 7.72,-5.96, 7.79,-5.94, 7.87,-5.92, 7.96,-5.92, 8.03,-5.92, 8.11,-5.91, 8.19,-5.89, 8.25,-5.88, 8.35,
-5.84, 8.47,-5.80, 8.60,-5.76, 8.72,-5.73, 8.84,-5.69, 8.96,-5.67, 9.04,-5.65, 9.12,-5.64, 9.20,-5.61, 9.28,-5.58, 9.41,-5.58, 9.48,-5.53, 9.56,
-5.49, 9.68,-5.44, 9.70,-5.42, 9.76,-5.35, 9.80,-5.27, 9.80,-5.19, 9.80,-5.11, 9.74,-5.08, 9.67,-5.03, 9.60,-5.04, 9.51,-5.07, 9.40,-5.09, 9.32,
-5.11, 9.24,-5.15, 9.12,-5.18, 9.00,-5.23, 8.90,-5.26, 8.75,-5.29, 8.67,-5.30, 8.55,-5.33, 8.47,-5.33, 8.39,-5.35, 8.31,-5.36, 8.23,-5.38, 8.11,
-5.40, 8.03,-5.40, 7.95,-5.42, 7.83,-5.42, 7.73,-5.44, 7.67,-5.44, 7.59,-5.44, 7.51,-5.46, 7.43,-5.46, 7.36,-5.49, 7.24,-5.52, 7.15,-5.50, 7.05,
-5.42, 6.99,-5.36, 7.01,-5.35, 7.07,-5.31, 7.15,-5.27, 7.23,-5.23, 7.31,-5.18, 7.40,-5.15, 7.51,-5.09, 7.55,-5.08, 7.63,-5.03, 7.71,-4.98, 7.73,
-4.96, 7.80,-4.91, 7.88,-4.86, 7.93,-4.84, 8.00,-4.81, 8.08,-4.77, 8.17,-4.73, 8.27,-4.69, 8.35,-4.65, 8.43,-4.61, 8.51,-4.57, 8.59,-4.54, 8.67,
-4.50, 8.75,-4.45, 8.84,-4.40, 8.90,-4.37, 8.96,-4.32, 8.94,-4.30, 9.00,-4.23, 9.00,-4.19, 8.94,-4.15, 8.98,-4.11, 8.91,-4.07, 8.84,-4.05, 8.71,
-4.07, 8.63,-4.10, 8.52,-4.14, 8.40,-4.19, 8.31,-4.23, 8.23,-4.26, 8.15,-4.30, 8.07,-4.34, 7.99,-4.38, 7.91,-4.42, 7.81,-4.46, 7.71,-4.50, 7.61,
-4.54, 7.51,-4.57, 7.43,-4.61, 7.32,-4.65, 7.23,-4.68, 7.12,-4.73, 7.01,-4.77, 6.91,-4.81, 6.83,-4.84, 6.75,-4.88, 6.67,-4.91, 6.55,-4.94, 6.47,
-4.92, 6.39,-4.92, 6.32,-4.88, 6.25,-4.81, 6.18,-4.73, 6.18,-4.67, 6.17,-4.65, 6.23,-4.57, 6.29,-4.50, 6.32,-4.46, 6.39,-4.40, 6.37,-4.37, 6.44,
-4.30, 6.49,-4.22, 6.56,-4.15, 6.61,-4.09, 6.61,-4.07, 6.68,-4.01, 6.69,-3.99, 6.76,-3.94, 6.77,-3.91, 6.84,-3.86, 6.85,-3.83, 6.92,-3.78, 6.93,
-3.76, 7.00,-3.71, 7.01,-3.68, 7.08,-3.63, 7.09,-3.61, 7.15,-3.53, 7.19,-3.45, 7.23,-3.38, 7.25,-3.30, 7.24,-3.22, 7.19,-3.18, 7.11,-3.17, 7.03,
-3.18, 6.95,-3.22, 6.87,-3.26, 6.79,-3.28, 6.73,-3.33, 6.72,-3.36, 6.65,-3.42, 6.61,-3.44, 6.53,-3.49, 6.52,-3.51, 6.45,-3.56, 6.44,-3.59, 6.37,
-3.65, 6.37,-3.72, 6.29,-3.80, 6.23,-3.82, 6.17,-3.87, 6.16,-3.90, 6.09,-3.95, 6.08,-4.03, 6.01,-4.11, 5.95,-4.13, 5.89,-4.18, 5.88,-4.21, 5.81,
-4.26, 5.80,-4.34, 5.73,-4.42, 5.65,-4.49, 5.56,-4.52, 5.49,-4.57, 5.48,-4.59, 5.39,-4.64, 5.36,-4.67, 5.29,-4.72, 5.24,-4.75, 5.17,-4.80, 5.12,
-4.84, 5.03,-4.88, 4.95,-4.92, 4.87,-4.96, 4.79,-5.00, 4.71,-5.02, 4.63,-5.07, 4.60,-5.09, 4.51,-5.15, 4.48,-5.19, 4.40,-5.21, 4.33,-5.26, 4.32,
-5.31, 4.24,-5.33, 4.17,-5.38, 4.16,-5.40, 4.09,-5.46, 4.08,-5.48, 4.01,-5.53, 4.00,-5.56, 3.93,-5.61, 3.92,-5.69, 3.84,-5.77, 3.77,-5.84, 3.68,
-5.88, 3.55,-5.91, 3.49,-5.87, 3.43,-5.87, 3.35,-5.85, 3.27,-5.85, 3.20,-5.81, 3.09,-5.81, 3.01,-5.79, 2.91,-5.77, 2.84,-5.85, 2.83,-5.92, 2.83,
-6.00, 2.83,-6.08, 2.83,-6.16, 2.83,-6.23, 2.83,-6.31, 2.83,-6.39, 2.83,-6.46, 2.83,-6.54, 2.83,-6.62, 2.83,-6.70, 2.83,-6.77, 2.83,-6.85, 2.83,
-6.93, 2.83,-7.01, 2.83,-7.08, 2.83,-7.16, 2.83,-7.24, 2.83,-7.31, 2.83,-7.39, 2.83,-7.41, 2.99,-7.43, 3.07,-7.43, 3.15,-7.45, 3.23,-7.45, 3.31,
-7.45, 3.39,-7.45, 3.47,-7.49, 3.53,-7.47, 3.57,-7.49, 3.67,-7.53, 3.73,-7.51, 3.77,-7.53, 3.87,-7.55, 3.95,-7.56, 4.03,-7.58, 4.11,-7.60, 4.19,
-7.66, 4.25,-7.74, 4.29,-7.82, 4.33,-7.91, 4.37,-7.89, 4.41,-7.97, 4.43,-7.97, 4.49,-8.04, 4.53,-8.09, 4.59,-8.12, 4.66,-8.16, 4.71,-8.20, 4.79,
-8.24, 4.87,-8.28, 4.95,-8.32, 5.03,-8.36, 5.11,-8.39, 5.19,-8.43, 5.27,-8.47, 5.35,-8.51, 5.43,-8.55, 5.51,-8.59, 5.59,-8.63, 5.69,-8.68, 5.77,
-8.66, 5.81,-8.70, 5.91,-8.76, 5.97,-8.74, 6.01,-8.78, 6.10,-8.82, 6.16,-8.84, 6.23,-8.90, 6.27,-8.90, 6.33,-8.97, 6.41,-9.01, 6.47,-9.05, 6.55,
-9.09, 6.63,-9.13, 6.72,-9.17, 6.80,-9.21, 6.88,-9.24, 6.95,-9.28, 7.03,-9.32, 7.10,-9.36, 7.15,-9.40, 7.22,-9.44, 7.27,-9.44, 7.35
}; // pontos (x, y) do desenho que o robo deve alcançar
int pontoX = 0; // posicao do array que representa o atual ponto x do desenho
int pontoY = 1; // posicao do array que representa o atual ponto y do desenho
int i = 0; // contador simples

void setup(){
  servo1.attach(8); // setup do servo 1 na porta 8
  servo2.attach(9); // setup do servo 1 na porta 9
  caneta.attach(10); // setup da caneta na porta 10
  Serial.begin(9600); // setup do monitor serial para monitoramento das variaveis
  servo1.write(0); // setup do servo 1 com angulo padrao 0
  servo2.write(180-0); // setup do servo 2 com angulo padrao 0
  caneta.write(180-0); // setup da caneta com angulo padrao 0
  Serial.println("Programa iniciado com sucesso"); // alerta de que o programa comecou
  delay(1000);
}

void loop(){
    atualizeServos();
}

void atualizeServos(){
    float angulosNecessariosParaOServo1AlcancarOResultadoDaCinematicaInversa = 0;
    float angulosNecessariosParaOServo2AlcancarOResultadoDaCinematicaInversa = 0;
    float atualAnguloDoServo1 = resultadoDaCinematicaInversaDoServo1;
    float atualAnguloDoServo2 = resultadoDaCinematicaInversaDoServo2;
    calculeCinematicaInversa();
    angulosNecessariosParaOServo1AlcancarOResultadoDaCinematicaInversa = resultadoDaCinematicaInversaDoServo1 - atualAnguloDoServo1;
    angulosNecessariosParaOServo2AlcancarOResultadoDaCinematicaInversa = resultadoDaCinematicaInversaDoServo2 - atualAnguloDoServo2;
    for (i = 0; i < 5; i++) { // suavizador do movimento da caneta que divide o avanço em 5 partes
        atualAnguloDoServo1 = atualAnguloDoServo1+(angulosNecessariosParaOServo1AlcancarOResultadoDaCinematicaInversa/5);
        atualAnguloDoServo2 = atualAnguloDoServo2+(angulosNecessariosParaOServo2AlcancarOResultadoDaCinematicaInversa/5);
        servo1.write(atualAnguloDoServo1);
        servo2.write(180-atualAnguloDoServo2);
    }
    delay(20);
    Serial.println((String)"Novo ponto (x, y) alcancado com sucesso atraves dos angulos "+atualAnguloDoServo1+" e "+atualAnguloDoServo2);
    if (pontoX == 0 && pontoY == 1) { // abaixador da caneta no inicio do desenho com delay para evitar desastres
      delay(1000);
      caneta.write(180-90);
      delay(1000);
    }
    if (pontoX >= 860 && pontoY >= 861) { // levantador da caneta no final do desenho com delay para evitar desastres
      delay(1000);
      caneta.write(180-0);
      delay(1000);
      pontoX = 0;
      pontoY = 1;
    } else {
      pontoX = pontoX + 2;
      pontoY = pontoY + 2;
    }
}

void calculeCinematicaInversa(){ // cinematica inversa atraves do tamanho dos elos e atual ponto (x, y) do desenho
    float a = sqrt(pontosDoDesenho[pontoX]*pontosDoDesenho[pontoX]+pontosDoDesenho[pontoY]*pontosDoDesenho[pontoY]);
    resultadoDaCinematicaInversaDoServo1 = acos(pontosDoDesenho[pontoX]/a) - acos(((pontosDoDesenho[pontoX]*pontosDoDesenho[pontoX]+pontosDoDesenho[pontoY]*pontosDoDesenho[pontoY])+(tamanhoDoElo1*tamanhoDoElo1)-(tamanhoDoElo2*tamanhoDoElo2))/(2*tamanhoDoElo1*a));
    resultadoDaCinematicaInversaDoServo1 = resultadoDaCinematicaInversaDoServo1*(180/M_PI);
    resultadoDaCinematicaInversaDoServo2 = acos(((tamanhoDoElo1*tamanhoDoElo1)+(tamanhoDoElo2*tamanhoDoElo2)-(pontosDoDesenho[pontoX]*pontosDoDesenho[pontoX]+pontosDoDesenho[pontoY]*pontosDoDesenho[pontoY]))/(2*tamanhoDoElo1*tamanhoDoElo2));
    resultadoDaCinematicaInversaDoServo2 = 180-(resultadoDaCinematicaInversaDoServo2*(180/M_PI));
}
