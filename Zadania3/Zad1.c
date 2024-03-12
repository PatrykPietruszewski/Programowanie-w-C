#include <stdio.h>

void Pascal(int wys) {
    int liczba = 1;
    for (int i = 0; i < wys; i++) {
        for (int miejsce = 1; miejsce <= wys - i; miejsce++)
            printf("  "); 

        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                liczba = 1;
            else
                liczba = liczba * (i - j + 1) / j;

            printf("%4d", liczba); 
        }
        printf("\n");
    }
}

int main() {
    int wys;

    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &wys);

    Pascal(wys);

    return 0;
}
