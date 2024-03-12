#include <stdio.h>

unsigned int factorial(unsigned int x){
    
    if(x == 0){
        return 1;
    }
    
    else if (x > 0){
        return x* factorial(x-1); 
    }
}


int main()
{
    unsigned int n;
    printf("Podaj liczbę: ");
    scanf("%d",&n);
    printf("Silnia z %d to: %d",n,factorial(n));

    return 0;
}
