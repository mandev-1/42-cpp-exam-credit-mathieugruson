## CPP 01

### Warlock Class Setup

> Great job on the first one! The Warlock is basically already setup.
>
> In this one, he will start casting spells.
> We will add **Spells**, **Target**, and _improve Warlock _so that he can **_Cast_**.

![Mage casting a spell](https://imgs.search.brave.com/zO6UsiV5tNSGDxZR5PXtY_0bmjPdKzWVfCh1szr7iDw/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9pLmt5/bS1jZG4uY29tL3Bo/b3Rvcy9pbWFnZXMv/bmV3c2ZlZWQvMDAy/LzMwMC80ODkvOGQ3/LnBuZw)

- His new functions will be learnSpell(), forgetSpell(), and launchSpell().
- e need to make sure he can cast spells, and he has someone to shoot them at. This requires an abstract ASpell class, and abstract ATarget class which will then inherit into Fwoosh class (spell is a Fwoosh) and Dummy (target) class for the target.

> SO, the PLAN is:

1. Create [ASpell](cpp_module_01/ASpell.cpp) class (hpp first)(cpp second)(Abstract Spell class)
2. Create [ATarget](cpp_module_01/ATarget.cpp) class (Abstract Target class)
3. Create [Fwoosh](cpp_module_01/Fwoosh.cpp) class (which is inheriting ASpell)(Actual spell he cant cast)
4. Create a [Dummy](cpp_module_01/Dummy.cpp) class (Actual Target, which can be hit)

> So, as said... in this second exercise, we add his Spellcasting abilities.
> This will require the Abstract **Target**, Abstract **Spell**, and actual Spell he cant cast (Fwoosh) and a target (a Dummy).

The Spell is very easy to create. It has a string of its name, and effects. The Fwoosh will be called that, and will say that the target has been "fwooshed". 

The Dummy is also quite hollow, as we need to declare this as the target in the spell only. 

> So the Spell abstract class. Lets start coding this, add the name, effect verb, the coplien requirements, getters for name, effect and also the Launch() function
> The launch function needs to target the dummy (or other target), so we include the ATarget in the ASpell header.
> Lets start writing ASpell:

##### ASpell

```cpp
#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell 
{
	protected :
		std::string _name;
		std::string _effects;
	
	public :
		ASpell(std::string name, std::string effects);
		ASpell & operator=(ASpell const & rhs);
		ASpell(ASpell const & obj);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target) const;
};
```

###### Fwoosh

```cpp
#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public :
        Fwoosh();
        ~Fwoosh();
        ASpell* clone() const;
};
```

> Cool. Now lets fill in the cpp files:
> That should be straight forward. Check the Files from the source if needed.

> The Target Is set to have getType() and getHitBySpell() functions. Aside of the Coplien requirements. Its only attribute is the protected _type
> The Dummy is then supposed to be called "Target Practice Dummy"

###### ATarget + Dummy:

```cpp

// # ATARGET.hpp

#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
	protected :
		std::string _type;
	
	public :
		ATarget(std::string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		std::string getType() const;
		virtual ATarget* clone() const = 0;
		void	getHitBySpell(ASpell const & spell) const;
};

// # The getHitBySpell from ATARGET.cpp


void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
```


```cpp
// # DUMMY.CPP: 
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{}

ATarget* Dummy::clone() const
{
	return (new Dummy());
}
```

### Final adjustments of the Warlock files:

> The Warlock must be able to learnSpell(), launchSpell() and forgetSpell()
> We will also adjust the destructor, which is needed for the SpellBook deletions
> We adjust the Warlock:
```cpp
// His Header will now look like this:
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock {

	private :
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();
		std::string _name;
		std::string _title;
		std::map < std::string, ASpell * > _SpellBook; //This is new

	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & str);
		void	introduce() const;
		void learnSpell(ASpell* spell);  //This is new
		void forgetSpell(std::string SpellName);  // Also new
		void launchSpell(std::string SpellName, ATarget const & target);  //This is new too
};
```


```cpp
// From:
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

// To:
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
}
```

> And we add these functions:

```cpp
void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end()) {
		delete _SpellBook[SpellName];	
		_SpellBook.erase(_SpellBook.find(SpellName));
	}
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName]->launch(target);
}
```
#### Main (NEW)

> Our new main is also supplied in the subject:

```cpp
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
```

Voila!

[Go to CPP Module 02](3_CPP_MODULE_02.md)
