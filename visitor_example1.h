#ifndef VISITOR_EXAMPLE1_H
#define VISITOR_EXAMPLE1_H

#include "visitor_template_cxx03.h"
#include <vector>

namespace visitor::example1 {

class Square;
class Circle;
class Triangle;

//*****************************************************************
// The shape visitor base class.
// Pure virtual 'Visit' functions will be defined for the Square,
// Circle, and Triangle types.
//*****************************************************************
class ShapeVisitor : public cxx03::Visitor<Square, Circle, Triangle>
{
};


class Shape : public cxx03::Visitable<ShapeVisitor>
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

} // end namespace visitor::example1

int visitor_example1();



#endif // VISITOR_EXAMPLE1_H
