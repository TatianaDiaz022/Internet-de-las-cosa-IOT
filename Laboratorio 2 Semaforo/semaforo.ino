// Definir los pines de los LEDs
const int pinLEDRed = 11;
const int pinLEDYellow = 12;
const int pinLEDGreen = 13;

// Duración de cada fase del semáforo (en milisegundos)
const unsigned long durationRed = 5000;     // 5 segundos
const unsigned long durationYellow = 2000;  // 2 segundos
const unsigned long durationGreen = 5000;   // 5 segundos

void setup() {
  // Configurar los pines de los LEDs como salidas
  pinMode(pinLEDRed, OUTPUT);
  pinMode(pinLEDYellow, OUTPUT);
  pinMode(pinLEDGreen, OUTPUT);
}

void loop() {
  // Encender la luz roja
  digitalWrite(pinLEDRed, HIGH);
  delay(durationRed);
  digitalWrite(pinLEDRed, LOW);

  // Encender la luz verde
  digitalWrite(pinLEDGreen, HIGH);
  delay(durationGreen);
  digitalWrite(pinLEDGreen, LOW);

  // Encender la luz amarilla
  digitalWrite(pinLEDYellow, HIGH);
  delay(durationYellow);
  digitalWrite(pinLEDYellow, LOW);
}
