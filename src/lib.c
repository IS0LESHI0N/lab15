#include "lib.h"

void calculate_digit_frequency(char *text, int *freq) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            freq[text[i] - '0']++; // увеличиваем частоту встречаемости соответствующей цифры
        }
    }
}
