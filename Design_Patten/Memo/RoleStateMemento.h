#pragma once

class RoleStateMemento
{
public:
    RoleStateMemento(int vitality,int attack,int defense) 
    :_vitality(vitality)
     ,_attack(attack)
     ,_defense(defense)
    {}

    int getVit()
    {
        return _vitality;
    }

    int getAtt()
    {
        return _attack;
    }

    int getDef()
    {
        return _defense; 
    }

private:
    int _vitality;
    int _attack;
    int _defense;
};

