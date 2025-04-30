#include <stdio.h>
#include <string.h>

int esNombreValido(char nombre[]) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') ||
              (nombre[i] >= 'a' && nombre[i] <= 'z') ||
              (nombre[i] >= '0' && nombre[i] <= '9'))) {
            return 0; 
        }
    }
    return 1;
}

int esNumeroValido(char texto[]) {
    int punto = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.') {
            if (punto) return 0;
            punto = 1;
        } else if (texto[i] < '0' || texto[i] > '9') {
            return 0;
        }
    }
    return 1;
}

float convertirAFloat(char texto[]) {
    float resultado = 0;
    int i = 0;
    int decimal = 0;
    float divisor = 10;

    while (texto[i] != '\0') {
        if (texto[i] == '.') {
            decimal = 1;
            i++;
            continue;
        }
        if (!decimal) {
            resultado = resultado * 10 + (texto[i] - '0');
        } else {
            resultado += (float)(texto[i] - '0') / divisor;
            divisor *= 10;
        }
        i++;
    }

    return resultado;
}

int main() {
    char nombres[5][30];
    float tiempos[5][3];
    int distancias[3] = {50, 100, 200};
    float totales[5];

    for (int i = 0; i < 5; i++) {
        char temp[30];
        int valido = 0;

        while (!valido) {
            printf("Ingrese el nombre del nadador %d (solo letras y numeros): ", i + 1);
            scanf("%s", temp);
            if (esNombreValido(temp)) {
                strcpy(nombres[i], temp);
                valido = 1;
            } else {
                printf("Nombre invalido. Intente solo con letras y numeros.\n");
            }
        }

        totales[i] = 0;

        for (int j = 0; j < 3; j++) {
            char entrada[20];
            float tiempo;
            valido = 0;
            while (!valido) {
                printf("Ingrese el tiempo (solo numero positivo) de %s en %d metros: ", nombres[i], distancias[j]);
                scanf("%s", entrada);
                if (esNumeroValido(entrada)) {
                    tiempo = convertirAFloat(entrada);
                    if (tiempo > 0) {
                        tiempos[i][j] = tiempo;
                        totales[i] += tiempo;
                        valido = 1;
                    } else {
                        printf("El numero debe ser mayor a 0.\n");
                    }
                } else {
                    printf("Entrada invalida. Use solo numeros positivos (ej: 12.5)\n");
                }
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        int mejor = 0;
        for (int i = 1; i < 5; i++) {
            if (tiempos[i][j] < tiempos[mejor][j]) {
                mejor = i;
            }
        }
        printf("\nGanador en %d metros: %s con %.2f segundos", distancias[j], nombres[mejor], tiempos[mejor][j]);
    }

    int mejorGeneral = 0;
    for (int i = 1; i < 5; i++) {
        if (totales[i] < totales[mejorGeneral]) {
            mejorGeneral = i;
        }
    }

    printf("\n\nGanador general: %s con tiempo total de %.2f segundos\n", nombres[mejorGeneral], totales[mejorGeneral]);

    return 0;
}