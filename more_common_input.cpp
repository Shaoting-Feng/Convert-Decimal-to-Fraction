// To convert a decimal value to its equal fraction expression
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long qpow(long long a, long long b)
{
    long long res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int num[1000], counterAll, i, counter1, counter2;
    num[0] = 0;
    string str;
    long long denominatorMax, part1, numerator, denominator, repetend, GCD, n, d;
    while (cin >> str, str != "0") {
        denominatorMax = 1e9 + 7;
        counterAll = 0;
        n = 0;
        d = 0;
        for (long long unsigned int i = 2; i <= str.length() - 4; i++) num[++counterAll] = str[i] - '0';
        counter1 = 0;
        part1 = 0;
        repetend = 0;
        for (i = 1; i <= counterAll; ++i) {
            repetend = repetend * 10 + num[i];
        }
        while (counter1 < counterAll) {
            part1 = part1 * 10 + num[counter1];
            counter2 = counterAll - counter1;
            repetend -= num[counter1] * qpow(10, counter2);
            numerator = part1 * qpow(10, counter2) + repetend - part1;
            denominator = 0;
            for (; counter2--; counter2 > 0) {
                denominator *= 10;
                denominator += 9;
            }
            denominator *= qpow(10, counter1);
            GCD = gcd(denominator, numerator);
            numerator /= GCD;
            denominator /= GCD;
            if (denominator < denominatorMax) {n = numerator; denominatorMax = d = denominator;};
            counter1++;
        }
        printf("%I64d", n);
        printf("/");
        printf("%I64d", d);
        printf("\n");
    }
    return 0;
}


