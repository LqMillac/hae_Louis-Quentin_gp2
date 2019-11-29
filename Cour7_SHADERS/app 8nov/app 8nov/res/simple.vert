#version 120
uniform float time;

void main()
{
   vec4  vertexPos = gl_Vertex;
   //espace monde x( 0 1280)

   vertexPos.xy += time * 300;

    // transform the vertex position
    gl_Position = gl_ModelViewProjectionMatrix * vertexPos;

	//espace homogene x( -1 1.0 )

	//gl_Position.xy += time * 300 / 1280.0; 

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    // forward the vertex color
    gl_FrontColor = gl_Color;
}