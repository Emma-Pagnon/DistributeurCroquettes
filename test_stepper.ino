

void setup() {
  pinMode(3, OUTPUT); // Déclaration de la broche n°3 en sortie Digitale PWM
  pinMode(8, OUTPUT); // Déclaration de la broche n°8 en sortie Digitale
  pinMode(9, OUTPUT); // Déclaration de la broche n°8 en sortie Digitale
  pinMode(11, OUTPUT); // Déclaration de la broche n°11 en sortie Digitale PWM
  pinMode(12, OUTPUT); // Déclaration de la broche n°12 en sortie Digitale
  pinMode(13, OUTPUT); // Déclaration de la broche n°13 en sortie Digitale
}

void loop(){
// Commande moteur pas à pas Unipolaire 5 fils en Full Step
// Pas n°1 | Sorties B- et B+ du Shield Moteur -> Bobines A et B du moteur pas à pas
digitalWrite(8, HIGH); //Activation Pin n°8
digitalWrite(9, LOW); //Désactivation Pin n°9
digitalWrite(12, LOW); //Désactivation Pin n°12
digitalWrite(13, HIGH); //Activation Pin n°13
analogWrite(3,0); //Pin 3 PWM valeur 0
analogWrite(11, 255); //Pin 11 PWM valeur 255
delay(20);

// Pas n°2 | Sorties B+ et A- du Shield Moteur -> Bobines B et C du moteur pas à pas 
digitalWrite(8, LOW); //Désactivation Pin n°8
digitalWrite(9, LOW); //Désactivation Pin n°9
digitalWrite(12, LOW);  //Désactivation Pin n°12
digitalWrite(13, HIGH); //Activation Pin n°13
analogWrite(3, 255); //Pin 3 PWM valeur 255
analogWrite(11, 255); //Pin 11 PWM valeur 255
delay(20);

// Pas n°3 | Sorties A- et A+ du Shield Moteur -> Bobines C et D du moteur pas à pas 
digitalWrite(8,LOW);  //Désactivation Pin n°8
digitalWrite(9,  HIGH); //Activation Pin n°9
digitalWrite(12, HIGH); //Activation Pin n°12
digitalWrite(13, LOW);  //Désactivation Pin n°13
analogWrite(3,255); //Pin 3 PWM valeur 255
analogWrite(11, 0); //Pin 11 PWM valeur 0
delay(20);

// Pas n°4 | Sorties A+ et A- du Shield Moteur -> Bobines D et A du moteur pas à pas 
digitalWrite(8, LOW);  //Désactivation Pin n°8
digitalWrite(9, LOW); //Désactivation Pin n°9
digitalWrite(12, HIGH); //Activation Pin n°12
digitalWrite(13, LOW);  //Désactivation Pin n°13
analogWrite(3, 255); //Pin 3 PWM valeur 255
analogWrite(11, 255); //Pin 11 PWM valeur 255
delay(20);
}
