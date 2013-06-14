/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.sweetpome.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "PrimitiveElement.h"
using namespace cocos2d;

NS_CC_EXT_BEGIN

PrimitiveElementBase::PrimitiveElementBase()
{
    
}

PrimitiveElementBase::~PrimitiveElementBase()
{
    
}

void PrimitiveElementBase::draw()
{
    //override me
}

//line
PrimitiveElementLine::PrimitiveElementLine():
m_fStartPositionX(0),
m_fStartPositionY(0),
m_fEndPositionX(0),
m_fEndPositionY(0)
{
    
}

PrimitiveElementLine::~PrimitiveElementLine()
{
    
}

void PrimitiveElementLine::draw()
{
    PrimitiveElementBase::draw();
    cocos2d::ccDrawLine(ccp(m_fStartPositionX,m_fStartPositionY), ccp(m_fEndPositionX, m_fEndPositionY));
}

//point
PrimitiveElementPoint::PrimitiveElementPoint():
m_fPositionX(0),
m_fPositionY(0)
{
    
}

PrimitiveElementPoint::~PrimitiveElementPoint()
{
    
}

void PrimitiveElementPoint::draw()
{
    PrimitiveElementBase::draw();
    cocos2d::ccDrawPoint(ccp(m_fPositionX,m_fPositionY));
}

//Circle
PrimitiveElementCircle::PrimitiveElementCircle():
m_fCenterX(0),
m_fCenterY(0),
m_fRadius(0),
m_fAngle(0),
m_nSegments(0),
m_bDrawLineToCenter(false)
{
    
}

PrimitiveElementCircle::~PrimitiveElementCircle()
{
    
}

void PrimitiveElementCircle::draw()
{
    cocos2d::ccDrawCircle(ccp(m_fCenterX,m_fCenterY), m_fRadius, m_fAngle, m_nSegments, m_bDrawLineToCenter);
}

//QuadBezier
PrimitiveElementQuadBezier::PrimitiveElementQuadBezier():
m_fOriginX(0),
m_fOriginY(0),
m_fControlX(0),
m_fControlY(0),
m_fDestinationX(0),
m_fDestinationY(0),
m_nSegments(0)
{
    
}

PrimitiveElementQuadBezier::~PrimitiveElementQuadBezier()
{
    
}

void PrimitiveElementQuadBezier::draw()
{
    cocos2d::ccDrawQuadBezier(ccp(m_fOriginX, m_fOriginY), ccp(m_fControlX, m_fControlY), ccp(m_fDestinationX, m_fDestinationY), m_nSegments);
}

//CubicBezier
PrimitiveElementCubicBezier::PrimitiveElementCubicBezier():
m_fOriginX(0),
m_fOriginY(0),
m_fControl1X(0),
m_fControl1Y(0),
m_fControl2X(0),
m_fControl2Y(0),
m_fDestinationX(0),
m_fDestinationY(0),
m_nSegments(0)
{
    
}

PrimitiveElementCubicBezier::~PrimitiveElementCubicBezier()
{
    
}

void PrimitiveElementCubicBezier::draw()
{
    cocos2d::ccDrawCubicBezier(ccp(m_fOriginX, m_fOriginY), ccp(m_fControl1X, m_fControl1Y), ccp(m_fControl2X, m_fControl2Y),ccp(m_fDestinationX, m_fDestinationY), m_nSegments);
}

PrimitiveElementPoly::PrimitiveElementPoly():
m_bDrawable(false),
m_nNumOfVertices(0),
m_bClosePolygon(false)
{

}

PrimitiveElementPoly::~PrimitiveElementPoly()
{
    
}

void PrimitiveElementPoly::draw()
{
    if (!m_bDrawable || m_points.empty()) {
        return;
    }
    cocos2d::CCPoint *vertices = new cocos2d::CCPoint[m_points.size()];
    for (size_t i=0; i < m_points.size(); i++) {
        vertices[i] = m_points.at(i);
    }
    cocos2d::ccDrawPoly(vertices, m_points.size(), m_bClosePolygon);
    delete []vertices;
    vertices = NULL;
}

void PrimitiveElementPoly::pushPoint(float x, float y)
{
    this->m_points.push_back(ccp(x, y));
}
void PrimitiveElementPoly::clear()
{
    this->m_points.clear();
}
void PrimitiveElementPoly::changePoint(float x, float y, int index)
{
	if (m_points.size() < index)
	{
		return;
	}

	if (m_points.size() == index)
	{
		this->m_points.push_back(ccp(x, y));
	}
	else
	{
		this->m_points[index] = cocos2d::CCPoint(x, y);
	}
}

void PrimitiveElementPoly::deletePoint(unsigned int index)
{
	this->m_points.erase( this->m_points.begin()+index );
}

void PrimitiveElementPoly::startDraw()
{
    m_bDrawable = true;
}

NS_CC_EXT_END
