#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char participantes[5][30];
    float evento1[5];
    float evento2[5];
    float evento3[5];
    int totalInscritos = 0;
    int opcion, longitud, valido;

    do {
        printf("1. Inscribir participantes y registrar tiempos\n");
        printf("2. Mostrar ganadores\n");
        printf("3. Finalizar programa\n\n");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Ingrese un número válido.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                if (totalInscritos >= 5) {
                    printf("Ya están registrados los 5 participantes.\n");
                    break;
                }

                for (int k = totalInscritos; k < 5; k++) {
                    printf("\nParticipante #%d\n", k + 1);
                    printf("Nombre: ");
                    scanf(" ");
                    fgets(participantes[k], 30, stdin);
                    longitud = strlen(participantes[k]);
                    if (participantes[k][longitud - 1] == '\n')
                        participantes[k][longitud - 1] = '\0';

                    valido = 0;
                    while (!valido) {
                        printf("Tiempo en 50m: ");
                        if (scanf("%f", &evento1[k]) != 1 || evento1[k] <= 0) {
                            printf("Tiempo inválido. Intente nuevamente.\n");
                            while (getchar() != '\n');
                        } else {
                            valido = 1;
                        }
                    }

                    valido = 0;
                    while (!valido) {
                        printf("Tiempo en 100m: ");
                        if (scanf("%f", &evento2[k]) != 1 || evento2[k] <= 0) {
                            printf("Tiempo inválido. Intente nuevamente.\n");
                            while (getchar() != '\n');
                        } else {
                            valido = 1;
                        }
                    }

                    valido = 0;
                    while (!valido) {
                        printf("Tiempo en 200m: ");
                        if (scanf("%f", &evento3[k]) != 1 || evento3[k] <= 0) {
                            printf("Tiempo inválido. Intente nuevamente.\n");
                            while (getchar() != '\n');
                        } else {
                            valido = 1;
                        }
                    }

                    totalInscritos++;
                }
                break;

            case 2:
                if (totalInscritos < 5) {
                    printf("Primero debe completar el registro de los 5 participantes.\n");
                } else {
                    int mejor50 = 0, mejor100 = 0, mejor200 = 0;

                    for (int i = 1; i < 5; i++) {
                        if (evento1[i] < evento1[mejor50]) mejor50 = i;
                        if (evento2[i] < evento2[mejor100]) mejor100 = i;
                        if (evento3[i] < evento3[mejor200]) mejor200 = i;
                    }

                    printf("\n--- Resultados Finales ---\n");
                    printf("Ganador 50m: %s - %.2f seg\n", participantes[mejor50], evento1[mejor50]);
                    printf("Ganador 100m: %s - %.2f seg\n", participantes[mejor100], evento2[mejor100]);
                    printf("Ganador 200m: %s - %.2f seg\n", participantes[mejor200], evento3[mejor200]);

                    float tiemposTop[3] = {evento1[mejor50], evento2[mejor100], evento3[mejor200]};
                    int indicesTop[3] = {mejor50, mejor100, mejor200};

                    int indexCampeon = 0;
                    for (int z = 1; z < 3; z++) {
                        if (tiemposTop[z] < tiemposTop[indexCampeon]) {
                            indexCampeon = z;
                        }
                    }

                    printf(">>> Campeón del torneo: %s con %.2f seg <<<\n",
                           participantes[indicesTop[indexCampeon]],
                           tiemposTop[indexCampeon]);
                }
                break;

            case 3:
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }

    } while (opcion != 3);

    return 0;
}
