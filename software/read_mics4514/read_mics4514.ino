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

//analog read
int ox=0;
int red=0;
int co2=0;
int no2=0;

//Value voltaje
float vox=0;
float vred=0;
float vco2=0;
float vno2=0;

//Value resistencia
float rox=0;
float rred=0;
float rco2=0;
float rno2=0;

void setup() {
  //resolution analog reads
   analogReadResolution(12);
   Serial.begin(9600);

  //pre heating
  pinMode(2,OUTPUT);
  Serial.println("pre heating");
  digitalWrite(2, HIGH);
  delay (30000);
  Serial.println("pre heating done");
  digitalWrite(2, LOW);
}

void loop() {
  
  //Get Sensor Data
  ox=analogRead(A0);
  red=analogRead(A1);
  co2=analogRead(A2);
  no2=analogRead(A3);
  
  Serial.print("bits ox:");
  Serial.print(",");
  Serial.print(ox);
  Serial.print(",");
  Serial.print(" bits red:");
  Serial.print(",");
  Serial.print(red);
  Serial.print(",");
  Serial.print(" bits co2:");
  Serial.print(",");
  Serial.print(co2);
  Serial.print(",");
  Serial.print(" bits no2:");
  Serial.print(",");
  Serial.println(no2);
    
  //Convert to voltaje
  vox=(3.3*ox)/4096;
  vred=(3.3*red)/4096;
  vco2=(3.3*co2)/4096;
  vno2=(3.3*no2)/4096;
   
  Serial.print("V ox:");
  Serial.print(",");
  Serial.print(vox);
  Serial.print(",");
  Serial.print(" V red:");
  Serial.print(",");
  Serial.print(vred);
  Serial.print(",");
  Serial.print(" V co2:");
  Serial.print(",");
  Serial.print(vco2);
  Serial.print(",");
  Serial.print(" V no2:");
  Serial.print(",");
  Serial.println(vno2);

  //Convert to resist
  rox=((3.3*270)/vox)-270; //load resistor in ox 270ohm
  rred=((3.3-vred)*47000)/vred; //load resistor in red 1ohm
  rco2=((3.3*47000)/vco2)-47000;
  rno2=((3.3*270)/vno2)-270;

  Serial.print("R ox:");
  Serial.print(",");
  Serial.print(rox);
  Serial.print(",");
  Serial.print(" R red:");
  Serial.print(",");
  Serial.print(rred);
  Serial.print(",");
  Serial.print(" R co2:");
  Serial.print(",");
  Serial.println(rco2);
  Serial.println(",");
  Serial.print(" R no2:");
  Serial.print(",");
  Serial.println(rno2);
    
  delay(1000);
}
