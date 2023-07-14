#include<iostream>

class Creature  {
private:

protected:
	int HP;
	int DMG;
public:
	Creature():HP(100),DMG(10){}
	Creature(int HP, int DMG) {
		this->HP = HP;
		this->DMG = DMG;
	}
	void virtual say() = 0;
	void attack(Creature* target) {
		if (target->HP > this->DMG)
			target->HP -= this->DMG;
		else
			target->HP = 0;
	 }
	int getHP() {
		return HP;
	}
};

class Player : public Creature {
private:
	int LVL;
public:
	Player() : Creature(),LVL(1){}
	Player(int HP, int DMG, int LVL = 1):Creature( HP, DMG) {
		this->LVL = LVL;
	}
	void say() override {
		std::cout << "Plaer says \"Hi!\"\n";
	}
};

class Enemy : public Creature {
public:
	Enemy() : Creature() {}
	Enemy(int HP, int DMG) :Creature(HP, DMG) {}
	void say() override {
		std::cout << "Enemy says \"Bye!\"\n";
	}
};



	int main() {

		Player p(200,50);
		Enemy e1;



		p.say();
		e1.say();
		std::cout << "Enemy HP" << e1.getHP() << '\n';
		p.attack(&e1);
		std::cout << "Player attacks the enemy!\n";
		std::cout << "Enemy HP" << e1.getHP() << '\n';
		std::cout << "--------------------------------\n";
		std::cout << "Player HP" << p.getHP() << '\n';
		e1.attack(&p);
		std::cout << "Enemy attacks the player!\n";
		std::cout << "Player HP" << p.getHP() << '\n';

	return {};
}