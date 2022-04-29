#ifndef VISITOR_TEMPLATE_CXX11_H
#define VISITOR_TEMPLATE_CXX11_H

namespace visitor::cxx11 {

// ---------------------------
// --- Visitable templates ---
// ---------------------------

template <typename VISITOR_NUMBER_N, typename... REST_OF_VISITORS>
class Visitable : public Visitable<VISITOR_NUMBER_N>, public Visitable<REST_OF_VISITORS...>
{
public:

  using Visitable<VISITOR_NUMBER_N>::Accept;
  using Visitable<REST_OF_VISITORS...>::Accept;
};

template <typename VISITOR1>
class Visitable<VISITOR1>
{
public:

  virtual void Accept(VISITOR1&) = 0;
};

// ------------------------
// --- Visitor templates
// ------------------------


template <typename T1, typename... Types>
class Visitor : public Visitor<T1>, public Visitor<Types...>
{
public:

  using Visitor<T1>::Visit;
  using Visitor<Types...>::Visit;
};

template <typename T1>
class Visitor<T1>
{
public:

  virtual void Visit(T1&) = 0;
};


//template <typename CLASS1, typename CLASS2  = void, typename CLASS3  = void, typename CLASS4  = void, typename CLASS5  = void>
//class Visitor
//{
//public:
//    virtual ~Visitor() = default;

//    virtual void Visit(CLASS1&) = 0;
//    virtual void Visit(CLASS2&) = 0;
//    virtual void Visit(CLASS3&) = 0;
//    virtual void Visit(CLASS4&) = 0;
//    virtual void Visit(CLASS5&) = 0;
//};

//template <typename CLASS1,  typename CLASS2,  typename CLASS3,  typename CLASS4>
//class Visitor<CLASS1, CLASS2, CLASS3, CLASS4>
//{
//public:
//    virtual ~Visitor() = default;

//    virtual void Visit(CLASS1&) = 0;
//    virtual void Visit(CLASS2&) = 0;
//    virtual void Visit(CLASS3&) = 0;
//    virtual void Visit(CLASS4&) = 0;
//};

//template <typename CLASS1,  typename CLASS2,  typename CLASS3>
//class Visitor<CLASS1, CLASS2, CLASS3>
//{
//public:
//    virtual ~Visitor() = default;

//    virtual void Visit(CLASS1&) = 0;
//    virtual void Visit(CLASS2&) = 0;
//    virtual void Visit(CLASS3&) = 0;
//};


//template <typename CLASS1,  typename CLASS2>
//class Visitor<CLASS1, CLASS2>
//{
//public:
//    virtual ~Visitor() = default;

//    virtual void Visit(CLASS1&) = 0;
//    virtual void Visit(CLASS2&) = 0;
//};

//template <typename CLASS1>
//class Visitor<CLASS1>
//{
//public:
//    virtual ~Visitor() = default;

//    virtual void Visit(CLASS1&) = 0;
//};

} // END namespace visitor::cxx11

#endif // VISITOR_TEMPLATE_CXX11_H
