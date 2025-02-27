#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & obj)
{
    *this = obj;
}

SpellBook & SpellBook::operator=(SpellBook const & rhs)
{
    _spellBook = rhs._spellBook;
    return (*this);
}

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell * spell)
{
    if (spell)
        if (_spellBook.find(spell->getName()) == _spellBook.end())
            _spellBook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const & spellName)
{
    if (_spellBook.find(spellName) != _spellBook.end())
    {
        delete _spellBook[spellName];
        _spellBook.erase(_spellBook.find(spellName));
    }
}

ASpell * SpellBook::createSpell(std::string const & spellName)
{
    ASpell *tmp = NULL;
    if (_spellBook.find(spellName) != _spellBook.end())
        tmp = _spellBook[spellName];
    return tmp;
}
