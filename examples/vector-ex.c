#include <Fecs/Vector.h>
#include <stdio.h>
#include <conio.h>

int main(){
	vec4f vertex2 = getVec4f(3,2,3,3);
	vec4f vertex = getVec4f(2.44,23.22,2.323,2.23);
	vec4f vertex3 = getVec4f(5,5,5,5);
	vec4f vertex4 = getVec4f(0,0,0,0);
	vec4f vertex5 =  getVec4f(2,2,2,2);
	
	vertex = subVec4f(vertex,vertex3);
	vertex = multVec4f(vertex,vertex4);
	vertex = addVec4f(vertex,vertex2);
	vertex = divVec4f(vertex,vertex5);
	
	printf("X: %f, Y: %f, Z: %f, W: %f\n",vertex.x,vertex.y,vertex.z,vertex.w);
	getch();
	return 0;
}