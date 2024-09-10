/*
  * Writed by Hardgs
  * My Page In Github: www.github.com/hardgs
  * Fast Easy C STL.
*/
#ifndef FECS_VECTOR_H
#define FECS_VECTOR_H

// Variables

/* two Variable */
struct vec2f
{
	float x;
	float y;
};
typedef struct vec2f vec2f;

struct vec2d
{
	double x;
	double y;
};
typedef struct vec2d vec2d;

struct vec2i
{
	int x;
	int y;
};
typedef struct vec2i vec2i;

/* Three Variable */
struct vec3f
{
	float x;
	float y;
	float z;
};
typedef struct vec3f vec3f;

struct vec3d
{
	double x;
	double y;
	double z;
};
typedef struct vec3d vec3d;

struct vec3i
{
	int x;
	int y;
	int z;
};
typedef struct vec3i vec3i;

/* four Variable */
struct vec4f
{
	float x;
	float y;
	float z;
	float w;
};
typedef struct vec4f vec4f;

struct vec4d
{
	double x;
	double y;
	double z;
	double w;
};
typedef struct vec4d vec4d;

struct vec4i
{
	int x;
	int y;
	int z;
	int w;
};
typedef struct vec4i vec4i;

// Methods
/* This Methods Is Very Basic. They Return Object. Easy Work */
vec4i getVec4i(int x,int y,int z,int w);
vec3i getVec3i(int x,int y,int z);
vec2i getVec2i(int x,int y);

vec4f getVec4f(float x,float y,float z,float w);
vec3f getVec3f(float x,float y,float z);
vec2f getVec2f(float x,float y);

vec4d getVec4d(double x,double y,double z,double w);
vec3d getVec3d(double x,double y,double z);
vec2d getVec2d(double x,double y);

// Adding Vector Methods
vec4i addVec4i(vec4i f,vec4i n);
vec3i addVec3i(vec3i f,vec3i n);
vec2i addVec2i(vec2i f,vec2i n);

vec4f addVec4f(vec4f f,vec4f n);
vec3f addVec3f(vec3f f,vec3f n);
vec2f addVec2f(vec2f f,vec2f n);

vec4d addVec4d(vec4d f,vec4d n); 
vec3d addVec3d(vec3d f,vec3d n); 
vec2d addVec2d(vec2d f,vec2d n);

// Subing Vector Methods
vec4i subVec4i(vec4i f,vec4i n);
vec3i subVec3i(vec3i f,vec3i n);
vec2i subVec2i(vec2i f,vec2i n);

vec4f subVec4f(vec4f f,vec4f n);
vec3f subVec3f(vec3f f,vec3f n);
vec2f subVec2f(vec2f f,vec2f n);

vec4d subVec4d(vec4d f,vec4d n); 
vec3d subVec3d(vec3d f,vec3d n); 
vec2d subVec2d(vec2d f,vec2d n);

// Multing Vector Methods
vec4i multVec4i(vec4i f,vec4i n);
vec3i multVec3i(vec3i f,vec3i n);
vec2i multVec2i(vec2i f,vec2i n);

vec4f multVec4f(vec4f f,vec4f n);
vec3f multbec3f(vec3f f,vec3f n);
vec2f multVec2f(vec2f f,vec2f n);

vec4d multVec4d(vec4d f,vec4d n); 
vec3d multVec3d(vec3d f,vec3d n); 
vec2d multVec2d(vec2d f,vec2d n);

// Diving Vector Methods
vec4i divVec4i(vec4i f,vec4i n);
vec3i divVec3i(vec3i f,vec3i n);
vec2i divVec2i(vec2i f,vec2i n);

vec4f divVec4f(vec4f f,vec4f n);
vec3f divbec3f(vec3f f,vec3f n);
vec2f divVec2f(vec2f f,vec2f n);

vec4d divVec4d(vec4d f,vec4d n); 
vec3d divVec3d(vec3d f,vec3d n); 
vec2d divVec2d(vec2d f,vec2d n);
#endif