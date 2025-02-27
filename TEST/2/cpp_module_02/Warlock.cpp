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
	std::cout << name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
    {
        delete it->second;
    }
    _spellBook.clear();
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

void Warlock::learnSpell(ASpell* spell)
{
    _spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
    _spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const & target)
{
    if (_spellBook.createSpell(spellName))
        _spellBook.createSpell(spellName)->launch(target);
}