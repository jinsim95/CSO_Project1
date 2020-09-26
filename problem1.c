#include <stdio.h>
// I will be using string.h library to concatenate strings.
#include <string.h>

/*
    Takes in the decimal form of the number (decimal_num), the number of 
    bits the binary version of it will take up (c), and an initialized 
    character array (string) that will contain binary representation of 
    the given decimal number. 
    Returns the character array (string) that will contain binary representation 
    of the given decimal number.
*/
const char * decimalToBinary(int decimal_num, int c, char str[]) {
    int result;
    int i = 0;
    for (c-=1; c >= 0; c--)
    {
        result = decimal_num >> c;
        if (result & 1) {
            strcat(str, "1");
        }
        else {
            strcat(str, "0");
        }
        i++;
    }
    strcat(str, "\0");
    return str;

}

int main () {
    int i, numLines;
    // Month/Day Hour:Min:Sec = mo1mo2/d1d2 h1h2:mi1mi2:s1s2
    int mo1, mo2, d1, d2, h1, h2, mi1, mi2, s1, s2;
    int intArr[10];
    char mo1b[2], mo2b[5], d1b[3], d2b[5], h1b[3], h2b[5], mi1b[4], mi2b[5], s1b[4], s2b[5];
    char combined[32];
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
        // Have the mo1b(inary),...,s2b char arrays store the binary representations of 
        // the decimal numbers of mo1,...,s2, in string format. 
        decimalToBinary(intArr[0], 1, mo1b);
        decimalToBinary(intArr[1], 4, mo2b);
        decimalToBinary(intArr[2], 2, d1b);
        decimalToBinary(intArr[3], 4, d2b);
        decimalToBinary(intArr[4], 2, h1b);
        decimalToBinary(intArr[5], 4, h2b);
        decimalToBinary(intArr[6], 3, mi1b);
        decimalToBinary(intArr[7], 4, mi2b);
        decimalToBinary(intArr[8], 3, s1b);
        decimalToBinary(intArr[9], 4, s2b);

        strcpy(combined, mo1b);
        printf("combined,mo1b = %s\n", combined);
        strcat(combined, mo2b);
        printf("combined,mo2b = %s\n", combined);
        strcat(combined, d1b);
        printf("combined,d1b = %s\n", combined);
        strcat(combined, d2b);
        printf("combined,d2b = %s\n", combined);
        strcat(combined, h1b);
        printf("combined,h1b = %s\n", combined);
        strcat(combined, h2b);
        printf("combined,h2b = %s\n", combined);
        strcat(combined, mi1b);
        printf("combined,mi1b = %s\n", combined);
        strcat(combined, mi2b);
        printf("combined,mi2b = %s\n", combined);
        strcat(combined, s1b);
        printf("combined,s1b = %s\n", combined);
        strcat(combined, s2b);
        printf("combined,s2b = %s\n", combined);

        

        // Re-Initialize the char arrays containing binary values for next line(s).
        memset(mo1b, 0, 2);
        memset(mo2b, 0, 5);
        memset(d1b, 0, 3);
        memset(d2b, 0, 5);
        memset(h1b, 0, 3);
        memset(h2b, 0, 5);
        memset(mi1b, 0, 4);
        memset(mi2b, 0, 5);
        memset(s1b, 0, 4);
        memset(s2b, 0, 5);
        memset(combined, 0, 32);
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