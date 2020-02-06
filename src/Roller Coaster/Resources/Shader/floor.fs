#version 430 core

in vec2 vUV;
in vec3 fragPos;

uniform sampler2D Texture;
uniform sampler2D texture_normal;
uniform sampler2D depth_map;

uniform vec3 viewPos;

out vec4 fColor;

vec2 ParallaxMapping(vec2 texCoords, vec3 viewDir)
{ 
    float height =  texture(depth_map, texCoords).r;     
    return texCoords - viewDir.xy * (height * 10);        
}

void main()
{
	vec3 viewDir = normalize(viewPos - fragPos);
    vec2 texCoords = vUV;
    
    //texCoords = ParallaxMapping(vUV, viewDir);
    //if(texCoords.x > 1.0 || texCoords.y > 1.0 || texCoords.x < 0.0 || texCoords.y < 0.0)
    //    discard;

	vec3 texNorm = texture2D(texture_normal, texCoords).rgb;
	vec3 norm = normalize(vec3(texNorm.x, texNorm.z, texNorm.y)*2.0 - 1.0);
	
	vec3 lightPos = vec3(0,800,0);
	vec3 lightColorDiff = vec3(0.8,0.8,0.8);
	vec3 lightColorAmbi = vec3(1,1,1)*0.2;
	vec3 lightDir = normalize(lightPos - fragPos);
	
	float diff = max(dot(norm, lightDir), 0.0);
    vec3 ambient = lightColorAmbi;
	vec3 diffuse = diff * lightColorDiff;
	
	vec4 color = texture2D(Texture,texCoords);
	//fColor = color;
	fColor = vec4(ambient+diffuse,1)*color;
}
