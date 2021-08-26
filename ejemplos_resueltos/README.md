# Ejemplos basicos de lenguaje C

> **Objetivos**
> * Ir ganando experiencia en la resolución de problemas empleando lenguaje C. 


## Ejemplos resueltos

A modo de repaso se mostraran algunos ejercicios resueltos que implican el uso de programacion modular. Puede descargarlos, compilarlos y ejecutarlos.

1. Hacer un programa que muestre en pantalla el mensaje: "Hasta la vista baby..."

**Solucion**: [ejemplo1.c](ejemplo1.c)

```C
#include <stdio.h>

int main() {
    printf("\"Hasta la \n\tvista baby\"\n");    
    
    return 0;
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo1.c -o ejemplo1.out
```

2. Hacer un programa que demuestre el funcionamiento de la función printf. Para ello este programa, debera mostrar en pantalla el siguiente mensaje:

```
Hola soy Salomon, tengo 15 años, vivo en Titiribi, peso 79 kg, mido 1.65 m y soy de sexo M.
```

**Solucion**: [ejemplo2.c](ejemplo2.c)

```C
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
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo2.c -o ejemplo2.out
```

3. Hacer un programa programa pida el nombre y el apellido de una persona y los imprima en orden inverso. A continuación se muestra un caso ejemplo:

```
Digite el nombre: Ramon
Digite el apellido: Valdez

Hola Valdez, Ramon
```


**Solucion**: [ejemplo3.c](ejemplo3.c)

```C
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
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo3.c -o ejemplo3.out
```

4. Hacer un progrtama que permita calcular la distancia entre 2 puntos. Una posible forma de funcionamiento se muestra a continuación:

```
Digite las coordenadas del punto 1: 0 0
El punto 1 es: (0.0, 0.0)

Digite las coordenadas del punto 2: 3 4
El punto 2 es: (3.0, 4.0)

La distancia entre (0.0, 0.0) y (3.0, 4.0) es 5.00
```

**Solucion**: [ejemplo4.c](ejemplo4.c)

```C
#include <stdio.h>
#include <math.h>  

int main() {
    /* Variables locales */
    double x1, y1; // Coordenada punto 1
    double x2, y2; // Coordenada punto 2
    double d;      // Diatancia

    /* Proceso */
    // Pedir la coordenadas
    printf("Digite las coordenadas del punto 1: ");
    scanf("%lf,%lf",&x1, &y1);  // Un enter se comporta como un espacio
    printf("El punto 1 es: (%.1lf, %.1lf)\n\n", x1, y1);

    printf("Digite las coordenadas del punto 2: ");
    scanf("%lf,%lf",&x2, &y2);  // Un enter se comporta como un espacio
    printf("El punto 1 es: (%.1lf, %.1lf)\n\n", x2, y2);

    d = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));   // sqrt --> raiz
                                                 // pow(x,y) --> x^y
    printf("La distancia entre (%.1lf,%.1lf) y (%.1lf,%.1lf) es %.2lf\n", x1, y1, x2, y2, d);
    return 0;
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo4.c -lm -o ejemplo4.out
```

5. Escriba un programa que reciba tres enteros del teclado e imprima la suma, promedio, producto, menor y mayor de estos números. El diálogo de la pantalla debe aparecer de la siguiente manera:

```
Introduzca tres enteros distintos: 13 27 14
La suma es 54
El promedio es 18
El producto es 4914
El menor es 13
El mayor es 27
```

**Solucion**: [ejemplo5.c](ejemplo5.c)

```C
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
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo5.c -o ejemplo5.out
```

1. Los conductores se preocupan acerca del kilometraje de sus automóviles. Un conductor ha llevado el registro de varios viajes, anotando los kilómetros conducidos y los litros usados en cada viaje. Desarrolle un programa en C++ que utilice una instrucción while para recibir como entrada los kilómetros conducidos y los litros usados por cada viaje, y que imprima el total de kilómetros por litro obtenidos en todos los reabastecimientos hasta este punto.

```
Escriba los kilometros usados (-1 para salir): 287
Escriba los litros: 13
KPL en este reabastecimiento: 22.076923
Total KPL: 22.076923

Escriba los kilometros usados (-1 para salir): 200
Escriba los litros: 10
KPL en este reabastecimiento: 20.000000
Total KPL: 42.076923

Escriba los kilometros usados (-1 para salir): 120
Escriba los litros: 5
KPL en este reabastecimiento: 24.000000
Total KPL: 66.076923

Escriba los kilometros usados (-1 para salir): -1
```

**Solucion**: [ejemplo6.c](ejemplo6.c)

```C
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
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo6.c -o ejemplo6.out
```

7. Hacer un programa que calcule el máximo de 2 números.

**Solucion**: [ejemplo7.c](ejemplo7.c)

```C
#include <stdio.h>

int maximo(int a, int b); /* prototipo de funcion */

int main() {
    int x, y;
    int max;
    printf("Introduzca dos numeros: ");
    scanf("%d %d", &x, &y);
    max = maximo(x, y); /* llamada a la funcion */
    printf("El maximo es %d\n", max);
    return 0;
}

int maximo(int a, int b) /* definicion de la funcion */ {
    int max;
    if (a > b)
        max = a;
    else
        max = b;
    return max; /* devuelve el valor maximo */
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo7.c -o ejemplo7.out
```

8. Hacer un programa que diga si un numero es cuadrado perfecto.

**Solucion**: [ejemplo8.c](ejemplo8.c)

```C
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void explicacion(void);
int cuadrado_perfecto(int x);

int main() {
    int n;
    int perfecto;
    explicacion();
    scanf("%d", &n);
    perfecto = cuadrado_perfecto(n);
    if (perfecto) {
        printf("%d es cuadrado perfecto.\n", n);
    }
    else {
        printf("%d no es cuadrado perfecto.\n", n);
    }
    return 0;
}

void explicacion(void) {
    printf("Este programa dice si un numero ");
    printf("es cuadrado perfecto \n");
    printf("Introduzca un numero: ");
}

int cuadrado_perfecto(int x) {
    int raiz;
    int perfecto;
    raiz = (int) sqrt(x);
    if (x == raiz * raiz) {
        perfecto = TRUE; /* cuadrado perfecto */
    }
    else {
        perfecto = FALSE; /* no es cuadrado perfecto */
    }
    return perfecto;
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo8.c -o ejemplo8.out -lm
```

9. Hacer un programa que permita calcular el área de diferentes figuras geométricas.

**Solucion**: [ejemplo9.c](ejemplo9.c)

```C
#include <stdio.h>
#include <math.h>

#define PI 3.14

/*
#define TRIANGULO 1
#define RECTANGULO 2
#define CUADRADO 3
#define CIRCULO 4
*/

enum opcion{TRIANGULO = 1,RECTANGULO = 2,CUADRADO = 3,CIRCULO = 4};

/* Declaracion de las funciones */
void borrar_pantalla(void);
int menu(void);
float a_triangulo(float, float);
float a_cuadrado(float);
float a_circulo(float);
float a_rectangulo(float, float);

int main() {
    float A, r, l, b, h; /* Variables*/
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case TRIANGULO:
                printf("\n\nAREA DEL TRIANGULO\n");
                printf("Digite la base: ");
                scanf("%f", &b);
                printf("Digite la altura: ");
                scanf("%f", &h);
                A = a_triangulo(b, h);
                printf("El area del triangulo es: %f\n", A);
                break;
            case RECTANGULO:
                printf("\n\nAREA DEL RECTANGULO\n");
                printf("Digite la base: ");
                scanf("%f", &b);
                printf("Digite la altura: ");
                scanf("%f", &h);
                A = a_rectangulo(b, h);
                printf("El area del rectangulo es: %f\n", A);
                break;
            case CUADRADO:
                printf("\n\nAREA DEL CUADRADO\n");
                printf("Digite el lado: ");
                scanf("%f", &l);
                A = a_cuadrado(l);
                printf("El area del cuadrado es: %f\n", A);
                break;
            case CIRCULO:
                printf("\n\nAREA DEL CIRCULO\n");
                printf("Digite el radio: ");
                scanf("%f", &r);
                A = a_circulo(r);
                printf("El area del cuadrado es: %f\n", A);
                break;
            default:
                printf("\n\nOPCION INVALIDA !!!!\n");
        }
        printf("\nPresione 1 si desea continuar u otro valor para terminar: ");
        scanf("%d",&opc);
        borrar_pantalla();
    }while(opc==1);
    printf("Fin del programa, Suerte es que le digo\n");
    return 0;
}

void explicacion(void) {
    printf("Este programa dice si un numero ");
    printf("es cuadrado perfecto \n");
    printf("Introduzca un numero: ");
}

float a_triangulo(float ancho, float alto) {
  float area; /* Area of the triangle */
  area = ancho * alto / 2.0;
  return (area);
}

float a_cuadrado(float lado) {
  /* Area del cuadrado */
  return lado*lado;
}

float a_circulo(float radio) {
  /* Area del circulo */
    float area;
    area = PI*radio*radio;
    return area;
}

float a_rectangulo(float ancho, float alto) {
  float area; /* Area of the triangle */
  area = ancho * alto;
  return (area);
}


int menu(void) {
    int opc; // Variable que almacena la opcion seleccionada
    printf("PROGRAMA QUE CALCULA EL AREA DE DIFERENTES FIGURAS GEOMETRICAS\n\n");
    printf("1. Area del triangulo\n");
    printf("2. Area del rectangulo\n");
    printf("3. Area del cuadrado\n");
    printf("4. Area del circulo\n");
    printf("\n\nElija una opcion: ");
    scanf("%d",&opc);
    return opc;
}

void borrar_pantalla(void) {
    printf("\033[2J\033[0;0f");
    printf("\033[%d;%df", 0, 0);
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo9.c -o ejemplo9.out
```

10. Hacer una función que solicite 2 números, genere 10 números aleatorios entre estos 2 números y cuente la cantidad de números pares.

**Solucion**: [ejemplo10.c](ejemplo10.c)

```C
#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()

int main (void)
{
  int min, max, num, cnt, i;
  printf("Digite los dos limites (minimo maximo): ");
  scanf("%d %d", &min, &max);
  cnt = 0;
  srand(time(NULL)); //genera la semilla
  for(i = 0; i < 10; i++)
  {
    num = rand()%(max - min + 1) + min;
    if(num % 2 == 0)
      cnt++;
    printf("%d ", num);
  }
  putchar('\n');
  printf("La cantidad de numeros pares generados es de: %d\n", cnt);
  return 0;
}
```

**Comando de compilación**:

```bash
gcc -Wall ejemplo10.c -o ejemplo10.out -lm
```