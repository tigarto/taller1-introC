#include <stdio.h>

int main() {
    // Variables locales
    char nom[51];   // 50 letras + null
    char apell[51]; // 50 letras + null

    printf("Digite el nombre: ");
    scanf("%s", nom);  // char[] --> %s   
    printf("Digite el apellido: ");
    scanf("%s", apell);  // char[] --> %s   
    printf("\nHola %s, %s\n", apell, nom);
    return 0;
}