#pragma once

#include "RoleStateMemento.h"
#include <iostream>
#include <string.h>
using std::string;
using std::cout;
using std::endl;


class GameRole
{
public:
    GameRole(int vitality,int attack,int defense) 
    :_vitality(vitality)
     ,_attack(attack)
     ,_defense(defense)
    {}


    void DisplayState() const
    {
        cout<<"生命值"<<_vitality<<endl;
        cout<<"攻击力"<<_attack<<endl;
        cout<<"防御力"<<_defense<<endl;
    }

    void SetState(int vit,int att,int def) 
    {
        _vitality = vit;
        _attack = att;
        _defense = def;
    }




    RoleStateMemento * SaveTheState()
    {
        return new RoleStateMemento(_vitality,_attack,_defense);
    }

    void LoadBackState(RoleStateMemento * ptr)
    {
        _vitality=ptr->getVit();
        _attack=ptr->getAtt();
        _defense=ptr->getDef();
    }


private:
    int _vitality;
    int _attack;
    int _defense;
};

