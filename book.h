#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
namespace KwonYeonseo2649004
{
    class book
    {
        std::string title;
        int id;
        int price;
        void testID()
        {
            if(id < 1 || id > 1000)
            {
                std::cout << "Invalid book id\n";
                std::exit(1);
            }
        }
        void testPrice()
        {
            if(price < 0 || price > 5000)
            {
                std::cout << "Invalid book price\n";
                std::exit(1);
            }
        }
    public:
        book(const std::string& t = "no title yet", int d =1, int p = 0)
        :title{t}, id{d}, price{p}
        {
            testID(); testPrice();
        }
        void input()
        {
            std::cout << "Enter book title: ";
            std::getline(std::cin >> std::ws, title);
            std::cout << "Enter book id: ";
            std::cin >> id; testID();
            std::cout << "Enter book price: ";
            std::cin >> price; testPrice();
        }
        friend std::istream& operator>>(std::istream& is, book&b)
        {
            std::cout << "Enter book title: ";
            std::getline(is >> std::ws, b.title);
            std::cout << "Enter book id: ";
            is >> b.id; b.testID();
            std::cout << "Enter book price: ";
            is >> b.price; b.testPrice();
            return is;
        }
        void setID(int d){id = d; testID();}
        void setPrice(int p){price = p; testPrice();}
        void setTitle(const std::string& t){title = t;}
        void print() const
        {
            std::cout << title << "(" << id << "): " << price << "won\n";
        }
        friend std::ostream& operator <<(std::ostream& os, const book& b)
        {
            os << b.title << ", " << b.id << ", " << b.price << "won\n";
            return os;
        }
        const std::string& getTitle() const {return title;}
        int getID() const {return id;}
        int getPrice() const {return price;}
        book& operator++()
        {
            ++price;
            return *this; //book{title, id, ++price};
        }
        book operator++(int)
        {
            book temp{*this};//{title, id, price};
            ++(*this);//price++;
            return temp;
        }
        friend bool operator==(const book& b1, const book& b2)
        {
            return b1.id == b2.id && b1.price ==b2.price;
        }
        friend int operator+(const book& b1, const book& b2)
        {
            return b1.price + b2.price;
        }
        book& operator+=(int p)
        {
            price += p; //this->price; (*this).price
            return *this;
        }
    };
}