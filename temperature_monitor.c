#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float getTemperature() {
    return (rand() % 1000) / 50.0 + 20;
}

int main() {
    FILE *file;

    // abrir ficheiro para guardar dados
    file = fopen("data.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Temperature Monitoring System Started...\n\n");

    for (int i = 0; i < 10; i++) {
        float temp = getTemperature();

        printf("Temperature: %.2f °C\n", temp);
        fprintf(file, "%.2f\n", temp);
    }

    fclose(file);

    printf("\nData saved to data.txt\n");

    return 0;
}