#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresar_productos(char nombres[][50], float precios[], int *num_productos) {
    printf("¿Cuántos productos desea ingresar (máx 10)? ");
    scanf("%d", num_productos);

    for (int i = 0; i < *num_productos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

float calcular_total(float precios[], int num_productos) {
    float total = 0.0;
    for (int i = 0; i < num_productos; i++) {
        total += precios[i];
    }
    return total;
}

void encontrar_mas_caro(char nombres[][50], float precios[], int num_productos) {
    int indice_mas_caro = 0;

    for (int i = 1; i < num_productos; i++) {
        if (precios[i] > precios[indice_mas_caro]) {
            indice_mas_caro = i;
        }
    }

    printf("Producto más caro: %s con un precio de %.2f\n", nombres[indice_mas_caro], precios[indice_mas_caro]);
}

void encontrar_mas_barato(char nombres[][50], float precios[], int num_productos) {
    int indice_mas_barato = 0;

    for (int i = 1; i < num_productos; i++) {
        if (precios[i] < precios[indice_mas_barato]) {
            indice_mas_barato = i;
        }
    }

    printf("Producto más barato: %s con un precio de %.2f\n", nombres[indice_mas_barato], precios[indice_mas_barato]);
}
float calcular_promedio(float precios[], int num_productos) {
    float total = calcular_total(precios, num_productos);
    return total / num_productos;
}
void buscar_producto(char nombres[][50], float precios[], int num_productos) {
    char producto_buscado[50];
    printf("Ingrese el nombre del producto que desea buscar: ");
    scanf("%s", producto_buscado);

    for (int i = 0; i < num_productos; i++) {
        if (strcmp(nombres[i], producto_buscado) == 0) {
            printf("El precio de %s es %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

