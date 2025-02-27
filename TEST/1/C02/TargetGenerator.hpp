// Make a TargetGenerator class, in canonical form, and as before,
// non-copyable.

// It will have the following functions:

// * void learnTargetType(ATarget*), teaches a target to the generator

// * void forgetTargetType(string const &), that makes the generator forget a
//   target type if it's known

// * ATarget* createTarget(string const &), that creates a target of the
//   specified type

// Phew, that's done. Now here's a test main. It's not very thorough, so make sure 
// to use your own aswell.

#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    private:
        TargetGenerator & operator=(TargetGenerator const & rhs);
        TargetGenerator(TargetGenerator const & oth);
        std::map < std::string, ATarget*> _target;
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget * target);
        void forgetTargetType(std::string const & targetName);
        ATarget *createTarget(std::string const & targetName);
};