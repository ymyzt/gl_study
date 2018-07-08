#version  330  core 
out vec4 Fcolor;
in vec2 outtextrue;
uniform sampler2D ourTexture1; 
uniform sampler2D ourTexture2; 
void main()
{
    Fcolor = mix(texture(ourTexture1,outtextrue),texture(ourTexture2,vec2(1.0-outtextrue.x,outtextrue.y)),0.2);
}