// To convert a decimal value to its equal fraction expression
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int part1, repetend, flag, temp, counter1 = 0, counter2 = 0, numerator, denominator;
    printf("if contain non-repetend part:\n");
    scanf("%d", &flag); // if includes several numbers(part1) in front of repetend, flag = 1; else, flag = 0
    if (flag) {
        printf("non-repetend part:\n");
        scanf("%d", &part1);
        // how many digits of part1
        temp = part1;
        while (temp > 10) {
            temp /= 10;
            counter1++;
        }
        counter1++;
    }
    printf("repetend part:\n");
    scanf("%d", &repetend);
    // how many digits of repetend
    temp = repetend;
    while (temp > 10) {
        temp /= 10;
        counter2++;
    }
    counter2++;
    if (flag) {
        numerator = part1 * pow(10, counter2) + repetend - part1;
        for (; counter2--; counter2 > 0) {
            denominator *= 10;
            denominator += 9;
        }
        denominator *= pow(10, counter1);
    }
    else {
        numerator = repetend;
        for (; counter2--; counter2 > 0) {
            denominator *= 10;
            denominator += 9;
        }
    }
    printf("numerator: %d\n", numerator);
    printf("denominator: %d\n", denominator);
    return 0;
}
