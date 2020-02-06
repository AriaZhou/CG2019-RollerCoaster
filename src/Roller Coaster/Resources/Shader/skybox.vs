#version 430 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 ProjectionMatrix;
uniform mat4 ModelViewMatrix;

void main()
{
    TexCoords = aPos;
    gl_Position = ProjectionMatrix * ModelViewMatrix * vec4((aPos+vec3(0,0.1,0))*1500, 1.0);
}  