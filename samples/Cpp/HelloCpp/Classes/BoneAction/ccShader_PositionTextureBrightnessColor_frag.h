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
uniform vec2 tcOffset[25];					\n\
void main()									\n\
{											\n\
	vec4 textureColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);			\n\
	float r = (textureColor.r / textureColor.a + red) * textureColor.a * alpha;			\n\
	float g = (textureColor.g / textureColor.a + green) * textureColor.a * alpha;		\n\
	float b = (textureColor.b / textureColor.a + blue) * textureColor.a * alpha;		\n\
	vec4 sample[25];																	\n\
	vec4 maxValue = vec4(0.0);\n\
	for (int i = 0; i < 25; i++)\n\
	{\n\
		sample[i] = texture2D(CC_Texture0, v_texCoord + tcOffset[i]);    \n\
		maxValue = max(sample[i], maxValue);\n\
	}\n\
	if(textureColor.a > 0)\n\
	{\n\
		gl_FragColor = vec4(1*maxValue.a,0,0,maxValue.a);\n\
	}\n\
	else\n\
	{\n\
		gl_FragColor = vec4(1*maxValue.a,0,0,maxValue.a);\n\
	}\n\
}\n\
";
