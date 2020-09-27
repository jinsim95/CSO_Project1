#include <stdio.h>

/*
    Author: Jin Sim (js7771)
    Takes in one number at a time, and checks to see if the number is equal to zero.
    If it is zero, the main returns immediately as it should not be processed and as 
    it marks the end of the series of input. For each of the 31 bits of 1 (0b00...01), 
    shift the binary representation of it to the left by 1 and conduct bitwise 'and' 
    operation against our given number, num.
    No return value, but instead prints out the two values after splitting the given number,
    num, namely x and y.
*/
int main() {
    int num = 1;
    while (num != 0) {
        scanf("%d", &num);
        if(num == 0) {
            return 0;
        }
        int x, y, i, bitCounter;
        x = 0;
        y = 0;
        bitCounter = 0;
        for(i=0; i<32-1; i++) {
            if ((1 << i) & num) {
                if (bitCounter%2 == 0)x|=(1<<i);
                else y|=(1<<i);
                bitCounter++;
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}