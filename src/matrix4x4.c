#include <Fecs/matrix4x4.h>

// Adding Matrix 4x4 Methods
void addMat4f(mat4f result, const mat4f f, const mat4f n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] + n[i][j];
        }
    }
}

void addMat4i(mat4i result, const mat4i f, const mat4i n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] + n[i][j];
        }
    }
}

void addMat4d(mat4d result, const mat4d f, const mat4d n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] + n[i][j];
        }
    }
}

// Subing Matrix 4x4 Methods
void subMat4f(mat4f result, const mat4f f, const mat4f n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] - n[i][j];
        }
    }
}

void subMat4i(mat4i result, const mat4i f, const mat4i n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] - n[i][j];
        }
    }
}

void subMat4d(mat4d result, const mat4d f, const mat4d n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = f[i][j] - n[i][j];
        }
    }
}

// Multing Matrix 4x4 Methods
void multMat4f(mat4f result, const mat4f f, const mat4f n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result[i][j] += f[i][k] * n[k][j];
            }
        }
    }
}

void multMat4i(mat4i result, const mat4i f, const mat4i n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result[i][j] += f[i][k] * n[k][j];
            }
        }
    }
}

void multMat4d(mat4d result, const mat4d f, const mat4d n)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result[i][j] += f[i][k] * n[k][j];
            }
        }
    }
}

// Dividing Matrix 4x4 Methods
/* void divMat4f(mat4f result, const mat4f f, const mat4f n)
{
    mat4f invN;
    inverseMat4f(invN, n);
    multMat4f(result, f, invN);
}

void divMat4i(mat4i result, const mat4i f, const mat4i n)
{
	mat4i invN;
    inverseMat4i(invN, n);
    multMat4i(result, f, invN);
}

void divMat4d(mat4d result, const mat4d f, const mat4d n)
{
    mat4d invN;
    inverseMat4d(invN, n);
    multMat4d(result, f, invN);
} */