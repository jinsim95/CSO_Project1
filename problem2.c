#include <stdio.h>

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