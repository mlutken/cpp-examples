#ifndef VISITOR_TEMPLATE_CXX03_H
#define VISITOR_TEMPLATE_CXX03_H

namespace visitor::cxx03 {


//template <typename VISITOR1, typename VISITOR2 = void, typename VISITOR3 = void, typename VISITOR4 = void>
//class Visitable
//{
//public:

//  virtual void Accept(VISITOR1&) = 0;
//  virtual void Accept(VISITOR2&) = 0;
//  virtual void Accept(VISITOR3&) = 0;
//  virtual void Accept(VISITOR4&) = 0;
//};

//template <typename VISITOR1, typename VISITOR2, typename VISITOR3>
//class Visitable<VISITOR1, VISITOR2, VISITOR3>
//{
//public:

//  virtual void Accept(VISITOR1&) = 0;
//  virtual void Accept(VISITOR2&) = 0;
//  virtual void Accept(VISITOR3&) = 0;
//};

//template <typename VISITOR1, typename VISITOR2>
//class Visitable<VISITOR1, VISITOR2>
//{
//public:

//  virtual void Accept(VISITOR1&) = 0;
//  virtual void Accept(VISITOR2&) = 0;
//};

//template <typename VISITOR1>
//class Visitable<VISITOR1>
//{
//public:

//  virtual void Accept(VISITOR1&) = 0;
//};


template <class VISITOR1>
class Visitable
{
public:
    virtual ~Visitable() = default;

    virtual void Accept(VISITOR1&) = 0;
};


// ------------------------
// --- Visitor templates
// ------------------------

template <typename CLASS1, typename CLASS2  = void, typename CLASS3  = void, typename CLASS4  = void, typename CLASS5  = void>
class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void Visit(CLASS1&) = 0;
    virtual void Visit(CLASS2&) = 0;
    virtual void Visit(CLASS3&) = 0;
    virtual void Visit(CLASS4&) = 0;
    virtual void Visit(CLASS5&) = 0;
};

template <typename CLASS1,  typename CLASS2,  typename CLASS3,  typename CLASS4>
class Visitor<CLASS1, CLASS2, CLASS3, CLASS4>
{
public:
    virtual ~Visitor() = default;

    virtual void Visit(CLASS1&) = 0;
    virtual void Visit(CLASS2&) = 0;
    virtual void Visit(CLASS3&) = 0;
    virtual void Visit(CLASS4&) = 0;
};

template <typename CLASS1,  typename CLASS2,  typename CLASS3>
class Visitor<CLASS1, CLASS2, CLASS3>
{
public:
    virtual ~Visitor() = default;

    virtual void Visit(CLASS1&) = 0;
    virtual void Visit(CLASS2&) = 0;
    virtual void Visit(CLASS3&) = 0;
};


template <typename CLASS1,  typename CLASS2>
class Visitor<CLASS1, CLASS2>
{
public:
    virtual ~Visitor() = default;

    virtual void Visit(CLASS1&) = 0;
    virtual void Visit(CLASS2&) = 0;
};

template <typename CLASS1>
class Visitor<CLASS1>
{
public:
    virtual ~Visitor() = default;

    virtual void Visit(CLASS1&) = 0;
};


} // END namespace visitor::cxx03
#endif // VISITOR_TEMPLATE_CXX03_H
