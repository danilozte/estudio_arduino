
int Vo;
float R1 = 100000;              // resistencia fija del divisor de tension 
float logR2, R2, TEMPERATURA;
float c1 = 2.114990448e-03; 
float c2 = 0.3832381228e-04;
float c3 = 5.228061052e-07;
// coeficientes de S-H en pagina: 
// http://www.thinksrs.com/downloads/programs/Therm%20Calc/NTCCalibrator/NTCcalculator.htm

void setup() {
Serial.begin(9600);		// inicializa comunicacion serie a 9600 bps
}

void loop() {
  Vo = analogRead(A0);			// lectura de A0
  R2 = R1 * (1023.0 / (float)Vo - 1.0);	// conversion de tension a resistencia
  logR2 = log(R2);			// logaritmo de R2 necesario para ecuacion
  TEMPERATURA = (-1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); 	// ecuacion S-H
  TEMPERATURA = (TEMPERATURA - 273.15);   // Kelvin a Centigrados (Celsius)
  Serial.print("Temperatura: "); 	// imprime valor en monitor serie
  Serial.print(TEMPERATURA);
  Serial.println(" C"); 
  delay(500);
  Serial.println("Temperatura: "); 	// imprime valor en monitor serie
  Serial.println(Vo);
  delay(500); // demora de medio segundo entre lecturas
  /// esto mejor
				
}//////hgfhfhhg