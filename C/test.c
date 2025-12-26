#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    
    unsigned long long suma = 0;
    for (int i = 0; i <= 100000000; i++) {
        suma += i;
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Wynik: %llu\n", suma);
    printf("Czas C: %.4f sekundy\n", time_spent);
    return 0;
}