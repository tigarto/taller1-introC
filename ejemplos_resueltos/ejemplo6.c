#include <stdio.h>

/* Declaracion de funciones */

// Funciones del programa
double obtener_KPL(int, int);


// Funcion de pruebas 
void test(void);


/* Funcion main */
int main() {
    /* Variables locales */
    int km;             // kilometros
    int lt;             // litros
    double kpl;         // kilometros por litro
    double total_kpl;   // Total kilometros por litro
    

    /* Codigo de la aplicacion */

    // Ingreso de los kilometros recorridos
    printf("Escriba los kilometros usados (-1 para salir): ");
    scanf("%d", &km);
    while(km != -1) {
        // Ingreso de los litros consumidos
        printf("Escriba los litros: ");
        scanf("%d", &lt);

        // Calculo y despliegue de los kilometros por litro
        kpl = obtener_KPL(km, lt);
        printf("KPL en este reabastecimiento: %lf\n", kpl);

        // Actualizacion y despliegue de los kilometros por litro consumidos en total
        total_kpl += kpl;
        printf("Total KPL: %lf\n\n", total_kpl);

        // Ingreso de los kilometros recorridos
        printf("Escriba los kilometros usados (-1 para salir): ");
        scanf("%d", &km);
    }

    /* Codigo test */
    // test();

    return 0;
}

/* Definicion de funciones */

double obtener_KPL(int km, int litros) {
    return (double)km/litros;
}

void test(void) {
    printf("Prueba funcion obtener_KPL\n");
    printf("%lf\n",obtener_KPL(287,13));
    printf("%lf\n",obtener_KPL(200,10));
    printf("%lf\n",obtener_KPL(120,5));
}