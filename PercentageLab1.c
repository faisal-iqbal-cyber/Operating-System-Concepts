#include <stdio.h>
int main() {
    int num1;
    printf("Please Enter Any Number: ");
    scanf("%d", &num1);

    float percentage = num1 * (25.0 / 100);

    printf("The 25%% of %d is %.2f\n", num1, percentage);  // Use %% for a literal % in printf.

    return 0;  // Explicit return statement
}
