## CPP 00

[Subject](cpp_module_00/Subject.txt)
### Warlock Class Setup

We need to make a Warlock class. The Warlock class needs to closely follow the Coplien Form (effectively the same thing as the Orthodox Canonical Form as you may know it), which includes:

- **Constructor**: Takes Name and Title (in this order)
- **Destructor**: Cleans up resources
- **Copy Constructor**: Creates a copy of an existing object
- **Copy Assignment Operator**: Assigns contents between objects

We expect the Warlock to have:
- private <ins>name</ins> and <ins>title</ins>
- only specific creation format
- the introduce function and the derived getters (2x) and a setter(1x)

Therefore, we will do this in the code:
1. Disallow Copying
2. Force creation exclusively WITH name and title in the function (By making other constructors private)
3. Add the setter for the Title (per assignment)
4. Add the Getters for Name and Title, as Name is private and Title too

### Header File

[Warlock header file](cpp_module_00/Warlock.hpp)


```cpp
#pragma once
#include <iostream>

class Warlock
{
    private:
//In Private, I set name, title
//I disallow empty constructor by adding it to Private
//Disallow Copying (using =) and via creation copying(Using Warlock(Warlock))
        Warlock & operator=(Warlock const & rhs); // Private - prevent unwanted copying This follows left-to-right reading: "Warlock that is const and is a reference"
        Warlock(Warlock const & obj);             // Private - enforce controlled creation.
        Warlock();                                // Private - restrict instantiation without parameters.
        std::string _name;                        // Basic private assigned attribute _NAME
        std::string _title;                       // _TITLE attribute 
    public:
        //force how we Create the Warlock
        //Implement function **introduce()**;
        //Add 2x getters for the member variables and 1x setter for the member var. 'title'
        //Add destructor
        Warlock(const std::string& name, const std::string& title); // Public constructor - Name and Title
        ~Warlock();
        //Getter returns string.
        //On the left side, we say Return Type. So return type is a string constant reference.
        //On the right side, we add qualifier. The const qualifier is a promise that we will not modify. So this makes it safe to use for Member Variables. This is called the "member function qualifier" 
        std::string const & getName() const;                        // Returns the private name.
        std::string const & getTitle() const;                       // Returns the private title.
        //Setter is Void
        void setTitle(std::string const & str);                     // Sets a new title for the warlock.
        //Void funciton for Printing Introduction
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
