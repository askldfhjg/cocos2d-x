/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2011 Ricardo Quesada
 * Copyright (c) 2012 Zynga Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

"											\n\
#ifdef GL_ES								\n\
precision lowp float;						\n\
#endif										\n\
											\n\
varying vec4 v_fragmentColor;				\n\
varying vec2 v_texCoord;					\n\
uniform sampler2D CC_Texture0;				\n\
uniform vec2 tcOffset[16];					\n\
vec3 outline = vec3(1,0,0);					\n\
void main()									\n\
{											\n\
	vec4 textureColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);			\n\
	vec4 sample[36];								\n\
	float maxValue = 0;\n\
    for (int i = 0; i < 16; i++)\n\
    {\n\
            sample[i] = texture2D(CC_Texture0, v_texCoord + tcOffset[i]);    \n\
            maxValue = max(sample[i].a, maxValue);\n\
			//maxValue = maxValue + sample[i].a;\n\
    }\n\
	//maxValue = maxValue / 16;\n\
	if(textureColor.a == 1)\n\
	{\n\
		gl_FragColor = textureColor;\n\
	}\n\
	else if(textureColor.a > 0)\n\
	{\n\
		vec4 tt = textureColor+vec4(outline,maxValue)*(1-textureColor.a);\n\
		gl_FragColor = vec4(tt.rgb*tt.a, tt.a);\n\
	}\n\
	else\n\
	{\n\
		gl_FragColor = vec4(1*maxValue,0,0,maxValue);\n\
	}\n\
}\n\
";