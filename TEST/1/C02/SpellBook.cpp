#include "SpellBook.hpp"

// * void learnSpell(ASpell*), that COPIES a spell in the book
// * void forgetSpell(string const &), that deletes a spell from the book, except
//   if it isn't there
// * ASpell* createSpell(string const &), that receives a string corresponding to
//   the name of a spell, creates it, and returns it.
// void learnSpell(ASpell *);
// void forgetSpell(std::string const &);
// ASpell* createSpell(std::string const &);

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}
SpellBook::SpellBook(SpellBook const & oth)
{
    *this = oth;
}
SpellBook & SpellBook::operator=(SpellBook const & oth)
{
    _spellBook = oth._spellBook;
    return (*this);
}

void SpellBook::learnSpell(ASpell * spell)
{
    if (spell)
    {
        _spellBook[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(std::string const & spellName)
{
    if (_spellBook.find(spellName) != _spellBook.end())
        _spellBook.erase(_spellBook.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
    ASpell* tmp = NULL;
    if (_spellBook.find(spellName) != _spellBook.end())
        tmp = _spellBook[spellName];
    return (tmp);
}

// // Create SpellBook.cpp:
// #include "SpellBook.hpp"

// SpellBook::SpellBook() {}
// SpellBook::~SpellBook()
// {
//     for (auto &pair : _SpellBook)
//         delete pair.second;
//     _SpellBook.clear();
// }

// void SpellBook::learnSpell(ASpell* spell)
// {
//     if (spell)
//         _SpellBook[spell->getName()] = spell->clone();
// }

// void SpellBook::forgetSpell(std::string const & SpellName)
// {
//     if (_SpellBook.find(SpellName) != _SpellBook.end())
//     {
//         delete _SpellBook[SpellName];
//         _SpellBook.erase(SpellName);
//     }
// }

// ASpell* SpellBook::createSpell(std::string const & SpellName)
// {
//     if (_SpellBook.find(SpellName) != _SpellBook.end())
//         return _SpellBook[SpellName];
//     return nullptr;
// }