///////////////////////////////////////////////////////////
// Attributes
attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec3 a_normal;

///////////////////////////////////////////////////////////
// Uniforms
//uniform mat4 u_worldViewProjectionMatrix;
uniform mat4 u_projMat;
uniform mat4 u_worldViewMat;

///////////////////////////////////////////////////////////
// Varyings
varying vec2 v_texCoord;
varying vec2 v_normal;


void main()
{
    
    gl_Position = u_projMat * u_worldViewMat * a_position;
    v_texCoord = a_texCoord;
    
}
