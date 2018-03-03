
precision mediump float;
//#endif

///////////////////////////////////////////////////////////
// Uniforms
uniform sampler2D u_texture;
///////////////////////////////////////////////////////////
// Varyings
varying vec2 v_texCoord;


void main()
{
    
    //gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
    gl_FragColor = texture2D(u_texture, v_texCoord);
}

