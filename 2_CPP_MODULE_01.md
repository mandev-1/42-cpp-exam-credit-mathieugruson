## CPP 01

### Warlock Class Setup

> Great job on the first one!

<img src="https://imgs.search.brave.com/_urWI0f3IjDIiqAC41aUbqk5g_JmhZzC0wMdVAPvJdY/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly90My5m/dGNkbi5uZXQvanBn/LzA2LzcwLzY1LzQw/LzM2MF9GXzY3MDY1/NDAxOV9VY0xXMXZJ/QmZsSjVGYTlGaWFr/Q2NuS2RLUlh0VjNp/Qi5qcGc" alt="Mage casting a spell" height="240"/>



_In this one, we will enhance the code from first excercise. We will add **Target** and **Cast spells**.
1. We will add a SpellBook map to the Warlock's Privates : `std::map < std::string, ASpell * > _SpellBook;`
2. The Warlock will get new functions:
	1. `void learnSpell(ASpell* spell)`
	2. `void forgetSpell(std::string SpellName)`
	3. `void launchSpell(std::string SpellName, ATarget const & target)`
	4. [Go to New Warlock Spells](#new-warlock-spells)
  
[Subject](cpp_module_01/subject.txt)


> We will add **Spell (Fwoosh)**, **Target (Dummy)**, and _improve Warlock _so that he can **_Cast Spells _** (Launch da spell at the target).

1. The plan is Implementing `ASpell.hpp`
2. Then Implementing `ATarget.hpp`
3. Once done, we implement the `Fwoosh` and `Dummy`
4. Last, we arejust the `Warlock.hpp` & `Warlock.cpp`
5. We test using the provided `main.cpp` (and compile with `g++`)

```cpp
//First, we implement:
#include "ASpell.hpp"
#include "Fwoosh.hpp"

//Second, we implement:
#include "ATarget.hpp"
#include "Dummy.hpp"
```


- His new functions will be `learnSpell()`, `forgetSpell()`, and `launchSpell()`.

##### ASpell

```cpp
#pragma once
#include <iostream>
#include "ATarget.hpp"

//We reference ATarget as we need to use it for launch (the cast)
class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;
    public:
    // Standard Coplien: 
    // 1.Constructor
    // 2.Copy operator and Copy Constructor
    // 3.Destructor (Virtual so children can use)
        ASpell(std::string name, std::string effects);
        ASpell & operator=(ASpell const & rhs);
        ASpell(ASpell const & obj);
        virtual ~ASpell();
    // 4. Getters for the protected attributes (member functions)    // 5 
        std::string getName() const;
        std::string getEffects() const;
    // 5. Assignment wants us to add a pure method 'Clone'
    // Pure method means a pure virtual function
    // It forces derived classes to implement the method
    // Pure method is always virtual and is marked with = 0; The right sidd indicates the return is constant and has to be implemented in derived classes
        virtual ASpell* clone() const = 0;
    // 6. Also, the launch function is requested in subject. 
    // The launch is called from the spell, thus we need to add the target to the prototype.
        void launch(ATarget const & target) const;
};
```

###### ATarget

```cpp
// # ATARGET.hpp

// ATarget is very similar to ASpell
// We can copy paste here
#pragma once
#include <iostream>
#include "ASpell.hpp"

// Change this to mention ASpell
class ASpell;

class ATarget 
{
	protected :
		// Change this to only have attribute type
		std::string _type;
	
	public :
		// Constructor only takes type -- adjust this
		ATarget(std::string type);
		ATarget & operator=(ATarget const & rhs);
		ATarget(ATarget const & obj);
		virtual ~ATarget();
		// Only one getter -- for the type
		std::string getType() const;

// Same cloning
		virtual ATarget* clone() const = 0;
// Instead of a launch, Target gets hit by a spell
		void	getHitBySpell(ASpell const & spell) const;
};
```
1. With ASpell, we again need to simply implement the constructor
2. =operator for coppies
3. Again the copy creation (ASpell::ASpell(ASpell const & obj)
4. Simple destructor
5. Getters for Name and Effects
6. and Launch void ASpell::launch(ATarget const & target) const
	- here the content will be "target.getHitBySpell(*this);"

```cpp
// # This is ASpell.cpp
#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell & ASpell::operator=(ASpell const & rhs)
{
	_name = rhs.getName();
	_effects = rhs.getEffects();
	return *this;
}

ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
	return (_name);
}

std::string ASpell::getEffects() const
{
	return (_effects);
}

void ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}
```

- We need to make sure he can cast spells, and he has someone to shoot them at. This requires an abstract ASpell class, and abstract ATarget class which will then inherit into Fwoosh class (spell is a Fwoosh) and Dummy (target) class for the target.

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
```cpp
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") 
{

}

Fwoosh::~Fwoosh() 
{

}

ASpell* Fwoosh::clone() const
{
	return (new Fwoosh());
}
```


> Cool. Now lets fill in the cpp files:
> That should be straight forward. Check the Files from the source if needed.

> The Target Is set to have getType() and getHitBySpell() functions. Aside of the Coplien requirements. Its only attribute is the protected _type
> The Dummy is then supposed to be called "Target Practice Dummy"

###### ATarget cpp

1. Copy Paste ASpell
2. Change ATarget to ASpells
3. Add the text output to "getHitBySpell"

   
```cpp
#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{

}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	_type = rhs.getType();
	return *this;
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return (_type);
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
```
```cpp
// # DUMMY.hpp
#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public :
		Dummy();
		~Dummy();
		ATarget* clone() const;
};
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
> We need to somehow store the spells, so we will:
> 1. Import <map>
> 2. Declare private "std::map < std::string, ASpell * > _SpellBook;"
> 3. Add the three functions
>    
> We will also adjust the destructor, which is needed for the SpellBook deletions
> We adjust the Warlock:
```cpp
// NEW HEADER:
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
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
1. Moreover, the Warlock.cpp needs to go through the spellbook and clear it
2. And we add the LearnSpell
3. We add ForgetSpell
4. We add LaunchSpell
5. Afterwards we can add new main and test with g++

```cpp
// ADJUSTMENTS TO WARLOCK.CPP
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
###### New Warlock Spells
- These will leverage builtin map commands _.find, .end, .erase_

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


[Subject](cpp_module_01/subject.txt)
[Main](cpp_module_01/main.cpp)


[Go to CPP Module 02](3_CPP_MODULE_02.md)
