#include <stdio.h>
#include <stdlib.h>

float fahrenheit_for_celsius(float temperature){
    float celsius;
    celsius = (temperature - 32) * (5.0/9.0);
    return celsius;
}

float celsius_for_fahrenheit(float celsius){
    float fahrenheit;
    fahrenheit = ((celsius * 9) + 160)/5.0;
    return fahrenheit;
}

int main()
{
    float temperature;
    printf("Digite a temperatura em fahrenheit: \n");
    scanf("%f", &temperature);

    float celsius = fahrenheit_for_celsius(temperature);
    printf("Celsius: %.2f\n", celsius);

    printf("Digite a temperatura em celsius: \n");
    scanf("%f", &celsius);

    float fahrenheit = celsius_for_fahrenheit(celsius);
    printf("Celsius: %.2f\n", fahrenheit);

    return 0;
}
