#version 120
uniform float time;

void main()
{
  // vec4  vertexPos = gl_Vertex;




    // transform the vertex position
   // gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	//gl_Position = gl_Position +cos(time*3)-vertexPos.x;
	//gl_Position.y = gl_Position.y +sin(time*2)+vertexPos.x*2;
	


    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;
}