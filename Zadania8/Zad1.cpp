#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX_NUMBERS 20
#define MAX_DIGITS 10

int decode(const std::string &line);
int convert_to_int(const std::string &number);
int concat_int(int number1, int number2);

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;
    int sum2 = 0;

    // CZĘŚĆ 1
    while (std::getline(file, line)) {
        int first_digit = -1;
        int last_digit = -1;

        // Szukamy pierwszej cyfry na początku linii
        for (char c : line) {
            if (std::isdigit(c)) {
                first_digit = c - '0';
                break;
            }
        }

        // Szukamy ostatniej cyfry na końcu linii
        for (int i = line.size() - 1; i >= 0; i--) {
            if (std::isdigit(line[i])) {
                last_digit = line[i] - '0';
                break;
            }
        }

        // Jeśli znaleziono obie cyfry, tworzymy liczbę i wyświetlamy ją
        if (first_digit != -1 && last_digit != -1) {
            int number = first_digit * 10 + last_digit;
            std::cout << "Wynik: " << number << std::endl;
            sum += number;
        }
    }
    std::cout << "Suma wartości energetycznych w naszym podręczniku to " << sum << std::endl;
    file.close();

    // CZĘŚĆ 2
    std::ifstream file2("input.txt");

    while (std::getline(file2, line)) {
        int energy = decode(line);
        std::cout << energy << std::endl;
        sum2 += energy;
    }
    std::cout << "Suma wartości energetycznych w naszym podręczniku to " << sum2 << std::endl;
    file2.close();

    return 0;
}

int decode(const std::string &line) {
    int count = 0;
    std::string numbers[MAX_NUMBERS];

    std::string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(words) / sizeof(words[0]);

    // Przeszukiwanie ciągu znaków, by znaleźć podciągi lub cyfry
    for (size_t i = 0; i < line.length(); ++i) {
        if (std::isdigit(line[i])) {
            std::string str(1, line[i]);
            numbers[count] = str;
            count++;
        } else {
            for (int j = 0; j < number_of_words; ++j) {
                if (line.compare(i, words[j].length(), words[j]) == 0) {
                    numbers[count] = words[j];
                    count++;
                    i += words[j].length() - 1;
                    break;
                }
            }
        }
    }
    return concat_int(convert_to_int(numbers[0]), convert_to_int(numbers[count - 1]));
}

int convert_to_int(const std::string &number) {
    std::string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int number_of_words = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < number_of_words; ++i) {
        if (number == words[i]) {
            return i + 1;
        }
    }

    return std::atoi(number.c_str());
}

int concat_int(int number1, int number2) {
    std::string str_number1 = std::to_string(number1);
    std::string str_number2 = std::to_string(number2);

    str_number1 += str_number2;
    int concatenated_number = std::stoi(str_number1);

    return concatenated_number;
}
