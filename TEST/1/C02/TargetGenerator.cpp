#include "TargetGenerator.hpp"

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & rhs)
{
    _target = rhs._target;
    return (*this);
}

TargetGenerator::TargetGenerator(TargetGenerator const & oth)
{
    *this = oth;
}

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}
void TargetGenerator::learnTargetType(ATarget * target)
{
    if (target)
        _target[target->getType()] = target->clone();
}
void TargetGenerator::forgetTargetType(std::string const & targetName)
{
    if (_target.end() != _target.find(targetName))
        _target.erase(_target.find(targetName));

}
ATarget* TargetGenerator::createTarget(std::string const & targetName)
{
    ATarget* tmp = NULL;
	if (_target.find(targetName) != _target.end())
    {
        _target[targetName] = tmp;
    }
    return tmp;
}
