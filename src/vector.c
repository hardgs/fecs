#include <Fecs/vector.h>

/* This Methods Is Very Basic. They Return Object And Easy Work */
vec4i getVec4i(int x,int y,int z,int w)
{
	vec4i temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.w = w;
	return temp;
}
vec3i getVec3i(int x,int y,int z)
{
	vec3i temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
}
vec2i getVec2i(int x,int y)
{
	vec2i temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

vec4f getVec4f(float x,float y,float z,float w)
{
	vec4f temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.w = w;
	return temp;
}
vec3f getVec3f(float x,float y,float z)
{
	vec3f temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
}
vec2f getVec2f(float x,float y)
{
	vec2f temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

vec4d getVec4d(double x,double y,double z,double w)
{
	vec4d temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.w = w;
	return temp;
}
vec3d getVec3d(double x,double y,double z)
{
	vec3d temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
}
vec2d getVec2d(double x,double y)
{
	vec2d temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

// Adding Vector Methods
vec4i addVec4i(vec4i f,vec4i n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	f.w+=n.w;
	return f;
}
vec3i addVec3i(vec3i f,vec3i n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	return f;
}
vec2i addVec2i(vec2i f,vec2i n)
{
	f.x+=n.x;
	f.y+=n.y;
	return f;
}

vec4f addVec4f(vec4f f,vec4f n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	f.w+=n.w;
	return f;
}
vec3f addVec3f(vec3f f,vec3f n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	return f;
}
vec2f addVec2f(vec2f f,vec2f n)
{
	f.x+=n.x;
	f.y+=n.y;
	return f;
}

vec4d addVec4d(vec4d f,vec4d n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	f.w+=n.w;
	return f;
} 
vec3d addVec3d(vec3d f,vec3d n)
{
	f.x+=n.x;
	f.y+=n.y;
	f.z+=n.z;
	return f;
} 
vec2d addVec2d(vec2d f,vec2d n)
{
	f.x+=n.x;
	f.y+=n.y;
	return f;
}

// Subing Vector Methods
vec4i subVec4i(vec4i f,vec4i n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	f.w-=n.w;
	return f;
}
vec3i subVec3i(vec3i f,vec3i n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	return f;
}
vec2i subVec2i(vec2i f,vec2i n)
{
	f.x-=n.x;
	f.y-=n.y;
	return f;
}

vec4f subVec4f(vec4f f,vec4f n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	f.w-=n.w;
	return f;
}
vec3f subVec3f(vec3f f,vec3f n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	return f;
}
vec2f subVec2f(vec2f f,vec2f n)
{
	f.x-=n.x;
	f.y-=n.y;
	return f;
}

vec4d subVec4d(vec4d f,vec4d n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	f.w-=n.w;
	return f;
} 
vec3d subVec3d(vec3d f,vec3d n)
{
	f.x-=n.x;
	f.y-=n.y;
	f.z-=n.z;
	return f;
} 
vec2d subVec2d(vec2d f,vec2d n)
{
	f.x-=n.x;
	f.y-=n.y;
	return f;
}

// Multing Vector Methods
vec4i multVec4i(vec4i f,vec4i n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	f.w*=n.w;
	return f;
}
vec3i multVec3i(vec3i f,vec3i n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	return f;
}
vec2i multVec2i(vec2i f,vec2i n)
{
	f.x*=n.x;
	f.y*=n.y;
	return f;
}

vec4f multVec4f(vec4f f,vec4f n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	f.w*=n.w;
	return f;
}
vec3f multVec3f(vec3f f,vec3f n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	return f;
}
vec2f multVec2f(vec2f f,vec2f n)
{
	f.x*=n.x;
	f.y*=n.y;
	return f;
}

vec4d multVec4d(vec4d f,vec4d n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	f.w*=n.w;
	return f;
} 
vec3d multVec3d(vec3d f,vec3d n)
{
	f.x*=n.x;
	f.y*=n.y;
	f.z*=n.z;
	return f;
} 
vec2d multVec2d(vec2d f,vec2d n)
{
	f.x*=n.x;
	f.y*=n.y;
	return f;
}

// Diving Vector Methods
vec4i divVec4i(vec4i f,vec4i n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	f.w/=n.w;
	return f;
}
vec3i divVec3i(vec3i f,vec3i n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	return f;
}
vec2i divVec2i(vec2i f,vec2i n)
{
	f.x/=n.x;
	f.y/=n.y;
	return f;
}

vec4f divVec4f(vec4f f,vec4f n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	f.w/=n.w;
	return f;
}
vec3f divVec3f(vec3f f,vec3f n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	return f;
}
vec2f divVec2f(vec2f f,vec2f n)
{
	f.x/=n.x;
	f.y/=n.y;
	return f;
}

vec4d divVec4d(vec4d f,vec4d n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	f.w/=n.w;
	return f;
} 
vec3d divVec3d(vec3d f,vec3d n)
{
	f.x/=n.x;
	f.y/=n.y;
	f.z/=n.z;
	return f;
} 
vec2d divVec2d(vec2d f,vec2d n)
{
	f.x/=n.x;
	f.y/=n.y;
	return f;
}