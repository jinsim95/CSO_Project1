#include <stdio.h>
// I will be using string.h library to concatenate strings.
#include <string.h>

int main () {
    int i, j, numLines;
    // Month/Day Hour:Min:Sec = mo1mo2/d1d2 h1h2:mi1mi2:s1s2
    int mo1, mo2, d1, d2, h1, h2, mi1, mi2, s1, s2;
    int intArr[10];
    char mo1b[1], mo2b[4], d1b[2], d2b[4], h1b[2], h2b[4], mi1b[3], mi2b[4], s1b[3], s2b[4];
    
    /* 
        TO DO:
        1. Convert each mo1,...,s2 to binary in STRING, store them in mo1b,...,s2b.
        2. Concatenate mo1b through s2b to one character array[32]; (first index always 0).
        3. Convert the <string> binary number to <integer> decimal number.
    */

    scanf("%d", &numLines);

    // Ex: 11/25 12:53:32
    for (i=0; i<numLines; i++) {
        scanf("%1d%1d/%1d%1d", &mo1, &mo2, &d1, &d2);
        scanf("%1d%1d:%1d%1d:%1d%1d", &h1, &h2, &mi1, &mi2, &s1, &s2);
        printf("mo1 = %d / mo2 = %d / d1 = %d / d2 = %d\n", mo1, mo2, d1, d2);
        printf("h1 = %d / h2 = %d / mi1 = %d / mi2 = %d / s1 = %d / s2 = %d\n", h1, h2, mi1, mi2, s1, s2);
        intArr[0] = mo1;
        intArr[1] = mo2;
        intArr[2] = d1;
        intArr[3] = d2;
        intArr[4] = h1;
        intArr[5] = h2;
        intArr[6] = mi1;
        intArr[7] = mi2;
        intArr[8] = s1;
        intArr[9] = s2;
        
        int mask = 0b00000000000000000000000000000001;
        if (mo1 & mask) {
            mo1b[0] = "1";
        }
        else { 
            mo1b[0] = "0";
        }
        mo1b[0] = "h";
        printf("mo1b[0] = %s\n", mo1b);

        /* Convert to Binary:
        for(j=0; mo1>0; j++) {
            strcat(str, )
        }
        */
        
        /*
        Convert each mo1, mo2, ..., s1, s2 to binary number
        String str = "";
        strcat(str, mo1.binary), strcat(str, mo2.binary), ... , strcat(str, s2.binary);
        str == "1001010101001010101010101"
        Convert str to decimal value: https://www.geeksforgeeks.org/program-binary-decimal-conversion/
        */
    }
    return 0;
}