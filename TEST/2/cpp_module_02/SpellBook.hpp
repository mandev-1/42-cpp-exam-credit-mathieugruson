#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
    private:
        SpellBook(SpellBook const & obj);
        SpellBook & operator=(SpellBook const & rhs);
        std::map<std::string, ASpell*> _spellBook;
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell * spell);
        void forgetSpell(std::string const & spellName);
        ASpell *createSpell(std::string const & spellName);
};
