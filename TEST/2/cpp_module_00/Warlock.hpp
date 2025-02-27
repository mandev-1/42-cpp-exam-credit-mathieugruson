#pragma once

#include <string>

class Warlock
{

    private:
        std::string name;
        std::string title;
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
};