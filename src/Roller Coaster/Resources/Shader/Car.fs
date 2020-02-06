#version 430 core

in vec2 vUV;
in vec3 aNormal;
in vec3 fragPos;

uniform sampler2D Texture;
uniform vec3 color;

out vec4 fColor;

void main()
{
	fColor = texture2D(Texture,vUV);
	
	vec3 norm = normalize(aNormal);
	vec3 lightPos1 = vec3(0, 200.0, 200);
	vec3 lightColorDiff1 = vec3(0.9,0.9,0.9);
	vec3 lightColorAmbi1 = vec3(0.6,0.6,0.6);
	vec3 lightDir1 = normalize(lightPos1 - fragPos);
	vec3 lightPos2 = vec3(200, 0.0, 0);
	vec3 lightColorDiff2 = vec3(0.5,0.5,1);
	vec3 lightDir2 = normalize(lightPos2 - fragPos);
	vec3 lightPos3 = vec3(0, -200.0, 0);
	vec3 lightColorDiff3 = vec3(1,1,0.3);
	vec3 lightDir3 = normalize(lightPos3 - fragPos);
	
	float ambientStrength = 0.4;
	float diff1 = max(dot(norm, lightDir1), 0.0);
	float diff2 = max(dot(norm, lightDir2), 0.0);
	float diff3 = max(dot(norm, lightDir3), 0.0);
    vec3 ambient = lightColorAmbi1;
	//vec3 diffuse = diff1 * lightColorDiff1 + diff2 * lightColorDiff2 + diff3 * lightColorDiff3;
	vec3 diffuse = diff1 * lightColorDiff1;
	
	//fColor = vec4((ambient+diffuse) * color, 1.0);
}
