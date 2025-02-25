// Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
// by copy. It will have the following functions:

// * void learnSpell(ASpell*), that COPIES a spell in the book
// * void forgetSpell(string const &), that deletes a spell from the book, except
//   if it isn't there
// * ASpell* createSpell(string const &), that receives a string corresponding to
//   the name of a spell, creates it, and returns it.
#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
    private:
        SpellBook & operator=(SpellBook const & oth);
        SpellBook(SpellBook const & oth);
        std::map<std::string, ASpell*> _spellBook;
    public:
        ~SpellBook();
        SpellBook();
        void learnSpell(ASpell *);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};


// * void learnSpell(ASpell*), that COPIES a spell in the book
// * void forgetSpell(string const &), that deletes a spell from the book, except
//   if it isn't there
// * ASpell* createSpell(string const &), that receives a string corresponding to
//   the name of a spell, creates it, and returns it.
        // void learnSpell(ASpell *);
        // void forgetSpell(std::string const &);
        // ASpell* createSpell(std::string const &);