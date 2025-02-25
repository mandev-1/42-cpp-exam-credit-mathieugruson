#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
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

//edit this
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

void	Warlock::setTitle(std::string const & str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

// 		void learnSpell(ASpell * spell);
// 		void forgetSpell(std::string spellName);
// 		void launchSpell(std::string spellName, ATarget const & target);


// * learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
// * forgetSpell, takes a string corresponding a to a spell's name, and makes the
//   Warlock forget it. If it's not a known spell, does nothing.
// * launchSpell, takes a string (a spell name) and a reference to ATarget, that
//   launches the spell on the selected target. If it's not a known spell, does
//   nothing.


/**
 * @brief Learns a new spell by adding it to the Warlock's spellbook
 * 
 * @param spell Pointer to the spell to be learned
 * 
 * @details The function checks if the spell exists and if it's not already in the spellbook.
 *          If both conditions are met, creates a clone of the spell and stores it in the spellbook
 *          using the spell's name as key.
 * 
 * @note Function does nothing if spell is nullptr or if spell is already known
 */

void Warlock::learnSpell(ASpell * spell)
{
	_spellBook.createSpell(spell->getName());
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