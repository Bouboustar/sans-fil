// Bouton Led
// Bouton poussoir anti rebond
// Boyer Alexis & Gutirrez Sandro
// 20.01.21
// Version 1.2

int pin_LED = 13;    // port numérique associé à la LED intégrée
int pin_button = 2;  // port numérique lié au bouton poussoir
int pin_reset = 5;   // port du bouton reset
volatile int state = LOW; // variable d'état de la LED (précédée de volatile !!)
volatile int compteur = 0; // variable compteur (précédée de volatile !!)

void setup() {
   pinMode(pin_LED, OUTPUT);    // réglage du port de la LED en mode SORTIE
   // Création de l'interruption
   attachInterrupt(0, blink, RISING);
   Serial.begin(9600);
}

void loop() {  
      if (compteur == 8) {
        digitalWrite(pin_LED, HIGH);
      }
      if (compteur == 12) {
        digitalWrite(pin_LED, LOW);
      }
}
void blink() {
    compteur = compteur+1;
    delay(10000);
    Serial.println(compteur);
}
void reset(){
  compteur = 0;
}
