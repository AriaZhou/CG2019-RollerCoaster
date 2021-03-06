#version 430 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;

uniform mat4 ProjectionMatrix;
uniform mat4 ModelViewMatrix;

out vec2 vUV;
out vec3 fragPos;

void main(void)
{
    gl_Position = ProjectionMatrix * ModelViewMatrix * (vec4(vertex, 1.0)-vec4(0,0.1f,0,0));
    vUV = uv;
	fragPos = vertex;
}
