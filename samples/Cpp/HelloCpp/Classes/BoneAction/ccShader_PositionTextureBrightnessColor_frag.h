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
/*
"											\n\
#ifdef GL_ES								\n\
precision lowp float;						\n\
#endif										\n\
											\n\
varying vec4 v_fragmentColor;				\n\
varying vec2 v_texCoord;					\n\
uniform sampler2D CC_Texture0;				\n\
uniform vec2 tcOffset[25];					\n\
vec3 outline = vec3(1,0,0);					\n\
void main()									\n\
{											\n\
	vec4 textureColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);			\n\
	vec4 sample[25];								\n\
	vec4 tmp;\n\
    for (int i = 0; i < 25; i++)\n\
    {\n\
            tmp = texture2D(CC_Texture0, v_texCoord + tcOffset[i]);    \n\
			sample[i] = vec4(1,0,0,tmp.a);\n\
    }\n\
	gl_FragColor = ((1.0  * (sample[0] + sample[4]  + sample[20] + sample[24])) +\n\
					(4.0  * (sample[1] + sample[3]  + sample[5]  + sample[9] + sample[15] + sample[19] + sample[21] + sample[23])) +\n\
					(7.0  * (sample[2] + sample[10] + sample[14] + sample[22])) +\n\
					(16.0 * (sample[6] + sample[8]  + sample[16] + sample[18])) +\n\
					(26.0 * (sample[7] + sample[11] + sample[13] + sample[17])) +\n\
					(41.0 * sample[12])) / 273.0;\n\
}\n\
";
*/

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
uniform float red;							\n\
uniform float blue;							\n\
uniform float green;						\n\
uniform float alpha;						\n\
void main()									\n\
{											\n\
	vec4 textureColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);			\n\
	float r = (textureColor.r / textureColor.a + red) * textureColor.a * alpha;			\n\
	float g = (textureColor.g / textureColor.a + green) * textureColor.a * alpha;		\n\
	float b = (textureColor.b / textureColor.a + blue) * textureColor.a * alpha;		\n\
	gl_FragColor = vec4(r,g,b,textureColor.a * alpha);\n\
}\n\
";
