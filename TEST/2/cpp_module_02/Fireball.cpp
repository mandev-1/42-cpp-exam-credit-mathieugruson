#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crips")
{

}

Fireball::~Fireball()
{

}

ASpell * Fireball::clone() const
{
    return (new(Fireball));
}