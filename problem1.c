#include <stdio.h>
// I will be using string.h library to concatenate strings.
#include <string.h>
// I will be using math.h library to use 'pow' function, which will be 
// used to "concatenate" two integers together.
// NOTE: The restrictions on README.md specified not to use math.h for 
// Problem 3 only, and so I have used this library for Problem 1, but not 3.
#include <math.h>

/*
    Author: Jin Sim (js7771)
    Takes in the decimal form of the number (decimal_num), the number of 
    bits the binary version of it will take up (c), and an initialized 
    character array (string) that will contain binary representation of 
    the given decimal number. 
    Returns the character array (string) that will contain binary representation 
    of the given decimal number.
*/
const char * decimalToBinary(int decimal_num, int c, char str[]) {
    int result;
    //printf("----- decimal_num = %d -----\n", decimal_num);
    for (c-=1; c >= 0; c--)
    {
        result = decimal_num >> c;
        //printf("The value of result is: %i\n", result);
        if (result & 1) {
            //printf("Concatenating 1\n");
            strcat(str, "1");
        }
        else {
            //printf("Concatenating 0\n");
            strcat(str, "0");
        }
    }
    //printf("Returning str = %s", str);
    return str;
}

// Author: Jin Sim (js7771)
// Takes in date/time and converts it to one numeric value for storing, then prints them out.
// If the given date/time is invalid, prints out "INVALID" instead.
int main () {
    int i, numLines, base, j, sum;
    // Month/Day Hour:Min:Sec = mo1mo2/d1d2 h1h2:mi1mi2:s1s2
    int mo1, mo2, d1, d2, h1, h2, mi1, mi2, s1, s2;
    int intArr[10];
    char mo1b[1], mo2b[4], d1b[2], d2b[4], h1b[2], h2b[4], mi1b[3], mi2b[4], s1b[3], s2b[4];
    char combined[33];
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
        //printf("mo1 = %d / mo2 = %d / d1 = %d / d2 = %d\n", mo1, mo2, d1, d2);
        //printf("h1 = %d / h2 = %d / mi1 = %d / mi2 = %d / s1 = %d / s2 = %d\n", h1, h2, mi1, mi2, s1, s2);
        
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

        // (Re)Initialize the char arrays containing binary values for next line(s).
        memset(mo1b, 0, 1);
        memset(mo2b, 0, 4);
        memset(d1b, 0, 2);
        memset(d2b, 0, 4);
        memset(h1b, 0, 2);
        memset(h2b, 0, 4);
        memset(mi1b, 0, 3);
        memset(mi2b, 0, 4);
        memset(s1b, 0, 3);
        memset(s2b, 0, 4);
        memset(combined, 0, 33);
        // bit 31 is never used and is always set equal to zero, so:
        strcpy(combined, "0");

        // I found the code for "concatenating" integers from StackOverflow:
        // url: https://stackoverflow.com/questions/12700497/how-to-concatenate-two-integers-in-c
        int month = (mo1 * pow(10, (int)log10(mo2)+1)) + mo2;
        int day = (d1 * pow(10, (int)log10(d2)+1)) + d2;
        int hour = (h1 * pow(10, (int)log10(h2)+1)) + h2;
        int minute = (mi1 * pow(10, (int)log10(mi2)+1)) + mi2;
        int second = (s1 * pow(10, (int)log10(s2)+1)) + s2;

        // Check if any of the month, day, hour, minute or second is an invalid number. 
        // If there is invalidity, change 'combined' string to "INVALID".
        if(month<1||month>12||day<1||day>31||hour<0||hour>23||minute<0||minute>59||second<0||second>59) {
            memset(combined, 0, 5);
            strcpy(combined, "INVALID");
            printf("%s\n", combined);
        }
        // If there is no invalidity with the input, proceed to convert each and every digit to 
        // its binary representation in char array. Then, concatenate all of them beginning with 
        // month all the way to second, storing them in one char array.
        else {
            strcat(combined, decimalToBinary(intArr[0], 1, mo1b));
            strcat(combined, decimalToBinary(intArr[1], 4, mo2b));
            strcat(combined, decimalToBinary(intArr[2], 2, d1b));
            strcat(combined, decimalToBinary(intArr[3], 4, d2b));
            strcat(combined, decimalToBinary(intArr[4], 2, h1b));
            strcat(combined, decimalToBinary(intArr[5], 4, h2b));
            strcat(combined, decimalToBinary(intArr[6], 3, mi1b));
            strcat(combined, decimalToBinary(intArr[7], 4, mi2b));
            strcat(combined, decimalToBinary(intArr[8], 3, s1b));
            strcat(combined, decimalToBinary(intArr[9], 4, s2b));
            //printf("Combined String = %s\n", combined);

            // Convert the resulting "combined" char array which contains the binary 
            // representation of all the input digits, into decimal form, then print it out.
            base = 1073741824; // i.e. 2^30
            sum = 0;
            for (j = 1; j<32; j++) {
                // Compare by ASCII value: "1" in ASCII is 49, so compare it with 49.
                if (combined[j] == 49) {
                    sum += base;
                }
                base = base / 2;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}