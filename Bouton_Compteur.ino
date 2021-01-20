// Bouton Led
// Bouton poussoir anti rebond
// Boyer Alexis & Gutirrez Sandro
// 20.01.21
// Version 1.2

int compteur = 0;     // on initialise le compteur a 0 
int pin_LED = 13;    // port numérique associé à la LED intégrée
int pin_button = 2;  // port numérique lié au bouton poussoir
int pin_reset = 5;   // port du bouton reset
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
   boolean appuiButton = digitalRead(pin_button);
   boolean appuiButton2 = digitalRead(pin_reset);
   if (appuiButton == HIGH) {
      compteur = compteur+1;
      Serial.println(compteur);
      delay(150);
      if (compteur == 8) {
        digitalWrite(pin_LED, LOW);
      }
      if (compteur == 12) {
        digitalWrite(pin_LED, HIGH);
      }
      }
    if (appuiButton2 == HIGH) { // Reset 
      compteur = 0;
      digitalWrite(pin_LED, LOW);
      Serial.println(compteur);
      }
   
}
void blink() {
   state = !state; // inversion de la variable d'état de la LED
}
