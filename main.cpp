#include "book.h"

namespace KwonYeonseo2649004
{
    void parVal(book b){b+=1;}
    void parRef(book& r){r+=1;}
    void parPtr(book *p){*p+=1;}
    book retVal(book b){b+=1; return b;}
    book& retRef(book& r){r+=1;return r;}
    book* retPtr(book* p){*p+=1;return p;}
}

int main()
{
    using namespace KwonYeonseo2649004;
    book b{"title", 1, 1000}; std::cout << b;
    parVal(b); std::cout << b;
    book& r{b}; std::cout << r;
    parRef(r); std::cout << r;
    book* p{&b}; std::cout << *p;
    parPtr(p); std::cout << *p;
    std::cout << std::endl;

    b = book{"title", 2, 2000};
    std::cout << b;
    std::cout << retVal(b);
    std::cout << r;
    std::cout << retRef(r);
    std::cout << *p;
    std::cout << *retPtr(p);

    book* ptr{new book};
    ptr->setTitle("title3");
    ptr->setID(3);
    ptr->setPrice(3000);
    std::cout << *ptr;
    delete ptr;

    return 0;
}