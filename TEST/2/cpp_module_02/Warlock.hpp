#pragma once

#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{

    private:
        std::string name;
        std::string title;
        SpellBook _spellBook;
        Warlock();
        Warlock(Warlock const & oth);
        Warlock operator=(Warlock const & rhs);

    public:

        ~Warlock();
        Warlock(std::string const & name, std::string const & title);
        std::string const & getName() const;
        std::string const & getTitle() const;
        void introduce() const;
        void setTitle(std::string const & str);
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, ATarget const & target);
};
