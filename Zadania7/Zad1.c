#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    FILE *plik;
    plik = fopen("input.txt", "r");

    char linia[50];
    int suma = 0;
    
    //CZĘŚĆ 1
    
     // Odczytujemy kolejne linie z pliku
    while (fgets(linia, sizeof(linia), plik) != NULL) {
        int dlugosc = strlen(linia);
        int pierwsza_cyfra = -1;
        int ostatnia_cyfra = -1;

        // Szukamy pierwszej cyfry na początku linii
        for (int i = 0; i < dlugosc; i++) {
            if (isdigit(linia[i])) {
                pierwsza_cyfra = linia[i] - '0';
                break;
            }
        }

        // Szukamy ostatniej cyfry na końcu linii
        for (int i = dlugosc - 1; i >= 0; i--) {
            if (isdigit(linia[i])) {
                ostatnia_cyfra = linia[i] - '0';
                break;
            }
        }

        // Jeśli znaleziono obie cyfry, tworzymy liczbę i wyświetlamy ją
        if (pierwsza_cyfra != -1 && ostatnia_cyfra != -1) {
            int liczba = pierwsza_cyfra * 10 + ostatnia_cyfra;
            printf("Wynik: %d\n", liczba);
            suma = suma+liczba;
        }
        
        
    }
    printf("Suma wartości energetycznych w naszym podręczniku to %d",suma);
    
    //CZĘŚĆ 2
    
    fclose(plik);

    return 0;
}
