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

#ifndef __PrimitiveElementBase_H__
#define __PrimitiveElementBase_H__

#define EP_SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: inline varType get##funName(void) const { return varName; }\
public: inline void set##funName(varType var){ varName = var; }

#include "cocos2d.h"
#include "ExtensionMacros.h"

NS_CC_EXT_BEGIN

/**
 *  PrimitiveElementBase is base class of primitive
 */
class PrimitiveElementBase
{
public:
    PrimitiveElementBase();
    virtual ~PrimitiveElementBase(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(const char *, m_strName, StrName);
};

/**
 *  PrimitiveElementLine is inherited from PrimitiveElementBase, being used for Line
 */
class PrimitiveElementLine : public PrimitiveElementBase
{
public:
    PrimitiveElementLine();
    virtual ~PrimitiveElementLine(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(float, m_fStartPositionX, StartPositionX);
    EP_SYNTHESIZE(float, m_fStartPositionY, StartPositionY);
    EP_SYNTHESIZE(float, m_fEndPositionX, EndPositionX);
    EP_SYNTHESIZE(float, m_fEndPositionY, EndPositionY);
};

/**
 *  PrimitiveElementPoint is inherited from PrimitiveElementBase, being used for point
 */
class PrimitiveElementPoint : public PrimitiveElementBase
{
public:
    PrimitiveElementPoint();
    virtual ~PrimitiveElementPoint(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(float, m_fPositionX, PositionX);
    EP_SYNTHESIZE(float, m_fPositionY, PositionY);
};

/**
 *  PrimitiveElementCircle is inherited from PrimitiveElementBase, being used for point
 */
class PrimitiveElementCircle : public PrimitiveElementBase
{
public:  
    PrimitiveElementCircle();
    virtual ~PrimitiveElementCircle(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(float, m_fCenterX, CenterX);
    EP_SYNTHESIZE(float, m_fCenterY, CenterY);
    EP_SYNTHESIZE(float, m_fRadius, Radius);
    EP_SYNTHESIZE(float, m_fAngle, Angle);
    EP_SYNTHESIZE(int, m_nSegments, Segments);
    EP_SYNTHESIZE(bool, m_bDrawLineToCenter, DrawLineToCenter);
};

/**
 *  PrimitiveElementQuadBezier is inherited from PrimitiveElementBase, being used for quad-Bezier
 */
class PrimitiveElementQuadBezier : public PrimitiveElementBase
{
public:
    PrimitiveElementQuadBezier();
    virtual ~PrimitiveElementQuadBezier(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(float, m_fOriginX, OriginX);
    EP_SYNTHESIZE(float, m_fOriginY, OriginY);
    EP_SYNTHESIZE(float, m_fControlX, ControlX);
    EP_SYNTHESIZE(float, m_fControlY, ControlY);
    EP_SYNTHESIZE(float, m_fDestinationX, DestinationX);
    EP_SYNTHESIZE(float, m_fDestinationY, DestinationY);
    EP_SYNTHESIZE(int, m_nSegments, Segments);
};

/**
 *  PrimitiveElementCubicBezier is inherited from PrimitiveElementBase, being used for cubic-Bezier
 */
class PrimitiveElementCubicBezier : public PrimitiveElementBase
{
public:
    PrimitiveElementCubicBezier();
    virtual ~PrimitiveElementCubicBezier(void);
public:
    virtual void draw();
    EP_SYNTHESIZE(float, m_fOriginX, OriginX);
    EP_SYNTHESIZE(float, m_fOriginY, OriginY);
    EP_SYNTHESIZE(float, m_fControl1X, Control1X);
    EP_SYNTHESIZE(float, m_fControl1Y, Control1Y);
    EP_SYNTHESIZE(float, m_fControl2X, Control2X);
    EP_SYNTHESIZE(float, m_fControl2Y, Control2Y);
    EP_SYNTHESIZE(float, m_fDestinationX, DestinationX);
    EP_SYNTHESIZE(float, m_fDestinationY, DestinationY);
    EP_SYNTHESIZE(int, m_nSegments, Segments);
};

/**
 *  PrimitiveElementPoly is inherited from PrimitiveElementBase, being used for poly
 */
class PrimitiveElementPoly : public PrimitiveElementBase
{
public:
    PrimitiveElementPoly();
    virtual ~PrimitiveElementPoly(void);
public:
    virtual void draw();
    void pushPoint(float x,float y);
	void changePoint(float x, float y, int index);
	void deletePoint(unsigned int index);
    void startDraw();
    void clear();
public:
    std::vector<cocos2d::CCPoint> m_points;
    EP_SYNTHESIZE(bool, m_bDrawable, Drawable);
    EP_SYNTHESIZE(cocos2d::CCPoint*, m_pVertices, Vertices);
    EP_SYNTHESIZE(int, m_nNumOfVertices, NumOfVertices);
    EP_SYNTHESIZE(bool, m_bClosePolygon, ClosePolygon);
};

NS_CC_EXT_END

#endif
