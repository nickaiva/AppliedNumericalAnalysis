#include <stdio.h>
#include <math.h>

/* Example output


Double Summary = 1.0000000000000006661338147750939 	 error = 0.000000000000000666133814775  	relative Error = 0.000000000000000666133814775
Float Summary = 0.9999907016754150390625000000000 	 error = 0.000009298324584960937500000  	relative Error = 0.000009298324584960937500000
Double Summary = 0.9999999999999061861544191742723 	 error = 0.000000000000093813845580826  	relative Error = 0.000000000000093813845580826
Float Summary = 1.0000535249710083007812500000000 	 error = 0.000053524971008300781250000  	relative Error = 0.000053524971008300781250000
Double Summary = 0.9999999999980837550594969798112 	 error = 0.000000000001916244940503020  	relative Error = 0.000000000001916244940503020
Float Summary = 1.0009901523590087890625000000000 	 error = 0.000990152359008789062500000  	relative Error = 0.000990152359008789062500000
*/
void floatSum(int end, float step);
void doubleSum(int end, double step);

double actual = 1.0;
float actualfloat = 1.0f;

int main()
{
    doubleSum(1000, 0.001);//Both ought to calculate 1.0
    floatSum(1000,0.001);

    doubleSum(10000, 0.0001);//Both ought to calculate 1.0
    floatSum(10000,0.0001);

    doubleSum(100000, 0.00001);//Both ought to calculate 1.0
    floatSum(100000,0.00001);

    return 0;
}
void floatSum(int end, float step){
    float sum = 0.0f;
    for (int i =0 ; i< end; i++){
        sum += step;
    }
    float Error = fabs(actualfloat - sum);
    float relativeError = Error / actualfloat;
    printf("Float Summary = %1.31f \t error = %5.27f  \trelative Error = %5.27f\n",sum, Error, relativeError);
}

void doubleSum(int end, double step){
    double sum = 0;
    for (int i =0 ; i< end; i++){
        sum += step;
    }
    double Error =  fabs( actual - sum);
    double relativeError = Error / actual;
    printf("Double Summary = %1.31f \t error = %5.27f  \trelative Error = %5.27f\n",sum, Error, relativeError);
}
