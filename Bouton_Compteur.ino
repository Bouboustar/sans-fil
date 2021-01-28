// Projet bouton rebond
// Devs: Alexis & Sandro
// Date: 26/01/2021
// Version: 1.0

int compt = 0;
int flag = 0;
int pin_LED = 3;   // port numérique associé à la LED intégrée
int pin_button = 2; // port numérique lié au bouton poussoir
int pin_button2 = 4; // Port numérique bouton reset
volatile int state = LOW; // variable d'état de la LED (précédée de volatile)

void setup() {
   pinMode(pin_LED, OUTPUT);    // réglage du port de la LED en mode SORTIE
   // Création de l'interruption
   attachInterrupt(0, compteur, RISING);
   Serial.begin(9600);
}
void loop() {
   digitalWrite(pin_LED, state); // action sur LED (allumage ou extinction)
   // Suite du programme ... simulé par une instruction d'attente
   if (compt >= 8 and compt < 12 and flag == 0) {
      blink();
      flag = 1;
    }
    if (compt >= 12 and flag == 1) {
      flag = 0;
      blink();
    }
    if (digitalRead(pin_button2) == HIGH) {
      compt = 0;
      state = LOW;
      Serial.println(compt);
    }
   delay(100);
}
void blink() {
   state = !state; // inversion de la variable d'état de la LED
}

void compteur() {
    compt = compt + 1;
    Serial.println(compt);
}
