#include <stdio.h>

union Dane {
    struct {
        int calkowita;
        float zmiennoprzecinkowa;
        char znak;
    }; 
};
int main()
{
     union Dane dane;
    scanf("%d", &dane.calkowita);
    printf("Wartosc typu int: %d\n", dane.calkowita);

    scanf("%f", &dane.zmiennoprzecinkowa);
    printf("Wartosc typu float: %f\n", dane.zmiennoprzecinkowa);

    scanf(" %c", &dane.znak);
    printf("Wartosc typu char: %c\n", dane.znak);

    return 0;
}
