#include <stdio.h>
#include <stdlib.h>


void Licz_srednia(int array[]){
    
    int wynik[10];
    wynik[0]=array[0];
    printf("Wynik to: %d \n",wynik[0]);
    for(int i = 1; i<10; i++){
        
        wynik[i] = array[i]*array[i-1];
        
        printf("Wynik to: %d \n",wynik[i]);
        }
}


int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    Licz_srednia(array);
    
	return 0;
}
