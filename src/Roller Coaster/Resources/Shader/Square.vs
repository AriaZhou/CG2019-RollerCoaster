#version 430 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

uniform mat4 ProjectionMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 RotationMatrix;
uniform mat4 TransformMatrix;

out vec2 vUV;
out vec3 fragPos;
out vec3 aNormal;

void main(void)
{
    gl_Position = ProjectionMatrix * ModelViewMatrix * TransformMatrix * RotationMatrix * vec4(vertex, 1.0);
    vUV = uv;
	aNormal = normal;
	fragPos = vertex;
}
