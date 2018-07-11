#version  330  core
out vec4 Fcolor;
in vec4 vFcolor;
in vec2 outtextrue;
uniform sampler2D ourTexture1; 
uniform sampler2D ourTexture2; 
in float mixvalue;

void main()
{
  //  Fcolor = mix(texture(ourTexture1,outtextrue),texture(ourTexture2,vec2(1.0-outtextrue.x,outtextrue.y)),mixvalue);
   //Fcolor = vec4(0.0f,1.0f,0.0f,1.0f);
   //Fcolor = vFcolor;
   //Fcolor = texture(ourTexture1,outtextrue);
  // Fcolor = vFcolor*texture(ourTexture1,outtextrue);
   Fcolor = mix(texture(ourTexture1,outtextrue),texture(ourTexture2,vec2(outtextrue.x,outtextrue.y)),mixvalue);
}