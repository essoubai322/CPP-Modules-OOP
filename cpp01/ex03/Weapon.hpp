#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <cstring>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(std::string type) : type(type) {}
        ~Weapon() {}
        const std::string &getType() const { return type; }
        void setType(std::string newType) { type = newType; }
};

#endif