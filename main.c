#include <stdio.h>
#include <math.h>

void inputArray(int arr[], int n) 
{
    for (int i = 0; i < n; i += 1) 
    {
        printf("Елемент %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Функція для аналізу масиву
void analyzeArray(int arr[], int n, double *geo_mean, double *arith_mean) 
{
    int positive_count = 0, negative_count = 0;
    double positive_product = 1.0, negative_sum = 0.0;

    for (int i = 0; i < n; i += 1) 
    {
        if (arr[i] > 0) 
        {
            positive_product *= arr[i];
            positive_count++;
        } else if (arr[i] < 0) 
        {
            negative_sum += arr[i];
            negative_count++;
        }
    }

    if (positive_count > 0) 
    {
        *geo_mean = pow(positive_product, 1.0 / positive_count);
    } else 
    {
        *geo_mean = 0;
    }

    if (negative_count > 0) 
    {
        *arith_mean = negative_sum / negative_count;
    } else 
    {
        *arith_mean = 0;
    }
}

int main() 
{
    system("chcp 65001");
    int n1, n2, n3;

    printf("Введіть кількість елементів для першого масиву: ");
    scanf("%d", &n1);
    int arr1[n1];

    printf("Введіть елементи першого масиву:\n");
    inputArray(arr1, n1);

    printf("\nВведіть кількість елементів для другого масиву: ");
    scanf("%d", &n2);
    int arr2[n2];

    printf("Введіть елементи другого масиву:\n");
    inputArray(arr2, n2);

    printf("\nВведіть кількість елементів для третього масиву: ");
    scanf("%d", &n3);
    int arr3[n3];

    printf("Введіть елементи третього масиву:\n");
    inputArray(arr3, n3);

    double geo_mean, arith_mean;

    printf("\nРезультати для першого масиву:\n");
    analyzeArray(arr1, n1, &geo_mean, &arith_mean);
    printf("Середнє геометричне позитивних: %.2lf\n", geo_mean);
    printf("Середнє арифметичне від’ємних: %.2lf\n", arith_mean);

    printf("\nРезультати для другого масиву:\n");
    analyzeArray(arr2, n2, &geo_mean, &arith_mean);
    printf("Середнє геометричне позитивних: %.2lf\n", geo_mean);
    printf("Середнє арифметичне від’ємних: %.2lf\n", arith_mean);

    printf("\nРезультати для третього масиву:\n");
    analyzeArray(arr3, n3, &geo_mean, &arith_mean);
    printf("Середнє геометричне позитивних: %.2lf\n", geo_mean);
    printf("Середнє арифметичне від’ємних: %.2lf\n", arith_mean);

    return 0;
}
