/***************************************************************************
  This is a example for the MISC4514 NO2 & CO sensor

  Designed specifically to work with the Electronic Cats MICS4514 Breakout
  ----> http://www.electroniccats.com

  Electronic Cats invests time and resources providing this open source code,
  please support Electronic Cats and open-source hardware by purchasing products
  from Electronic Cats!

  Written by Andrés Sabas & Rocio Rosales for Electronic Cats.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
#define Serial SerialUSB
#define e 2.71828

//analog read
int co=0;
int no2=0;

//Value voltaje
float vco=0;
float vno2=0;

//Value resistencia
float rco=0;
float rno2=0;

//Value Rs/Ro
float conCO=0;
float conNO2=0;

//cálculo de ppm 
double ppmCO=0;
double ppmNO2=0;

void setup() {
  //resolution analog reads
   analogReadResolution(12);
   Serial.begin(9600);
  //pre heating
  //pinMode(2,OUTPUT);
  Serial.println("pre heating");
  //digitalWrite(9, HIGH);
  //delay (30000);
  Serial.println("pre heating done");
  //digitalWrite(2, LOW);
}

void loop() {
  
  //Get Sensor Data
  co=analogRead(A0);
  no2=analogRead(A1);
  
  Serial.print(",");
  Serial.print(co);
  Serial.print(",");
  Serial.print(no2);
    
  //Convert to voltaje
  vco=(3.3*co)/4096;
  vno2=(3.3*no2)/4096;
   
  Serial.print(",");
  Serial.print(vco);
  Serial.print(",");
  Serial.print(vno2);

  //Convert to resist
  rco=47000*((3.3-vco)/vco);//load resistor in red 1ohm
  rno2=4270*((3.3-vno2)/vno2);//load resistor in ox 270ohm
  
  Serial.print(",");
  Serial.print(rco);
  Serial.print(",");
  Serial.print(rno2);

 //Convert to indicator concentration
  conCO= 47000/rco;
  conNO2= 270/rno2;
  
  Serial.print(",");
  Serial.print(conCO);
  Serial.print(",");
  Serial.print(conNO2);

  //Calculo de particulas por millon 
  ppmCO=971.43*pow(e,-9177*conCO);
  ppmNO2= 11.455*pow(conNO2, 0.5399);

  Serial.print(",");
  Serial.print(ppmCO);
  Serial.print(",");
  Serial.println(ppmNO2);
 
  delay(1000);
}
