
#include "visitor_example1.h"


#include <iostream>
#include <vector>

using namespace std;
namespace visitor::example1 {

//*****************************************************************
// The 'draw' visitor.
//*****************************************************************
class DrawVisitor : public ShapeVisitor
{
public:
    void Visit(Square& square) override
    {
        std::cerr << "Draw the square\n";
    }

    void Visit(Circle& circle) override
    {
        std::cerr << "Draw the circle\n";
    }

    void Visit(Triangle& triangle) override
    {
        std::cerr << "Draw the triangle\n";
    }
};

//*****************************************************************
// The 'serialise' visitor.
//*****************************************************************
class SerialiseVisitor : public ShapeVisitor
{
public:
    void Visit(Square& square) override
    {
        std::cerr << "Serialise the square\n";
    }

    void Visit(Circle& circle) override
    {
        std::cerr << "Serialise the circle\n";
    }

    void Visit(Triangle& triangle) override
    {
        std::cerr << "Serialise the triangle\n";
    }
};

} // END namespace visitor::example1


int visitor_example1()
{
    using namespace visitor::example1;
    cerr << "--- Visitor example 1 ---\n";
    //*****************************************************************
    // The actual visitors.
    //*****************************************************************
    DrawVisitor      draw_visitor;
    SerialiseVisitor serialise_visitor;


    // Create some shapes.
    Square   square;
    Circle   circle;
    Triangle triangle;

    // Add them to the vector
    std::vector<Shape*> shape_list;
    shape_list.push_back(&square);
    shape_list.push_back(&circle);
    shape_list.push_back(&triangle);

    // Apply the visitors.
    Apply(draw_visitor, shape_list);
    Apply(serialise_visitor, shape_list);


    return 0;
}

