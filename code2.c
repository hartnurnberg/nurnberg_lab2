#include <stdio.h>
#include <string.h>

float c_to_f(float temp) {
    return 9*temp/5 + 32;
}

float f_to_c(float temp) {
    return (5.0/9.0)*(temp - 32);
}

float c_to_k(float temp) {
    return temp + 273.15;
}

float k_to_c(float temp) {
    return temp - 273.15;
}

float f_to_k(float temp) {
    temp = f_to_c(temp);
    temp = c_to_k(temp);
    return temp;
}

float k_to_f(float temp) {
    temp = k_to_c(temp);
    temp = c_to_f(temp);
    return temp;
}

float convertTemp(int scale, int target, float temp) {
    float finalTemp;
        // Convert user's temperature to the desired scale
    switch (scale) {
        case 1: // Convert from celcius
            if (target == 2) {
                finalTemp = c_to_f(temp);
            } else {
                finalTemp = c_to_k(temp);
            }
            break;
        case 2: // Convert from Fahrenheit
            if (target == 1) {
                finalTemp = f_to_c(temp);
            } else {
                finalTemp = f_to_k(temp);
            }
            break;
        case 3: // Convert from Kelvin
            if (target == 1) {
                finalTemp = k_to_c(temp);
            } else {
                finalTemp = k_to_f(temp);
            }
    }
    return finalTemp;   
}

int main() {
    float temp;
    float tempC;
    float finalTemp;
    int validScale = 0;
    int validTarget = 0;
    int validTemp = 0;
    int scale;
    int target;
    char condition[100];
    char advice[100];

    while (!validScale) {
        printf("What temp scale is this temp (type 1 for celcius, 2 for fahrenheit, 3 for kelvin)? ");
        scanf("%d", &scale);
        if (scale >= 1 && scale <= 3) {
            validScale = 1;
        } else {
            printf("Invalid input. Enter 1, 2, or 3.\n");
        }
    }

    while (!validTarget) {
        printf("What temp scale would you like to convert to (type 1 for celcius, 2 for fahrenheit, 3 for kelvin)?");
        scanf("%d", &target);
        if (scale >= 1 && scale <= 3) {
            if (scale == target) {
                printf("Convert to a different scale.\n");
            } else {
                validTarget = 1;
            }
        }
    }

    while (!validTemp) {
        printf("What is the starting temp?");
        scanf("%f", &temp);
        if (scale == 3 && temp < 0) {
            printf("Invalid input. Kelvin must be positive.\n");
        } else {
            validTemp = 1;
        }
    }      

    // Convert temp to desired scale
    finalTemp = convertTemp(scale, target, temp);

    // Convert temp to celcius for weather advisory use
    if (scale != 1) { // If temperature scale didn't start in celcius
        tempC = convertTemp(scale, 2, temp); // Convert temp to celcius
    } else {
        tempC = temp; // Original temperature is in celcius
    }

    if (tempC < 0) {
        strcpy(condition, "Freezing");
        strcpy(advice, "Watch for ice.");
    } else if (tempC >= 0 && tempC < 10) {
        strcpy(condition, "Cold");
        strcpy(advice, "Wear a jacket.");
    } else if (tempC >= 10 && tempC < 25) {
        strcpy(condition, "Comfortable");
        strcpy(advice, "Take a walk.");
    } else if (tempC >= 25 && tempC < 35) {
        strcpy(condition, "Hot");
        strcpy(advice, "Drink water.");
    } else {
        strcpy(condition, "Extreme heat");
        strcpy(advice, "Stay inside.");
    }

    printf("Converted temperature: %f\n", finalTemp);
    printf("Weather: %s. Advisory: %s\n", condition, advice);
}