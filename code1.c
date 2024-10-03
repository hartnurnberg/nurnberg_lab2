#include <stdio.h>

int main() {
    int td = 6; // Touchdown
    int fg = 3; // Field goal
    int safety = 2; // Safety
    int tpc = 8; // Two-point conversion
    int ep = 7; // Extra point
    int counts[] = {0, 0, 0, 0, 0}; // Count of each score scenario, highest score type to lowest (two point conversion down to safety)
    int score; // Desired score

    scanf("%d", &score); // User gives score

    if (score <=1) { // Ensure score is valid
        return 0;
    }

    for (int tp=0; tp<=score; tp+=tpc) { // Loop for adding touchdown+2pt to score
        counts[1] = 0;
        for (int e=0; e<=score; e+=ep) { // Loop for adding touchdown+fg to score
            counts[2] = 0;
            for (int t=0; t<=score; t+=td){ // Loop for adding touchdown to score
                counts[3] = 0;
                for (int f=0; f<=score; f += fg) { // Loop for adding 3pt fg to score
                    counts[4] = 0;
                    for (int saf=0; saf<=score; saf += safety) { // Loop for adding safety to score
                        if ((tp + e + t + f + saf) == score) { // Check whether score has been reached exactly
                            printf("%d TD + 2pt, %d TD + fg, %d TD, %d 3pt FG, %d Safety\n", counts[0], counts[1], counts[2], counts[3], counts[4]); // Print scoring scenario
                        }
                        counts[4]++;
                    }
                    counts[3]++;
                }
                counts[2]++;
            }
            counts[1]++;
        }
        counts[0]++;
    }
    return 1;
}