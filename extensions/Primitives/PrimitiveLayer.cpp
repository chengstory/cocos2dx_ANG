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


#include "PrimitiveLayer.h"
   
using namespace cocos2d;

NS_CC_EXT_BEGIN

void PrimitiveLayer::draw()
{
	ccDrawColor4B(m_cColor.r, m_cColor.g, m_cColor.b, m_cColor.a);
    CCLayer::draw();
    for (ElementMap::iterator i = m_elementMap.begin(); i!=m_elementMap.end(); i++)
    {
        i->second->draw();
    }
}

void PrimitiveLayer::addLine(const char * lineName,float startPosX,float startPosY,float endPosX,float endPosY)
{
    PrimitiveElementLine * line = new PrimitiveElementLine();
    line->setStrName(lineName);
    line->setStartPositionX(startPosX);
    line->setStartPositionY(startPosY);
    line->setEndPositionX(endPosX);
    line->setEndPositionY(endPosY);
    this->addLine(line);
}

template<class T>
T* PrimitiveLayer::findPrimitive(const char* name)
{
	ElementMap::iterator it = m_elementMap.find(name);

	T* Primitive = NULL;
	if (it == m_elementMap.end())
	{
		Primitive =  new T();
		Primitive->setStrName(name);
		this->addPrimitive(Primitive);
	}
	else
	{
		Primitive = ( (T*)it->second );
	}

	return Primitive;
}

template<class T>
void PrimitiveLayer::addPrimitive(T* primitive)
{
	m_elementMap.insert(ElementMap::value_type(primitive->getStrName(), primitive));
}

void PrimitiveLayer::deletePrimitive(const char* name)
{
	m_elementMap.erase(ElementMap::key_type(name));
}

PrimitiveElementLine* PrimitiveLayer::findLine(const char* lineName)
{
	ElementMap::iterator it = m_elementMap.find(lineName);

	PrimitiveElementLine* line = NULL;
	if (it == m_elementMap.end())
	{
		line =  new PrimitiveElementLine();
		line->setStrName(lineName);
		this->addLine(line);
	}
	else
	{
		line = ( (PrimitiveElementLine*)it->second );
	}

	return line;
}

void PrimitiveLayer::setLineStartPosX(const char* lineName, float startPosX)
{
	PrimitiveElementLine* line = findPrimitive<PrimitiveElementLine>(lineName);
	line->setStartPositionX(startPosX);
}

void PrimitiveLayer::setLineStartPosY(const char* lineName, float startPosY)
{
	PrimitiveElementLine* line = findPrimitive<PrimitiveElementLine>(lineName);
	line->setStartPositionY(startPosY);
}

void PrimitiveLayer::setLineEndPosX(const char* lineName, float endPosX)
{
	PrimitiveElementLine* line = findPrimitive<PrimitiveElementLine>(lineName);
	line->setEndPositionX(endPosX);
}

void PrimitiveLayer::setLineEndPosY(const char* lineName, float endPosY)
{
	PrimitiveElementLine* line = findPrimitive<PrimitiveElementLine>(lineName);
	line->setEndPositionY(endPosY);
}

void PrimitiveLayer::addLine(PrimitiveElementLine * line)
{
    m_elementMap.insert(ElementMap::value_type(line->getStrName(), line));
}

void PrimitiveLayer::removeLine(PrimitiveElementLine * line)
{
    m_elementMap.erase(ElementMap::key_type(line->getStrName()));
}

void PrimitiveLayer::removeLine(const char * lineName)
{
    m_elementMap.erase(ElementMap::key_type(lineName));
}

void PrimitiveLayer::addPoint(const char * pointName,float positionX,float positionY)
{
    PrimitiveElementPoint * point = new PrimitiveElementPoint();
    point->setStrName(pointName);
    point->setPositionX(positionX);
    point->setPositionY(positionY);
    this->addPoint(point);
}

void PrimitiveLayer::addPoint(PrimitiveElementPoint *point)
{
    m_elementMap.insert(ElementMap::value_type(point->getStrName(), point));
}

void PrimitiveLayer::removePoint(const char* pointName)
{
    m_elementMap.erase(pointName);
}

void PrimitiveLayer::removePoint(PrimitiveElementPoint *point)
{
    m_elementMap.erase(ElementMap::key_type(point->getStrName()));
}

void PrimitiveLayer::setPointPosX(const char* pointName,  float posX)
{
	PrimitiveElementPoint* point = findPrimitive<PrimitiveElementPoint>(pointName);
	point->setPositionX(posX);
}

void PrimitiveLayer::setPointPosY(const char* pointName,  float posY)
{
	PrimitiveElementPoint* point = findPrimitive<PrimitiveElementPoint>(pointName);
	point->setPositionX(posY);
}

void PrimitiveLayer::addCircle(const char *circleName, float centerX, float centerY, float radius, float angle, int segments, bool drawLineToCenter)
{
    PrimitiveElementCircle * circle = new PrimitiveElementCircle();
    circle->setStrName(circleName);
    circle->setCenterX(centerX);
    circle->setCenterY(centerY);
    circle->setRadius(radius);
    circle->setAngle(angle);
    circle->setSegments(segments);
    circle->setDrawLineToCenter(drawLineToCenter);
    this->addCircle(circle);
}

void PrimitiveLayer::addCircle(PrimitiveElementCircle *circle)
{
    m_elementMap.insert(ElementMap::value_type(circle->getStrName(), circle));
}

void PrimitiveLayer::removeCircle(const char *circleName)
{
    m_elementMap.erase(circleName);
}

void PrimitiveLayer::removeCircle(PrimitiveElementCircle *circle)
{
    m_elementMap.erase(ElementMap::key_type(circle->getStrName()));
}

void PrimitiveLayer::setCircleAttribute(const char* circleName, float centerX, float centerY, float radius, float angle, int segments, bool drawLineToCenter)
{
	PrimitiveElementCircle* circle = findPrimitive<PrimitiveElementCircle>(circleName);
	circle->setCenterX(centerX);
	circle->setCenterY(centerY);
	circle->setRadius(radius);
	circle->setAngle(angle);
	circle->setSegments(segments);
	circle->setDrawLineToCenter(drawLineToCenter);
}

void PrimitiveLayer::addQuadBezier(const char* qBezName,float originX,float originY,float controlX,float controlY,float destinationX,float destinationY,int segments)
{
    PrimitiveElementQuadBezier * qBez = new PrimitiveElementQuadBezier();
    qBez->setStrName(qBezName);
    qBez->setOriginX(originX);
    qBez->setOriginY(originY);
    qBez->setControlX(controlX);
    qBez->setControlY(controlY);
    qBez->setDestinationX(destinationX);
    qBez->setDestinationY(destinationY);
    qBez->setSegments(segments);
    this->addQuadBezier(qBez);
}

void PrimitiveLayer::addQuadBezier(PrimitiveElementQuadBezier* quadBezier)
{
    m_elementMap.insert(ElementMap::value_type(quadBezier->getStrName(), quadBezier));
}

void PrimitiveLayer::removeQuadBezier(const char* qBezName)
{
    m_elementMap.erase(qBezName);
}

void PrimitiveLayer::removeQuadBezier(PrimitiveElementQuadBezier* quadBezier)
{
    m_elementMap.erase(ElementMap::key_type(quadBezier->getStrName()));
}

void PrimitiveLayer::setQBezierAttribute(const char* qBezName,float originX,float originY,float controlX,float controlY,float destinationX,float destinationY,int segments)
{
	PrimitiveElementQuadBezier* qBez = findPrimitive<PrimitiveElementQuadBezier>(qBezName);
	qBez->setOriginX(originX);
	qBez->setOriginY(originY);
	qBez->setControlX(controlX);
	qBez->setControlY(controlY);
	qBez->setDestinationX(destinationX);
	qBez->setDestinationY(destinationY);
	qBez->setSegments(segments);
}

void PrimitiveLayer::addCubicBezier(const char* qBezName,float originX,float originY,float control1X,float control1Y,float control2X,float control2Y,float destinationX,float destinationY,int segments)
{
    PrimitiveElementCubicBezier * cBez = new PrimitiveElementCubicBezier();
    cBez->setStrName(qBezName);
    cBez->setOriginX(originX);
    cBez->setOriginY(originY);
    cBez->setControl1X(control1X);
    cBez->setControl1Y(control1Y);
    cBez->setControl2X(control1X);
    cBez->setControl2Y(control1Y);
    cBez->setDestinationX(destinationX);
    cBez->setDestinationY(destinationY);
    cBez->setSegments(segments);
    this->addCubicBezier(cBez);
}

void PrimitiveLayer::addCubicBezier(PrimitiveElementCubicBezier* cubicBezier)
{
    m_elementMap.insert(ElementMap::value_type(cubicBezier->getStrName(), cubicBezier));
}

void PrimitiveLayer::removeCubicBezier(const char* cBezName)
{
    m_elementMap.erase(cBezName);
}

void PrimitiveLayer::removeCubicBezier(PrimitiveElementCubicBezier* cubicBezier)
{
    m_elementMap.erase(ElementMap::key_type(cubicBezier->getStrName()));
}

void PrimitiveLayer::setCBezierAttribute(const char* cBezName,float originX,float originY,float controlX1,float controlY1, float controlX2, float controlY2, float destinationX,float destinationY,int segments)
{
	PrimitiveElementCubicBezier* cBez = findPrimitive<PrimitiveElementCubicBezier>(cBezName);
    cBez->setOriginX(originX);
    cBez->setOriginY(originY);
    cBez->setControl1X(controlX1);
    cBez->setControl1Y(controlY1);
    cBez->setControl2X(controlX2);
    cBez->setControl2Y(controlY2);
    cBez->setDestinationX(destinationX);
    cBez->setDestinationY(destinationY);
    cBez->setSegments(segments);
}

void PrimitiveLayer::addPoly(const char* polyName)
{
//    ElementMap::iterator temp = m_elementMap.find(polyName);
//    if(temp != m_elementMap.end())
//    {
//        return;
//    }
    
    PrimitiveElementPoly * poly = new PrimitiveElementPoly();
    poly->setStrName(polyName);
    m_elementMap.insert(ElementMap::value_type(poly->getStrName(), poly));
}

void PrimitiveLayer::pushPointToPoly(const char* polyName,float x,float y)
{
    ElementMap::iterator it = m_elementMap.find(polyName);
    PrimitiveElementPoly * poly = NULL;
    if(it != m_elementMap.end())
    {
        poly = (PrimitiveElementPoly*)(it->second);
    }
    poly->pushPoint(x, y);
}
void PrimitiveLayer::clearPoint(const char* elementName)
{
    ElementMap::iterator it = m_elementMap.find(elementName);
    if(it != m_elementMap.end())
    {
        ((PrimitiveElementPoly*)it->second)->clear();
    }
}
void PrimitiveLayer::removePoly(const char* polyName)
{
    m_elementMap.erase(polyName);
}

void PrimitiveLayer::startPolyDraw(const char *polyName)
{
    ElementMap::iterator it = m_elementMap.find(polyName);
    PrimitiveElementPoly * poly = NULL;
    if(it != m_elementMap.end())
    {
        poly = (PrimitiveElementPoly*)(it->second);
    }
    poly->startDraw();
}

void PrimitiveLayer::setPolyAttribute(const char* polyName, cocos2d::CCPoint point, int index)
{
	PrimitiveElementPoly* poly = findPrimitive<PrimitiveElementPoly>(polyName);
	poly->changePoint(point.x, point.y, index);
}

void PrimitiveLayer::deletePolyPoint(const char* polyName, unsigned int index)
{
	PrimitiveElementPoly* poly = findPrimitive<PrimitiveElementPoly>(polyName);
	poly->deletePoint(index);
}

void PrimitiveLayer::setColor(ccColor4B &c)
{
	m_cColor = c;
}

NS_CC_EXT_END

