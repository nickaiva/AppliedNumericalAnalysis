#include <stdio.h>
/*

 How to convert fractional decimal to binary:

Following steps describe how to convert decimal to binary

Step1. First we convert the integral part of binary number to decimal.

Following steps describe how to convert decimal number to binary number:

S1: Divide the decimal number by 2
S2: Divide the quotient by 2
S3: Repeat the step 2 until we get quotient equal to zero.

Equivalent binary number would be remainders of each step in the reverse order.

Step2. Now we convert the fractional part of decimal number to binary.
Following steps describe how to convert floating decimal to binary

S1: Multiply the decimal number by 2
S2: Integral part of resultant decimal number will be first digit of fraction binary number.
S3: Repeat the S1 using only fractional part of decimal number and then S2.

Step3: Add the integral and fractional part of binary number.

Example for floating point decimal to binary:
For example we want to convert the decimal number 25.7 to binary number.

Step1: Conversions of 25 to binary.

S1:  25 / 2  Remainder : 1 , Quotient : 12
S2:  12 / 2  Remainder : 0 , Quotient : 6
S3:   6 / 2  Remainder : 0 , Quotient : 3
S4:   3 / 2  Remainder : 1 , Quotient : 1
S5:   1 / 2  Remainder : 1 , Quotient : 0

So equivalent binary number is: 11001

Step2: Conversions of .7 to binary.

S1: 0.7 * 2 = 1.4, Integral part = 1
S2: 0.4 * 2 = 0.8, Integral part = 0
S3: 0.8 * 2 = 1.6, Integral part = 1
S4: 0.6 * 2 = 1.2, Integral part = 1
S5: 0.2 * 2 = 0.4, Integral part = 0
S6: 0.4 * 2 = 0.8, Integral part = 0

So equivalent binary number is: 0.101100

Step 3: So binary value of decimal number 25.7 will be
11001 + 0.101100 = 1101.101100




*/

void dec_to_hexa_conversion(long int fraDecimal) ;
void dec_to_bin_conversion(long double fraDecimal);

int main()
{
    long double fraDecimal;
    printf("Enter any fractional decimal number: ");
    scanf("%Lf",&fraDecimal);
    dec_to_bin_conversion(fraDecimal);
    dec_to_hexa_conversion(fraDecimal);
    return 0;
}
void dec_to_bin_conversion(long double fraDecimal)
{
    long double fraBinary,bFractional = 0.0,dFractional,fraFactor=0.1;
    long int dIntegral,bIntegral=0;
    long int intFactor=1,remainder,temp;

    dIntegral = fraDecimal;
    dFractional = fraDecimal - dIntegral;
    while(dIntegral!=0)
    {
        remainder=dIntegral%2;
        bIntegral=bIntegral+remainder*intFactor;
        dIntegral=dIntegral/2;
        intFactor=intFactor*10;
    }
    for(int i=1; i<=6; i++)
    {
        dFractional = dFractional * 2;
        temp = dFractional;
        bFractional = bFractional + fraFactor* temp;
        if(temp ==1)
            dFractional = dFractional - temp;
        fraFactor=fraFactor/10;
    }
    fraBinary = bIntegral + bFractional;
    printf("Equivalent binary value: %Lf\t",fraBinary);
}
//integer part only!
void dec_to_hexa_conversion(long int decimal)
{

    if (decimal == 0)
    {
        printf("Hexadecimal: 0\n");
        return;
    }

    char hexadecimal[100];
    int indx = 0;

    while (decimal > 0)
    {
        long int remainder = decimal % 16;

        if (remainder < 10)
            hexadecimal[indx++] = remainder + '0';
        else
            hexadecimal[indx++] = remainder + 'A' - 10;

        decimal /= 16;
    }

    printf("Hexadecimal number is: ");

    for (int i = indx - 1; i >= 0; i--)
        printf("%c", hexadecimal[i]);

    printf("\n");
}
