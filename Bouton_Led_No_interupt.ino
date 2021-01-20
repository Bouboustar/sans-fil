// Bouton Led
// Bouton poussoir anti rebond
// Boyer Alexis & Gutirrez Sandro
// 20.01.21
// Version 1.1

int pin_LED = 13;    // port numérique associé à la LED intégrée
int pin_button = 3;  // port numérique lié au bouton poussoir
volatile int state = LOW; // variable d'état de la LED (précédée de volatile !!)
void setup() {
   pinMode(pin_LED, OUTPUT);    // réglage du port de la LED en mode SORTIE
   // Création de l'interruption
   attachInterrupt(0, blink, CHANGE);
   Serial.begin(9600);
}
void loop() {
   digitalWrite(pin_LED, state); // action sur LED (allumage ou extinction)
   // Suite du programme ... simulé par une instruction d'attente
   delay(100);
}
void blink() {
   state = !state; // inversion de la variable d'état de la LED
   Serial.println(state);
}
