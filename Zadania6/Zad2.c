#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    char z;
    time_t tt;
    z = time(&tt);
    srand(z);
    int tablica[10];
    
    for(int i = 0;  i<10; i++){
        tablica[i] = rand()%10;
        printf("%d ", tablica[i]);
    }
    
    int *wskaznik = &tablica[0];

    
    printf("\nZawartosc tablicy int:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *wskaznik); 
        wskaznik++; 
    }
    printf("\n");
    return 0;
}
