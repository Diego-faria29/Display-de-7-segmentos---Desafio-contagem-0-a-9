int valorDisp;

byte displaySeteSeg[10][7] = { 
 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,1,0,1,1 }  //DIGITO 9
};

void setup(){
  pinMode(2, OUTPUT); //PINO 2 -> SEGMENTO A  
  pinMode(3, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(4, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(6, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(7, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(8, OUTPUT); //PINO 8 -> SEGMENTO G
  pinMode(9, OUTPUT); //PINO 9 -> SEGMENTO PONTO

  //inicializa display com número 0
  valorDisp= 0;
  ligaSegmentosDisplay(valorDisp);
  
}


void ligaSegmentosDisplay (byte digito) {

  byte pino = 2;
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos){
    digitalWrite (pino, displaySeteSeg[digito][contadorSegmentos]);
    if (valorDisp <= 9) {++pino;} 
  }
  
    if (valorDisp==9)
    {
       digitalWrite(9, HIGH);
       delay (500);
       digitalWrite(9, LOW);
       delay(500);
    }
}

void loop () {
  //put your main code here, to run repeatedly:
  delay (1000);
  ligaSegmentosDisplay(valorDisp);
  valorDisp++;

}
