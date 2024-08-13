#include <stdio.h>

void floatSum();
void doubleSum();

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
    printf("Float Summary = %1.31f \n",sum);
}

void doubleSum(){
    double sum = 0;
    for (int i =0 ; i< 1000; i++){
        sum += .001;
    }
    printf("Double Summary = %1.31f \n",sum);
}
