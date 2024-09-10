#ifndef FECS_MATRIX4X4_H
#define FECS_MATRIX4X4_H

#include <Fecs/vector.h>

typedef float mat4f[4][4];
typedef int mat4i[4][4];
typedef double mat4d[4][4];

// Adding Matrix 4x4 Methods
void addMat4f(mat4f result, const mat4f f, const mat4f n);
void addMat4i(mat4i result, const mat4i f, const mat4i n);
void addMat4d(mat4d result, const mat4d f, const mat4d n);

// Subing Matirx 4x4 Methods
void subMat4f(mat4f result, const mat4f f, const mat4f n);
void subMat4i(mat4i result, const mat4i f, const mat4i n);
void subMat4d(mat4d result, const mat4d f, const mat4d n);

// Multing Matrix 4x4 Methods
void multMat4f(mat4f result, const mat4f f, const mat4f n);
void multMat4i(mat4i result, const mat4i f, const mat4i n);
void multMat4d(mat4d result, const mat4d f, const mat4d n);

// Dividing Matrix 4x4 Methods
/* void divMat4f(mat4f result, const mat4f f, const mat4f n);
void divMat4i(mat4i result, const mat4i f, const mat4i n);
void divMat4d(mat4d result, const mat4d f, const mat4d n); */
#endif
