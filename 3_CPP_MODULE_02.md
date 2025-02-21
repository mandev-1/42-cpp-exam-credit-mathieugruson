# Recipe for Exercise 3

## Step 1: Create New Spells

1. **Fireball**
   - Create `Fireball.hpp`:
     ```cpp
     #pragma once
     #include "ASpell.hpp"

     class Fireball : public ASpell
     {
         public:
             Fireball();
             ~Fireball();
             ASpell* clone() const;
     };
     ```
   - Create `Fireball.cpp`:
     ```cpp
     #include "Fireball.hpp"

     Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
     Fireball::~Fireball() {}
     ASpell* Fireball::clone() const { return new Fireball(); }
     ```

2. **Polymorph**
   - Create `Polymorph.hpp`:
     ```cpp
     #pragma once
     #include "ASpell.hpp"

     class Polymorph : public ASpell
     {
         public:
             Polymorph();
             ~Polymorph();
             ASpell* clone() const;
     };
     ```
   - Create `Polymorph.cpp`:
     ```cpp
     #include "Polymorph.hpp"

     Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}
     Polymorph::~Polymorph() {}
     ASpell* Polymorph::clone() const { return new Polymorph(); }
     ```

## Step 2: Create New Target

1. **BrickWall**
   - Create `BrickWall.hpp`:
     ```cpp
     #pragma once
     #include "ATarget.hpp"

     class BrickWall : public ATarget
     {
         public:
             BrickWall();
             ~BrickWall();
             ATarget* clone() const;
     };
     ```
   - Create `BrickWall.cpp`:
     ```cpp
     #include "BrickWall.hpp"

     BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
     BrickWall::~BrickWall() {}
     ATarget* BrickWall::clone() const { return new BrickWall(); }
     ```

## Step 3: Create SpellBook Class

1. **SpellBook**
   - Create `SpellBook.hpp`:
     ```cpp
     #pragma once
     #include "ASpell.hpp"
     #include <map>

     class SpellBook
     {
         private:
             SpellBook(SpellBook const & src);
             SpellBook & operator=(SpellBook const & src);
             std::map<std::string, ASpell*> _SpellBook;

         public:
             SpellBook();
             ~SpellBook();
             void learnSpell(ASpell*);
             void forgetSpell(std::string const &);
             ASpell* createSpell(std::string const &);
     };
     ```
   - Create `SpellBook.cpp`:
     ```cpp
     #include "SpellBook.hpp"

     SpellBook::SpellBook() {}
     SpellBook::~SpellBook()
     {
         for (auto &pair : _SpellBook)
             delete pair.second;
         _SpellBook.clear();
     }

     void SpellBook::learnSpell(ASpell* spell)
     {
         if (spell)
             _SpellBook[spell->getName()] = spell->clone();
     }

     void SpellBook::forgetSpell(std::string const & SpellName)
     {
         if (_SpellBook.find(SpellName) != _SpellBook.end())
         {
             delete _SpellBook[SpellName];
             _SpellBook.erase(SpellName);
         }
     }

     ASpell* SpellBook::createSpell(std::string const & SpellName)
     {
         if (_SpellBook.find(SpellName) != _SpellBook.end())
             return _SpellBook[SpellName];
         return nullptr;
     }
     ```

## Step 4: Modify Warlock Class

1. **Warlock.hpp**
   - Add `SpellBook` member and update methods:
     ```cpp
     #include <iostream>
     #include <map>
     #include "ASpell.hpp"
     #include "ATarget.hpp"
     #include "SpellBook.hpp"

     class Warlock
     {
         private:
             std::string _name;
             std::string _title;
             SpellBook _SpellBook;
             Warlock & operator=(Warlock const & rhs);
             Warlock(Warlock const & obj);
             Warlock();

         public:
             Warlock(std::string const &name, std::string const &title);
             ~Warlock();
             std::string const & getName() const;
             std::string const & getTitle() const;
             void setTitle(std::string const & str);
             void introduce() const;
             void learnSpell(ASpell* spell);
             void forgetSpell(std::string SpellName);
             void launchSpell(std::string SpellName, ATarget const & target);
     };
     ```

2. **Warlock.cpp**
   - Update methods to use `SpellBook`:
     ```cpp
     #include "Warlock.hpp"

     Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
     {
         std::cout << _name << ": This looks like another boring day." << std::endl;
     }

     Warlock::~Warlock()
     {
         std::cout << _name << ": My job here is done!" << std::endl;
     }

     std::string const & Warlock::getName() const { return _name; }
     std::string const & Warlock::getTitle() const { return _title; }
     void Warlock::setTitle(std::string const & str) { _title = str; }
     void Warlock::introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; }

     void Warlock::learnSpell(ASpell* spell) { _SpellBook.learnSpell(spell); }
     void Warlock::forgetSpell(std::string SpellName) { _SpellBook.forgetSpell(SpellName); }
     void Warlock::launchSpell(std::string SpellName, ATarget const & target)
     {
         ASpell* spell = _SpellBook.createSpell(SpellName);
         if (spell)
             spell->launch(target);
     }
     ```

## Step 5: Create TargetGenerator Class

1. **TargetGenerator**
   - Create `TargetGenerator.hpp`:
     ```cpp
     #pragma once
     #include "ATarget.hpp"
     #include <map>

     class TargetGenerator
     {
         private:
             TargetGenerator(TargetGenerator const & src);
             TargetGenerator & operator=(TargetGenerator const & src);
             std::map<std::string, ATarget*> _target;

         public:
             TargetGenerator();
             ~TargetGenerator();
             void learnTargetType(ATarget*);
             void forgetTargetType(std::string const &);
             ATarget* createTarget(std::string const &);
     };
     ```
   - Create `TargetGenerator.cpp`:
     ```cpp
     #include "TargetGenerator.hpp"

     TargetGenerator::TargetGenerator() {}
     TargetGenerator::~TargetGenerator()
     {
         for (auto &pair : _target)
             delete pair.second;
         _target.clear();
     }

     void TargetGenerator::learnTargetType(ATarget* target)
     {
         if (target)
             _target[target->getType()] = target->clone();
     }

     void TargetGenerator::forgetTargetType(std::string const & target)
     {
         if (_target.find(target) != _target.end())
         {
             delete _target[target];
             _target.erase(target);
         }
     }

     ATarget* TargetGenerator::createTarget(std::string const & target)
     {
         if (_target.find(target) != _target.end())
             return _target[target];
         return nullptr;
     }
     ```

## Step 6: Test the Implementation

- Use the provided `main` function to test the implementation:
  ```cpp
  int main()
  {
      Warlock richard("Richard", "foo");
      richard.setTitle("Hello, I'm Richard the Warlock!");
      BrickWall model1;

      Polymorph* polymorph = new Polymorph();
      TargetGenerator tarGen;

      tarGen.learnTargetType(&model1);
      richard.learnSpell(polymorph);

      Fireball* fireball = new Fireball();

      richard.learnSpell(fireball);

      ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

      richard.introduce();
      richard.launchSpell("Polymorph", *wall);
      richard.launchSpell("Fireball", *wall);
  }