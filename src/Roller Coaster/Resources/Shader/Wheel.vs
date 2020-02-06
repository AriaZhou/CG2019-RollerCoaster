#version 430 core

layout(location = 0) in vec3 vertex;

uniform mat4 ProjectionMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 RotationMatrix;
uniform mat4 TransformMatrix;

void main(void)
{
    gl_Position = ProjectionMatrix * ModelViewMatrix * TransformMatrix * RotationMatrix * vec4(vertex, 1.0);
}
