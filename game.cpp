#include "game.h"

Attack::Attack(const string& name, int dmg, double hitChance, double critChance, double critMultiplier)
        : name(name), dmg(dmg), hitChance(hitChance), critChance(critChance), critMultiplier(critMultiplier) {}

int Attack::getDMG() const {
    return dmg;
}

istream& operator>>(istream& is, Attack& a) {
    cout << "Nume: ";
    is >> a.name;

    cout << "Dmg: ";
    is >> a.dmg;

    cout << "Hit Chance: ";
    is >> a.hitChance;

    cout << "Crit Chance: ";
    is >> a.critChance;

    cout << "Crit Multiplier: ";
    is >> a.critMultiplier;

    return is;
}

ostream& operator<<(ostream& out, const Attack& a) {
    out << "Nume:" << a.name << endl
        << "Dmg:" << a.dmg << endl
        << "HitChance:" << a.hitChance << endl
        << "CritChance:" << a.critChance << endl
        << "CritMultiplier:" << a.critMultiplier << endl;
    return out;
}

Character::Character(const string& name, int hp) : name(name), hp(hp) {}

const string& Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

void Character::addAttack(const Attack& newAttack) {
    attacks.push_back(newAttack);
}

void Character::performAttack(Character& target) const {
    if (attacks.empty()) {
        cout << getName() << " nu are niciun atac disponibil.\n";
        return;
    }

    // Afiseaza atacurile disponibile pentru jucator
    displayAttacks();

    int choice;
    cout << "Alegeti atacul: ";
    cin >> choice;

    // Valideaza alegerea si aplica atacul asupra target-ului
    if (choice >= 1 && choice <= static_cast<int>(attacks.size())) {
        const Attack& selectedAttack = attacks[choice - 1];

        // Aplica atacul asupra jucatorului target
        cout << getName() << " ataca cu " << selectedAttack << "!\n";
        // Implementeaza logica pentru scaderea HP-ului jucatorului target in functie de atributele atacului
        int damageDealt = selectedAttack.getDMG();
        target.hp -= damageDealt;
        cout << target.getName() << " a suferit " << damageDealt << " de daune!\n";
    } else {
        cout << "Alegere invalida. Va rugam alegeti un atac valid.\n";
        performAttack(target);  // Se reia procesul de alegere
    }
}

void Character::chooseAttacks() {
    cout << "Alegeti un atac:\n";
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << i + 1 << ". " << attacks[i] << "\n";
    }

    int choice;
    cout << "Alegeti atacul: ";
    cin >> choice;

    // Validează alegerea și adaugă atacul ales într-o listă de atacuri pentru a le utiliza în timpul jocului
    if (choice >= 1 && choice <= static_cast<int>(attacks.size())) {
        // Resetăm lista de atacuri ale jucătorului
        attacks.clear();
        attacks.push_back(attacks[choice - 1]);
    } else {
        cout << "Alegere invalida. Va rugam alegeti un atac valid.\n";
        chooseAttacks();  // Se reia procesul de alegere
    }
}

void Character::displayAttacks() const {
    cout << "Atacuri disponibile:\n";
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << i + 1 << ". " << attacks[i] << "\n";
    }
}

ostream& operator<<(ostream& out, const Character& c) {
    out << "Nume:" << c.name << endl
        << "HP:" << c.hp << endl;

    return out;
}

istream& operator>>(istream& is, Character& c) {
    string characterName;  // Folosim o variabilă intermediară pentru a citi numele
    cout << "Nume: ";
    is >> characterName;

    // Apelăm constructorul personalizat pentru a seta numele în clasa Character
    c = Character(characterName, 0);

    cout << "HP: ";
    is >> c.hp;

    return is;
}

Enemy::Enemy(const string& name, int hp, int level) : Character(name, hp), level(level) {}

ostream& operator<<(ostream& out, const Enemy& e) {
    out << static_cast<const Character&>(e) << "Level:" << e.level << endl;
    return out;
}

Boss::Boss(const string& name, int hp) : Character(name, hp) {}

int displayMenu() {
    int choice;
    cout << "\n===== Meniu =====\n";
    cout << "1. Play\n";
    cout << "2. Exit\n";
    cout << "==================\n";
    cout << "Alegeti optiunea: ";
    cin >> choice;
    return choice;
}