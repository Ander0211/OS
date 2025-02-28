// C++ code
// Pines
const int led = 13; 
const int motor = 12; 
int sensorValue; 
float temp;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600); // baudios de trasferencia señales 
   Serial.println(" ### temperatura  Monitor ###");
}

void loop() {
  // lectura analogica
  sensorValue = analogRead(A0);
  Serial.print("serial value:");
  Serial.println(sensorValue);
  delay(2000);//milesecons
  
  temp = (sensorValue * (500.0/1023.0))-50.0;
  Serial.print("temp value:");
  Serial.println(temp);
  delay(2000);//milesecons
  
   // Validación 1: Temperatura inferior a 5 °C
  if (temp < 5) {
    Serial.println("Temperatura baja, el LED parpadea.");
    digitalWrite(motor, LOW); // Apagar el motor
    digitalWrite(led, HIGH);
    delay(400);
    digitalWrite(led, LOW);
    delay(400);
    digitalWrite(led, HIGH);
    delay(400);
    digitalWrite(led, LOW);
    delay(400);
  }
  // Validación 2: Temperatura entre 6 °C y 25 °C
 else if (temp>= 6 && temp <= 25) {
    Serial.println("Temperatura moderada, el LED y el motor se apagan.");
    digitalWrite(led, LOW);
    digitalWrite(motor, LOW);
  }
  // Validación 3: Temperatura mayor a 25 °C
  else if (temp > 25) {
    Serial.println("Alta temperatura, el LED y el motor se encienden.");
    digitalWrite(led, HIGH);
    digitalWrite(motor, HIGH);
    
  }

}
