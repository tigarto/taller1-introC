#include <stdio.h>

int main() {
    // Variables locales
    char nom[] = "Salomon";
    int edad = 15;
    char ciudad[] = "Titiribí";
    int peso = 79;
    double estatura = 1.65;
    char sexo = 'M';

    // Ejemplos usando printf
    printf("Hola soy Salomon, tengo 15 años, vivo en Titiribi, peso 79 kg, mido 1.65 m y soy de sexo M.\n"); 
    printf("\n"); 
    printf("Hola soy %s, tengo %d años, vivo en %s, peso %d kg, mido %lf m y soy de sexo %c.\n", nom, edad, ciudad, peso, estatura, sexo); 
    
    return 0;
}