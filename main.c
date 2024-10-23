#include <stdio.h>
#include <stdint.h>
#include <math.h>

int8_t vector_mult(int8_t *input, int8_t *input2, int dim){
    int8_t result = 0;
    for (int i=0;i<dim;i++){
        result += input[i] * input2[i];
    }
    return result;
}

double sigmoid(double x){
    return (1.0f / (1.0f + exp(-x)));
}

int main(){
    int8_t input[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    int8_t output[4] = {0, 0, 0, 1};
    int8_t weights[3] = {1, 2, 3};

    int8_t results[4];
    double error[4];
    for(int i = 0; i < 4; i++){
        int8_t temp[3] = {1}; temp[1] = input[i][0]; temp[2] = input[i][1];
        results[i] = vector_mult(temp, weights, 3);
        error[i] = output[i] - sigmoid(results[i]);
        error[i] *= error[i];
        printf("{%d, %d} => {%d} (%d), Sig: %f, Error: %f\n", input[i][0], input[i][1], results[i], output[i], sigmoid(results[i]), error[i]);
    }

    double sum;
    for(int i = 0; i < 4; i++){
        sum += error[i];
    }
    printf("Average Error: %f\n", sum / 4);
    
    return 0;
}




