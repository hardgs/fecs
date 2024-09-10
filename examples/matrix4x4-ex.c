#include <stdio.h>
#include <Fecs/matrix4x4.h>

int main()
{
    mat4f idle = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    mat4f transform = {
        {0, 3, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 2}
    };

    mat4f result;
    addMat4f(result, idle, transform);
    printf("Addition Result:\n");
    printf("%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n",
        result[0][0], result[0][1], result[0][2], result[0][3],
        result[1][0], result[1][1], result[1][2], result[1][3],
        result[2][0], result[2][1], result[2][2], result[2][3],
        result[3][0], result[3][1], result[3][2], result[3][3]);

    multMat4f(result, idle, transform);
    printf("Multiplication Result:\n");
    printf("%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n",
        result[0][0], result[0][1], result[0][2], result[0][3],
        result[1][0], result[1][1], result[1][2], result[1][3],
        result[2][0], result[2][1], result[2][2], result[2][3],
        result[3][0], result[3][1], result[3][2], result[3][3]);

    return 0;
}
