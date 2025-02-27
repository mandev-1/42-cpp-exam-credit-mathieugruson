#include "Warlock.hpp"

#include <iostream>

Warlock::Warlock()
{

}
Warlock::Warlock(Warlock const & oth)
{

}

Warlock Warlock::operator=(Warlock const & rhs)
{
    this->name = rhs.name;
    this->title = rhs.title;
    return (*this);
}

Warlock::~Warlock()
{
    std::cout << "byebye" << std::endl;
}

Warlock::Warlock(std::string const & name, std::string const & title): name(name), title(title)
{
    std::cout << "Hello" << std::endl;
}

std::string const & Warlock::getName() const
{
    return (name);
}

std::string const & Warlock::getTitle() const
{
    return (title);
}

void Warlock::introduce() const
{
    std::cout << "I am " << name << std::endl;
}

void Warlock::setTitle(std::string const & str)
{
    title = str;
}