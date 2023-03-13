#include <stdio.h>
#include "lib.h"

int main() {
    char text[] = "В 1991 году Украина получила независимость, тогда моему папе было 18 лет!";
    int freq[10] = {0}; // массив для хранения частоты встречаемости цифр от 0 до 9

    calculate_digit_frequency(text, freq);

    printf("Частота встречаемости цифр в тексте:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, freq[i]);
    }

    return 0;
}
