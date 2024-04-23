#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NUMBERS 20
#define MAX_DIGITS 10

int decode(char *line);
int convert_to_int(char *number);
int concat_int(int number1, int number2);

int main()
{
    
    
    
    FILE *plik;
    plik = fopen("input.txt", "r");

    char linia[50];
    char linia2[50];
    int suma = 0;
    int suma2 = 0;
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
    printf("Suma wartości energetycznych w naszym podręczniku to %d\n",suma);
    fclose(plik);
    //CZĘŚĆ 2
    
    FILE *plik2;
    char line[100];

    plik2 = fopen("input.txt", "r");


    while (fgets(line, sizeof(line), plik2) != NULL) 
    {
        int energy = decode(line);
        printf("%i\n", energy);
        suma2 += energy;
    }
    printf("Suma wartości energetycznych w naszym podręczniku to %d\n", suma2);
    fclose(plik2);

    return 0;
}
int decode(char *line) 
{   
    int count = 0;
    char numbers[MAX_NUMBERS][MAX_DIGITS]; 

    char* slowa[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(slowa) / sizeof(slowa[0]);

    // Przeszukiwanie ciągu znaków, by znaleźć podciągi lub cyfry
    for (int i = 0; i < strlen(line); i++) 
    {
        if (isdigit(line[i])) 
        {
            char str[MAX_DIGITS]; 
            sprintf(str, "%c", line[i]); 
            strcpy(numbers[count], str); 
            count++;
        }
        else 
        {
            for (int j = 0; j < number_of_words; j++) 
            {
                if (strncmp(&line[i], slowa[j], strlen(slowa[j])) == 0) 
                {
                    strncpy(numbers[count], &line[i], strlen(slowa[j])); 
                    numbers[count][strlen(slowa[j])] = '\0';
                    count++;
                    i++; 
                    break;
                }
            }
        }
    }
    return concat_int(convert_to_int(numbers[0]), convert_to_int(numbers[count - 1]));
}

int convert_to_int(char *number) // zamiana slownych liczb na int
{
    char* slowa[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(slowa) / sizeof(slowa[0]);
    
    for (int i = 0; i < number_of_words; ++i) 
    {
        if (strcmp(number, slowa[i]) == 0) 
        {
            return i; 
        }
    }
    
    return atoi(number); 
}

int concat_int(int number1, int number2) // konkatenacja dwoch liczb
{
    char str_number1[20]; 
    char str_number2[20];
    sprintf(str_number1, "%d", number1);
    sprintf(str_number2, "%d", number2);

    strcat(str_number1, str_number2);
    int concatenated_number = atoi(str_number1);

    return concatenated_number;
}
