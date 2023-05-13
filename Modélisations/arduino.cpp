#include <Adafruit_NeoPixel.h>
#define PIN_NEOPIXEL 5 // Broche de données de la NeoPixel

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800); // Initialise la NeoPixel avec 4 pixels

int ledPin = 3; // Broche de commande de la LED
int buttonPin = 2; // Broche du bouton poussoir
int potentiometerPin = A0; // Broche du potentiomètre
int switchPin = 4; // Broche de l'interrupteur à glissière

void setup() {
  pixels.begin(); 
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(potentiometerPin, INPUT); 
  pinMode(switchPin, INPUT);
}

void loop() {
  // potentiomètre
  int potValue = analogRead(potentiometerPin);
  
  // l'interrupteur à glissière
  int switchState = digitalRead(switchPin);
  
  // état du bouton poussoir
  int buttonState = digitalRead(buttonPin);
  
  // Allumer ou éteindre la LED en fonction de l'état de l'interrupteur à glissière et du bouton poussoir
  if (switchState == HIGH && buttonState == LOW) {
    digitalWrite(ledPin, HIGH); // Allumer la LED
  } else {
    digitalWrite(ledPin, LOW); // Éteindre la LED
  }
  
  // Régler la couleur des pixels en fonction de la valeur du potentiomètre
  int red = map(potValue, 0, 1023, 0, 255);
  int green = map(potValue, 0, 1023, 0, 255);
  int blue = map(potValue, 0, 1023, 0, 255);
  for (int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show(); // MaJ des pixels
  
  delay(100); // Délai pour éviter une mise à jour trop rapide des valeurs
}
