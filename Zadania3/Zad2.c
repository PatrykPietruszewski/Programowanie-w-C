#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    
    int wys, szer;
    
    char z;
    time_t tt;
    z = time(&tt);
    srand(z);
    
    printf("Podaj szerokość macierzy: ");
    scanf("%d", &wys);
    printf("Podaj wysokość macierzy: ");
    scanf("%d", &szer);
    
    printf("\n");
    //Alokacja wierszy
    
    int **tablica = (int **)malloc(wys * sizeof(int *));
    
    
    //Alokacja kolumn
    for (int i = 0; i < wys; i++) 
        tablica[i] = (int *)malloc(szer * sizeof(int));
        
        
    //Dodanie losowych wartości do tablicy
    for (int i = 0; i < szer; i++) {
        for (int j = 0; j < wys; j++) {
            tablica[i][j] = rand()%500+1;
        }
    }    
    
    //Wyświetlanie tablicy na ekranie
    for (int i = 0; i < szer; i++) {
        for (int j = 0; j < wys; j++) {
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }
    
    //Zwalnianie pamięci
    for (int i = 0; i < szer; i++) {
        free(tablica[i]);
    }
    free(tablica);
    
    return 0;
}
