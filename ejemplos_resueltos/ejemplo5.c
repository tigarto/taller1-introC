#include <stdio.h>

/* Declaracion de funciones */
int suma(int n1, int n2, int n3);
int producto(int n1, int n2, int n3);
int menor(int n1, int n2, int n3);
int mayor(int n1, int n2, int n3); 
double promedio(int n1, int n2, int n3); 
int validar_numeros(int n1, int n2, int n3);

// Funcion de pruebas 
void tests(void); 

/* Funcion main */
int main() {
    // Variables locales
    int num1, num2, num3;
    int sum, prod, m, M;
    double prom;

    /* Codigo de la aplicacion */
    // Entrada de datos
    printf("Introduzca tres enteros distintos: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    if(validar_numeros(num1, num2, num3) == 1) {
        // Calculos
        sum = suma(num1, num2, num3);
        prod = producto(num1, num2, num3);
        m = menor(num1, num2, num3);
        M = mayor(num1, num2, num3);
        prom = promedio(num1, num2, num3);

        // Despliegue de la salida
        printf("La suma es %d\n", sum);
        printf("El promedio es %.1lf\n", prom);
        printf("El producto es %d\n", prod);
        printf("El menor es %d\n", m);
        printf("El mayor es %d\n", M);
    }
    else {
        printf("ERROR!!! Los numeros deben ser todos diferentes\n");
    }
    
    /* 
    Pruebas
    tests(); Se comenta cuando las pruebas dan
    */
   
    return 0;
}

/* Definicion de funciones */
void tests(void) {
    printf("13 + 27 + 14 = %d\n", suma(13,27,14));
    printf("13 * 27 * 14 = %d\n", producto(13,27,14));
    printf("El menor de: 13, 27 y 14 es %d\n", menor(13,27,14));
    printf("El mayor de: 13, 27 y 14 es %d\n", mayor(13,27,14));
    printf("El promedio de: 13, 27 y 14 es %.2lf\n", promedio(13,27,14));
}

int suma(int n1, int n2, int n3) {
    // Codigo de lo que hace la funcion
    int resultado = n1 + n2 + n3;
    return resultado;
}

int producto(int n1, int n2, int n3) {
    return n1*n2*n3;
}

int menor(int n1, int n2, int n3) {
    int menor;
    if((n1 < n2) && (n1 < n3)) {
        menor = n1;
    }
    else if ((n2 < n1) && (n2 < n3)) {
        menor = n2;
    }
    else {
        menor = n3;
    }
    return menor;
}

int mayor(int n1, int n2, int n3) {
    if((n1 > n2) && (n1 > n3)) {
        return n1;
    }
    else if ((n2 > n1) && (n2 > n3)) {
        return n2;
    }
    else {
        return n3;
    }
}

double promedio(int n1, int n2, int n3) {
    double prom = (n1 + n2 + n3)/3.0; 
    return prom;
}

int validar_numeros(int n1, int n2, int n3) {
    // Faltan validar casos
    if((n1 != n2) & (n2 != n3) ) {
        // numeros diferentes
        return 1; 
    }
    else {
        // numeros no cumplen que san diferentes
        return 0; 
    }
}