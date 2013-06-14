/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.cocos2d-x.org
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

#ifndef __PrimitiveLayer_H__
#define __PrimitiveLayer_H__

#include <unordered_map>
#include "cocos2d.h"
#include "PrimitiveElement.h"
#include "ExtensionMacros.h"

NS_CC_EXT_BEGIN

/**
 *  PrimitiveLayer is inherited from CCLayer, using for rendering all primitive
 */
class PrimitiveLayer : public cocos2d::CCLayer
{
  typedef std::tr1::unordered_map<std::string, PrimitiveElementBase*>  ElementMap;
public:
    /**
     *	@brief renders Primitive
     */
    virtual void draw();
    
    /**
     *	@brief adds line to "m_elementMap"
     */
    void addLine(const char * lineName,float startPosX,float startPosY,float endPosX,float endPosY);
    void addLine(PrimitiveElementLine * line);

	/**
     *	@brief find line by line name
     */
	PrimitiveElementLine* findLine(const char* lineName);

	template<class T>
	T* findPrimitive(const char* name);

	template<class T>
	void addPrimitive(T* primitive);

	void deletePrimitive(const char* name);
	/**
     *	@brief set line position
     */
	void setLineStartPosX(const char* lineName, float startPosX);
	void setLineStartPosY(const char* lineName, float startPosY);
	void setLineEndPosX(const char* lineName, float endPosX);
	void setLineEndPosY(const char* lineName, float endPosY);
    
    /**
    *	@brief removes line from "m_elementMap"
    */
    void removeLine(PrimitiveElementLine * line);
    void removeLine(const char * lineName);
    
    /**
     *	@brief adds point to "m_elementMap"
     */
    void addPoint(const char * pointName,float positionX,float positionY);
    void addPoint(PrimitiveElementPoint * point);
    
    
    /**
     *	@brief removes point from "m_elementMap"
     */
    void removePoint(PrimitiveElementPoint * point);
    void removePoint(const char* pointName);

    /**
    *	@brief set point position
    */
    void setPointPosX(const char* pointName, float posX);
	void setPointPosY(const char* pointName, float posY);

    /**
     *	@brief adds circle to "m_elementMap"
     */
    void addCircle(const char * circleName,float centerX,float centerY,float radius,float angle,int segments,bool drawLineToCenter);
    void addCircle(PrimitiveElementCircle* circle);
    
    /**
     *	@brief removes circle from "m_elementMap"
     */
    void removeCircle(PrimitiveElementCircle * circle);
    void removeCircle(const char * circleName);

   /**
    *	@brief set circle attribute
    */
	void setCircleAttribute(const char* circleName, float centerX, float centerY, float radius, float angle, int segments, bool drawLineToCenter);
    
    /**
     *	@brief adds quad-bezier to "m_elementMap"
     */
    void addQuadBezier(const char* qBezName,float originX,float originY,float controlX,float controlY,float destinationX,float destinationY,int segments);
    void addQuadBezier(PrimitiveElementQuadBezier* quadBezier);
    
    /**
     *	@brief remove quad-bezier from "m_elementMap"
     */
    void removeQuadBezier(const char* qBezName);
    void removeQuadBezier(PrimitiveElementQuadBezier* quadBezier);

   /**
    *	@brief set QuadBezier attribute
    */
	void setQBezierAttribute(const char* qBezName,float originX,float originY,float controlX,float controlY,float destinationX,float destinationY,int segments);

    /**
     *	@brief adds cubic-bezier to "m_elementMap"
     */
    void addCubicBezier(const char* cBezName,float originX,float originY,float control1X,float control1Y,float control2X,float control2Y,float destinationX,float destinationY,int segments);
    void addCubicBezier(PrimitiveElementCubicBezier* cubicBezier);
    
    /**
     *	@brief remove cubic-bezier from "m_elementMap"
     */
    void removeCubicBezier(const char* cBezName);
    void removeCubicBezier(PrimitiveElementCubicBezier* cubicBezier);
    
   /**
    *	@brief set CubicBezier attribute
    */
	void setCBezierAttribute(const char* qBezName,float originX,float originY,float controlX1,float controlY1, float controlX2,float controlY2, float destinationX,float destinationY,int segments);

    /**
     *	@brief adds poly to "m_elementMap"
     */
    void addPoly(const char* polyName);
    void pushPointToPoly(const char* polyName,float x,float y);
    void clearPoint(const char* eleName);
    
    /**
     *	@brief remove poly from "m_elementMap"
     */
    void removePoly(const char* polyName);
    
    /**
     *	@brief start to render poly
     */
    void startPolyDraw(const char* polyName);

    /**
     *	@brief poly attribute
     */
	void setPolyAttribute(const char* polyName, cocos2d::CCPoint point, int index);

    /**
     *	@brief delete poly point at index.
     */
	void deletePolyPoint(const char* polyName, unsigned int index);

	void setColor(ccColor4B &c);
private:
    // stores all primitives
    ElementMap m_elementMap;
	
	ccColor4B m_cColor;
};

NS_CC_EXT_END

#endif
