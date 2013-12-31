#include "cocos2d.h"
#include "CCBones.h"
#include "Function.h"
#include "CCEffect.h"
#include "CCBoneActionManager.h"
USING_NS_CC;


int CCBones::weightListLength = 5;

CCBones *CCBones::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, std::string &name)
{
	CCBones *pobSprite = new CCBones();
    if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
    {
        pobSprite->autorelease();
		pobSprite->name = name;
		pobSprite->m_weightList = new CCBonePicWeight*[weightListLength];
		pobSprite->m_preventList = new int[weightListLength];
		for(int i =0; i < weightListLength;i++)
		{
			pobSprite->m_weightList[i] = NULL;
			pobSprite->m_preventList[i] = 0;
		}
		pobSprite->setShaderProgram(CCBones::getShader());
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

CCBones *CCBones::create(std::string &name)
{
	CCBones *pobSprite = new CCBones();
	if (pobSprite && pobSprite->init())
    {
        pobSprite->autorelease();
		pobSprite->name = name;
		pobSprite->m_weightList = new CCBonePicWeight*[weightListLength];
		pobSprite->m_preventList = new int[weightListLength];
		for(int i =0; i < weightListLength;i++)
		{
			pobSprite->m_weightList[i] = NULL;
			pobSprite->m_preventList[i] = 0;
		}
		pobSprite->setShaderProgram(CCBones::getShader());
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

CCGLProgram *CCBones::getShader()
{
	CCGLProgram *shader = CCShaderCache::sharedShaderCache()->programForKey("boneshader");
	if (!shader)
	{
		const GLchar * ccPositionTextureBrightnessColor_frag =
		#include "ccShader_PositionTextureBrightnessColor_frag.h"
		shader = new CCGLProgram();
		shader->initWithVertexShaderByteArray(ccPositionTextureColor_vert, ccPositionTextureBrightnessColor_frag);
		shader->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
		shader->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
		shader->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
		shader->link();
		shader->updateUniforms();
		CHECK_GL_ERROR_DEBUG();
		CCShaderCache::sharedShaderCache()->addProgram(shader, "boneshader");
		shader->release();
	}
	return shader;
}

CCBones::~CCBones(void)
{
	clearWeightList();
	CC_SAFE_DELETE_ARRAY(m_weightList);
	CC_SAFE_DELETE_ARRAY(m_preventList);
}
void CCBones::Reset()
{
	setPosition(m_startPosition);
	setRotationX(m_fStartAngleX);
	setRotationY(m_fStartAngleY);
	setScaleX(m_fStartScaleX);
	setScaleY(m_fStartAngleY);
}

const char *CCBones::getName()
{
	return this->name.c_str();
}

void CCBones::clearWeightList()
{
	if(m_weightList)
	{
		for(int i =0; i < weightListLength;i++)
		{
			CC_SAFE_DELETE(m_weightList[i]);
		}
	}

}
void CCBones::changeTexture(CCTexture2D * texture)
{
	CCRect rect = CCRectZero;
	rect.size = texture->getContentSize();
	setTexture(texture);
	setTextureRect(rect, false, rect.size);
}
void CCBones::setStartStatus(bool del)
{
	if(!del)
	{
		this->m_startPosition = this->getPosition();
		this->m_fStartAngleX = this->getRotationX();
		this->m_fStartAngleY = this->getRotationY();
		this->m_fStartScaleX = this->getScaleX();
		this->m_fStartScaleY = this->getScaleY();
		this->m_startVisable = this->isVisible();
	}
	else
	{
		this->m_fStartScaleX = this->getScaleX();
		this->m_fStartScaleY = this->getScaleY();
	}
}


void CCBones::setOffset(float top, float left)
{
     this->m_topOffset = top;
     this->m_leftOffset = left;
}

float CCBones::getTopOffset()
{
     return m_topOffset;
}
float CCBones::getLeftOffset()
{
     return m_leftOffset;
}

void CCBones::setRedPercent(float red)
{
	if(red > 1)
	{
		red = 1.0f;
	}
	if(red < -1)
	{
		red = -1.0f;
	}
	m_redPercent = red;
}
void CCBones::setGreenPercent(float green)
{
	if(green > 1)
	{
		green = 1.0f;
	}
	if(green < -1)
	{
		green = -1.0f;
	}
	m_greenPercent = green;
}
void CCBones::setBluePercent(float blue)
{
	if(blue > 1)
	{
		blue = 1.0f;
	}
	if(blue < -1)
	{
		blue = -1.0f;
	}
	m_bluePercent = blue;
}

void CCBones::setAlpha(float alpha)
{
	if(alpha > 1)
	{
		alpha = 1.0f;
	}
	if(alpha < 0)
	{
		alpha = 0;
	}
	m_alpha = alpha;
}

float CCBones::getAlpha()
{
	return m_alpha;
}

void CCBones::draw(void)
{
	CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");

    CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");

    CC_NODE_DRAW_SETUP();

    ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

    if (m_pobTexture != NULL)
    {
        ccGLBindTexture2D( m_pobTexture->getName() );
    }
    else
    {
        ccGLBindTexture2D(0);
    }

    ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex );
	//GLfloat step = 1.0f;
	//CCSize tmp = getTexture()->getContentSize();
	//float xInc = step / (GLfloat)(tmp.width);
	//float yInc = step / (GLfloat)(tmp.height);
	/*
	GLfloat texCoordOffsets[50];
	for(int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			texCoordOffsets[(((i*5)+j)*2)+0] = (-2.0f * xInc) + ((GLfloat)i * xInc);
			texCoordOffsets[(((i*5)+j)*2)+1] = (-2.0f * yInc) + ((GLfloat)j * yInc);
		}
	}
	*/
#define kQuadSize sizeof(m_sQuad.bl)
    long offset = (long)&m_sQuad;

    // vertex
    int diff = offsetof( ccV3F_C4B_T2F, vertices);
    glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));

    // texCoods
    diff = offsetof( ccV3F_C4B_T2F, texCoords);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

    // color
    diff = offsetof( ccV3F_C4B_T2F, colors);
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));

	GLint c0 = glGetUniformLocation(getShaderProgram()->getProgram(), "red");
	glUniform1f(c0, m_redPercent);
	GLint c1 = glGetUniformLocation(getShaderProgram()->getProgram(), "green");
	glUniform1f(c1, m_greenPercent);
	GLint c2 = glGetUniformLocation(getShaderProgram()->getProgram(), "blue");
	glUniform1f(c2, m_bluePercent);
	GLint c3 = glGetUniformLocation(getShaderProgram()->getProgram(), "alpha");
	glUniform1f(c3, m_alpha);
	/*GLint c4 = glGetUniformLocation(getShaderProgram()->getProgram(), "tcOffset");
	glUniform2fv(c4, 25, texCoordOffsets);*/

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    CHECK_GL_ERROR_DEBUG();


#if CC_SPRITE_DEBUG_DRAW == 1
    // draw bounding box
    CCPoint vertices[4]={
        ccp(m_sQuad.tl.vertices.x,m_sQuad.tl.vertices.y),
        ccp(m_sQuad.bl.vertices.x,m_sQuad.bl.vertices.y),
        ccp(m_sQuad.br.vertices.x,m_sQuad.br.vertices.y),
        ccp(m_sQuad.tr.vertices.x,m_sQuad.tr.vertices.y),
    };
    ccDrawPoly(vertices, 4, true);
#elif CC_SPRITE_DEBUG_DRAW == 2
    // draw texture box
    CCSize s = this->getTextureRect().size;
    CCPoint offsetPix = this->getOffsetPosition();
    CCPoint vertices[4] = {
        ccp(offsetPix.x,offsetPix.y), ccp(offsetPix.x+s.width,offsetPix.y),
        ccp(offsetPix.x+s.width,offsetPix.y+s.height), ccp(offsetPix.x,offsetPix.y+s.height)
    };
    ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW

    CC_INCREMENT_GL_DRAWS(1);

    CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}

void CCBones::setFrame(CCArray *boneArray, int frameInAll, int frameInAction)
{
	CCObject* child = NULL;
	CCARRAY_FOREACH(boneArray, child)
	{
		CCBones *ch = (CCBones *)child;
		if(frameInAll > ch->endFrame)
		{
			ch->setVisible(false);
			continue;
		}
		int_json::iterator it = ch->m_boneData->find(frameInAll);
		if(it != ch->m_boneData->end())
		{
			float posX =it->second->posX;
			float posY = it->second->posY;
			float scaleX = it->second->scaleX;
			float scaleY = it->second->scaleY;
			float skewX = it->second->skewX;
			float skewY = it->second->skewY;
			float visable = it->second->visable;

			ch->setRedPercent(it->second->colorRed);
			ch->setGreenPercent(it->second->colorGreen);
			ch->setBluePercent(it->second->colorBlue);
			
			
			float fX = 0;
			float fY = 0;



			if(ch->m_masked)
			{
				CCBoneClip *tm = (CCBoneClip *)ch->getParent();
				fX = tm->m_offsetX;
				fY = tm->m_offsetY;
			}
			ch->setPosition(ccp(ch->m_startPosition.x + posX - fX, ch->m_startPosition.y + posY - fY));
			ch->setRotationX(ch->m_fStartAngleX + skewX);
			ch->setRotationY(ch->m_fStartAngleY + skewY);
			ch->setScaleX(ch->m_fStartScaleX * scaleX);
			ch->setScaleY(ch->m_fStartScaleY * scaleY);

			bool vis = ch->isVisible();
			bool boolVisable = (bool)(int)visable;
			float alf = ch->getAlpha();
			if(vis != boolVisable || alf != visable)
			{ 
				if(boolVisable)
				{
					ch->setVisible(true);
					ch->setAlpha(1.0f);
				}
				else if(visable <= 0)
				{
					ch->setVisible(false);
					ch->setAlpha(0);
				}
				else
				{
					ch->setVisible(true);
					ch->setAlpha(visable);
				}
			}
		}
		else
		{
			if(frameInAction == 0)
			{
				ch->setPosition(ccp(ch->m_startPosition.x, ch->m_startPosition.y));
				ch->setRotationX(ch->m_fStartAngleX);
				ch->setRotationY(ch->m_fStartAngleY);
				ch->setScaleX(ch->m_fStartScaleX);
				ch->setScaleY(ch->m_fStartScaleY);
				ch->setVisible((bool)ch->m_startVisable);
			}
		}
	}
}
