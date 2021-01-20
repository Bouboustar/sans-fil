// Bouton Led
// Bouton poussoir 
// Boyer Alexis & Gutirrez Sandro
// 20.01.21
// Version 1.0

int pin_LED = 13;   // port numérique associé à la LED intégrée
int pin_button = 4; // port numérique lié au bouton poussoir
int state = LOW; // variable d'état de la LED
void setup() {
   pinMode(pin_LED, OUTPUT);   // réglage du port de la LED en mode SORTIE
   pinMode(pin_button, INPUT); // réglage du port du bouton en mode ENTREE
   Serial.begin(9600);
}
void loop() {
   if (digitalRead(pin_button) == HIGH) { // si le bouton est pressé ...
      state = !state; // ... inversion de la variable d'état de la LED (allumée<->éteinte)
      Serial.println(state);
   }
   digitalWrite(pin_LED, state); // action sur la LED (allumage ou extinction)
   
   // Suite du programme ... simulé par une instruction d'attente
   delay(100);
}
