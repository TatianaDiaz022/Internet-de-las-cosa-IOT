// C++ code
#define LED_RED    12
#define LED_GREEN  11
#define LED_YELLOW 13

void setup() {
  // Configura los LEDs como salida
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  // Inicializa el monitor serial
  Serial.begin(9600);
  
  // Inicializa todos los LEDs apagados
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  
  Serial.println("MAIN MENU");
  Serial.println("[1]. Turn on LED green");
  Serial.println("[2]. Turn off LED green");
  Serial.println("[3]. Turn on LED red");
  Serial.println("[4]. Turn off LED red");
  Serial.println("[5]. Turn on LED yellow");
  Serial.println("[6]. Turn off LED yellow");
  Serial.println("[7]. Turn on all LEDs");
  Serial.println("[8]. Turn off all LEDs");
  Serial.println("[9]. Blink all LEDs");
}

void loop() {
  static unsigned long lastBlinkTime = 0;
  static bool ledState = LOW;
  const unsigned long blinkInterval = 500; 
  
  if (Serial.available() > 0) {
    char opt = Serial.read(); 
    
    switch(opt) {
      case '1':
        digitalWrite(LED_GREEN, HIGH); // Enciende el LED verde
        Serial.println("LED green is ON");
        break;
      case '2':
        digitalWrite(LED_GREEN, LOW); // Apaga el LED verde
        Serial.println("LED green is OFF");
        break;
      case '3':
        digitalWrite(LED_RED, HIGH); // Enciende el LED rojo
        Serial.println("LED red is ON");
        break;
      case '4':
        digitalWrite(LED_RED, LOW); // Apaga el LED rojo
        Serial.println("LED red is OFF");
        break;
      case '5':
        digitalWrite(LED_YELLOW, HIGH); // Enciende el LED amarillo
        Serial.println("LED yellow is ON");
        break;
      case '6':
        digitalWrite(LED_YELLOW, LOW); // Apaga el LED amarillo
        Serial.println("LED yellow is OFF");
        break;
      case '7':
        digitalWrite(LED_RED, HIGH);    // Enciende todos los LEDs
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("All LEDs are ON");
        break;
      case '8':
        digitalWrite(LED_RED, LOW);     // Apaga todos los LEDs
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("All LEDs are OFF");
        break;
      case '9': {
        // Modo intermitente
        unsigned long currentTime = millis();
        if (currentTime - lastBlinkTime >= blinkInterval) {
          lastBlinkTime = currentTime;
          ledState = !ledState;
          digitalWrite(LED_RED, ledState);
          digitalWrite(LED_GREEN, ledState);
          digitalWrite(LED_YELLOW, ledState);
          Serial.print("LEDs are ");
          Serial.println(ledState ? "ON" : "OFF");
        }
        break;
      }
      default:
        Serial.println("Invalid option. Use 1 to turn on green LED, 2 to turn off green LED, 
        3 to turn on red LED, 4 to turn off red LED, 5 to turn on yellow LED, 6 to turn off yellow LED, 
        7 to turn on all LEDs, 8 to turn off all LEDs, or 9 for blinking LEDs.");
        break;
    }
  }
}
