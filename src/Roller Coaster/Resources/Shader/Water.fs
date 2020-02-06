#version 430 core

in vec2 vUV;
in vec3 fragPos;

uniform sampler2D texture_flowmap;
uniform sampler2D texture_normal;
uniform samplerCube skybox;

uniform vec3 viewPos;
uniform vec4 tiling;
uniform vec4 flowTiling;
uniform float _time;

out vec4 fColor;

void main()
{
	//vec3 texNorm = texture2D(texture_normal, vUV).rgb;
	//vec3 norm =  normalize(vec3(texNorm.x, texNorm.z, texNorm.y)*2.0 - 1.0);
	
	vec2 flowSpeed = texture(texture_flowmap, vUV * flowTiling.xy + flowTiling.zw).rg * 2.0f - 1.0f;
    float phase = _time - floor(_time);
	vec4 texnormal = texture(texture_normal, vUV*tiling.xy + tiling.zw + flowSpeed * phase);
 
    //unpack normal map
    vec3 norm;
    norm.xz = texnormal.xy * 2.0f - 1.0f;
    norm.y = sqrt(1 - norm.x * norm.x - norm.z * norm.z);
	
	vec3 lightPos = vec3(0,800,0);
	vec3 lightColorDiff = vec3(0.8,0.8,0.8);
	vec3 lightColorAmbi = vec3(1,0.6,0)*0.4;
	vec3 lightDir = normalize(lightPos - fragPos);
	
	float diff = max(dot(norm, lightDir), 0.0);
    vec3 ambient = lightColorAmbi;
	vec3 diffuse = diff * lightColorDiff;
	
	//sample skybox
    vec3 viewDir = normalize(fragPos - viewPos);
    vec3 refDir = normalize(reflect(viewDir, norm));
    vec4 skyCol = texture(skybox, refDir);
	
	//vec4 color = texture2D(Texture,vUV);
	fColor = vec4(skyCol.xyz, 1);
	//fColor = color;
}
