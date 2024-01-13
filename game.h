#ifndef OOP_PROOJECT_GAME_H
#define OOP_PROOJECT_GAME_H

#endif //OOP_PROOJECT_GAME_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Attack {
private:
    string name;
    int dmg;
    double hitChance;
    double critChance;
    double critMultiplier;

public:
    Attack(const string &name, int dmg, double hitChance, double critChance, double critMultiplier);

    friend istream &operator>>(istream &is, Attack &a);

    friend ostream &operator<<(ostream &out, const Attack &a);

    int getDMG() const;
};

class Character {
private:
    string name;
    int hp;
    vector<Attack> attacks;

public:
    Character(const string& name, int hp);
    const string& getName() const;
    int getHP() const;
    void addAttack(const Attack& newAttack);
    void performAttack(Character& target) const;
    void chooseAttacks();
    void displayAttacks() const;

    friend ostream& operator<<(ostream& out, const Character& c);
    friend istream& operator>>(istream& is, Character& c);
};

class Enemy : public Character {
private:
    int level;

public:
    Enemy(const string& name, int hp, int level);
    friend ostream& operator<<(ostream& out, const Enemy& e);
};

class Boss : public Character {
public:
    Boss(const string& name, int hp);
    virtual void Boss_skill1() const = 0;
    virtual void Boss_skill2() const = 0;
};

int displayMenu();
