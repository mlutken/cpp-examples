#ifndef VISITOR_EXAMPLE0_H
#define VISITOR_EXAMPLE0_H

#include <vector>

namespace visitor::example0 {

class Square;
class Circle;
class Triangle;

//*****************************************************************
// The shape visitor base class.
// Pure virtual 'Visit' functions will be defined for the Square,
// Circle, and Triangle types.
//*****************************************************************
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() = default;

    virtual void Visit(Square&) = 0;
    virtual void Visit(Circle&) = 0;
    virtual void Visit(Triangle&) = 0;
};

class ShapeVisitable
{
public:
    virtual ~ShapeVisitable() = default;

    virtual void Accept(ShapeVisitor&) = 0;
};


class Shape : public ShapeVisitable
{
};


//*****************************************************************
// The square class
//*****************************************************************

class Square : public Shape
{
    void Accept(ShapeVisitor& visitor) override
    {
        visitor.Visit(*this);
    }
};

//*****************************************************************
// The circle class
//*****************************************************************
class Circle : public Shape
{
    void Accept(ShapeVisitor& visitor) override
    {
        visitor.Visit(*this);
    }
};

//*****************************************************************
// The triangle class
//*****************************************************************
class Triangle : public Shape
{
    void Accept(ShapeVisitor& visitor) override
    {
        visitor.Visit(*this);
    }
};



//*****************************************************************
// The Apply a visitor.
//*****************************************************************
inline void Apply(ShapeVisitor &visitor, std::vector<Shape*> shape_list)
{
    for (Shape* shape_ptr : shape_list)
    {
        // Send the visitor to the shape.
        shape_ptr->Accept(visitor);
    }
}

} // end namespace visitor::example0

int visitor_example0();



#endif // VISITOR_EXAMPLE0_H
