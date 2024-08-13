#include <stdio.h>
#include <math.h>

/* Example output

Double Summary = 1.0000000000000006661338147750939
 error = 0.000000000000000666133814775  relative Error = 0.000000000000000666133814775
Float Summary = 0.9999907016754150390625000000000
 error = 0.000009298324584960937500000  relative Error = 0.000009298324584960937500000

*/
void floatSum();
void doubleSum();

double actual = 1.0;
float actualfloat = 1.0f;
int main()
{
    doubleSum();//Both ought to calculate 1.0
    floatSum();

    return 0;
}
void floatSum(){
    float sum = 0.0f;
    for (int i =0 ; i< 1000; i++){
        sum += .001;
    }
    float Error = fabs(actualfloat - sum);
    float relativeError = Error / actualfloat;
    printf("Float Summary = %1.31f \n error = %5.27f  relative Error = %5.27f\n",sum, Error, relativeError);
}

void doubleSum(){
    double sum = 0;
    for (int i =0 ; i< 1000; i++){
        sum += .001;
    }
    double Error =  fabs( actual - sum);
    double relativeError = Error / actual;
    printf("Double Summary = %1.31f \n error = %5.27f  relative Error = %5.27f\n",sum, Error, relativeError);
}
