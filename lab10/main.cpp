#include <iostream>
using namespace std;

class Boss {
private:
    int hp;
public:
    Boss() {
        hp = 500;
    }
    void attacked(int hp) {
        this->hp -= hp;
        if (this->hp <= 0) {
            cout << "You win!" << endl;
            exit(0);
        }
    }
    int getHp() {
        return hp;
    }
};

class People {
protected:
    int hp, shieldHp;
public:
    People() {
        hp = 100;
        shieldHp = -1;
    }
    void attacked() {
        if (shieldHp != -1) {
            shieldHp -= 40;
            if (shieldHp <= 0) {
                cout << "Shield break!" << endl;
                shieldHp = -1;
            }
        }
        else {
            this->hp -= 50;
            if (this->hp <= 0) {
                cout << "Game over!" << endl;
                exit(0);
            }
        }
    }
    int getHp() {
        return hp;
    }
    int getShieldHp() {
        return shieldHp;
    }
};

class Swordsman : virtual public People {
protected:
    int weapon;
public:
    Swordsman(int weapon) {
        this->weapon = weapon;
    }
    void attack(Boss& boss) {
        switch (weapon) {
            case 0:
                boss.attacked(10);
                break;
            case 1:
                boss.attacked(20);
                break;
            case 2:
                boss.attacked(100);
                break;
            default:
                cout << "error!" << endl;
                exit(1);
        }
    }
};

class Wizard : virtual public People {
protected:
    float multiple;
public:
    Wizard(int wand) {
        switch (wand) {
            case 0:
                multiple = 1.0;
                break;
            case 1:
                multiple = 1.5;
                break;
            case 2:
                multiple = 2.0;
                break;
            default:
                cout << "error!" << endl;
                exit(1);
        }
    }
    void spellMagic(Boss& boss, int skill) {
        switch (skill) {
            case 0:
                shieldHp = 100;
                break;
            case 1:
                boss.attacked(static_cast<int>(multiple * 50));
                break;
            case 2:
                boss.attacked(static_cast<int>(multiple * 50));
                break;
            case 3:
                boss.attacked(static_cast<int>(multiple * 50));
                break;
            case 13112:
                boss.attacked(static_cast<int>(multiple * 100));
                break;
            default:
                cout << "error!" << endl;
                exit(1);
        }
    }
};

class Magicka : public Swordsman, public Wizard {
public:
    Magicka(int weapon, int wand) : Swordsman(weapon), Wizard(wand) { }
};

int main() {
    int weapon, wand, round = 0;
    cout << "Please choose weapon for hero. [0]sword, [1]M60, [2]excalibur" << endl;
    cin >> weapon;
    cout << "Please choose wand for hero. [0]wood, [1]silver, [2]gold" << endl;
    cin >> wand;
    Magicka magicka(weapon, wand);
    Boss boss;
    cout << endl;
    while (1) {
        int command;
        if (getchar() == 'q')
            return 0;
        cout << "Round " << ++round << endl;
        cout << "  Boss HP <" << boss.getHp() << "/500> ";
        for (int i = 0; i < boss.getHp(); i += 10)
            cout << "| ";
        cout << endl << "  Hero HP <" << magicka.getHp() << "/100> ";
        for (int i = 0; i < magicka.getHp(); i += 10)
            cout << "| ";
        if (magicka.getShieldHp() != -1) {
            cout << endl << "Shield HP <" << magicka.getShieldHp() << "/100> ";
            for (int i = 0; i < magicka.getShieldHp(); i += 10)
                cout << "| ";
        }
        cout << endl << "Boss attack!" << endl;
        cout << "Select attack or magic for hero. [0]attack, [1]magic" << endl;
        cin >> command;
        int tmpBossHp = boss.getHp(), tmpMagickaHp = magicka.getHp();
        if (command == 0)
            magicka.attack(boss);
        else {
            cout << "Select skill for hero." << endl;
            cin >> command;
            magicka.spellMagic(boss, command);
        }
        if (magicka.getShieldHp() != -1) {
            cout << "Hero got 40 damage." << endl;
            magicka.attacked();
        }
        else {
            magicka.attacked();
            cout << "Hero got " << tmpMagickaHp - magicka.getHp() << " damage." << endl;
        }
        cout << "Boss got " << tmpBossHp - boss.getHp() << " damage." << endl << endl;
    }
}
