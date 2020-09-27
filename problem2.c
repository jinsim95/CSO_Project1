#include <stdio.h>

/*
    Author: Jin Sim (js7771)
    Takes in number of inputs and start a for loop for that number of inputs. 
    For each iteration, take in the values for red, green, blue and store these 
    in their corresponding variables, red, green, blue. 
    Check to see if any of the three values are invalid, or namely, lower than 0 or 
    bigger than 255 (ff), in which case print out "INVALID". 
    If all the values are okay, print those decimal values in hex using %x.
*/
int main() {
    int i, numInput, red, green, blue;
    scanf("%d", &numInput);
    
    for (i=0; i<numInput; i++) {
        scanf("%d, %d, %d", &red, &green, &blue);
        if (red > 255 | red < 0 | green > 255 | green < 0 | blue > 255 | blue < 0) {
            printf("INVALID\n");
        }
        else {
            printf("#%02x%02x%02x\n", red, green, blue);
        }
    }
    
    return 0;
}