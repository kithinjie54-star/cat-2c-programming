#include <stdio.h>

int main() {
    float hours, rate, grossPay, tax, netPay;
    
    // Request input from user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    
    printf("Enter hourly wage: ");
    scanf("%f", &rate);
    
    // Calculate gross pay
    if (hours > 40)
        grossPay = (40 * rate) + ((hours - 40) * rate * 1.5);
    else
        grossPay = hours * rate;
    
    // Calculate tax
    if (grossPay <= 600)
        tax = 0.15 * grossPay;
    else
        tax = (0.15 * 600) + (0.20 * (grossPay - 600));
    
    // Calculate net pay
    netPay = grossPay - tax;
    
    // Display results
    printf("\nGross Pay: $%.2f", grossPay);
    printf("\nTax: $%.2f", tax);
    printf("\nNet Pay: $%.2f\n", netPay);
    
    return 0;
}