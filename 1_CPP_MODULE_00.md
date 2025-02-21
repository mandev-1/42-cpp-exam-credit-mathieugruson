## CPP 00

### Warlock Class Setup

We need to make a Warlock class. The Warlock class needs to closely follow the Coplien Form (effectively the same thing as the Orthodox Canonical Form as you may know it), which includes:

- **Constructor**: Takes Name and Title (in this order)
- **Destructor**: Cleans up resources
- **Copy Constructor**: Creates a copy of an existing object
- **Copy Assignment Operator**: Assigns contents between objects

The Warlock class is required to have these things:
- Private attributes (name and title as strings)
- Getters and setters
- An introduce() function

### Header File

[Warlock header file](cpp_module_00/Warlock.hpp)


```cpp
#pragma once
#include <iostream>

class Warlock
{
    private:
        Warlock & operator=(Warlock const & rhs); // Private - prevent unwanted copying
        Warlock(Warlock const & obj);             // Private - enforce controlled creation.
        Warlock();                                // Private - restrict instantiation without parameters.
        std::string _name;                        // Basic private assigned attribute _NAME
        std::string _title;                       // _TITLE attribute 
    public:
        Warlock(const std::string& name, const std::string& title); // Public constructor - Name and Title
        ~Warlock();                                                 // 
        std::string const & getName() const;                        // Returns the private name.
        std::string const & getTitle() const;                       // Returns the private title.
        void setTitle(std::string const & str);                     // Sets a new title for the warlock.
        void introduce() const;                                     // Prints or logs an introduction message.
};
```

### Implementation Details

> The Warlock is also required to say some things. So it will say stuff on creation, on deletion and when the required introduce() method is called. He has specific messages for different actions:
- **Creation**: `<NAME>: This looks like another boring day.`
- **Deletion**: `<NAME>: My job here is done!`
- **Introduce**: `<NAME>: I am <NAME>, <TITLE>!`

> We also know which main we should have, as that is in the subject assignment.
> So with this, here's the implementation of the cpp file:


```cpp
#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
    this->_name = rhs._name;
    this->_title = rhs._title;
    return *this;
}

Warlock::Warlock(Warlock const & obj)
{
    *this = obj;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const
{
    return (_name);
}

std::string const & Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(std::string const & str)
{
    _title = str;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}
```
[Warlock code](cpp_module_00/Warlock.cpp)
[Main.cpp](cpp_module_00/main.cpp)


[Go to CPP Module 01](2_CPP_MODULE_01.md)
