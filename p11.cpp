#include <stdio.h>
#include <math.h>
double factorial_log2(int n) 
{
    double log2_factorial = 0.0;
    for (int i = 1; i <= n; i++) 
	{
        log2_factorial += log2(i);  
    }
    return log2_factorial;
}

int main() 
{
    int n = 25;
    double log2_factorial = factorial_log2(n);
    printf("log2(25!) = %.2f\n", log2_factorial);
    double log2_effective_keys = log2_factorial - log2(2);
    printf("log2(Effectively unique keys) = %.2f\n", log2_effective_keys);
    printf("Approximate number of possible keys: 2^%.2f\n", log2_factorial);
    printf("Approximate number of effectively unique keys: 2^%.2f\n", log2_effective_keys);

    return 0;
}