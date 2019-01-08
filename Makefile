main: Hero.o Creature.o Heroes.o BlackDragon.o Wizard.o Archer.o Vampire.o Zombie.o Thief.o Warrior.o Necromancer.o
	g++ Hero.o Creature.o Heroes.o BlackDragon.o Wizard.o Archer.o Vampire.o Zombie.o Thief.o Warrior.o Necromancer.o -o heroes

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp


BlackDragon.o: BlackDragon.cpp BlackDragon.h Creature.h
	g++ -c BlackDragon.cpp

Wizard.o: Wizard.cpp Wizard.h Creature.h
	g++ -c Wizard.cpp

Archer.o: Archer.cpp Archer.h Creature.h
	g++ -c Archer.cpp

Vampire.o: Vampire.cpp Vampire.h Creature.h
	g++ -c Vampire.cpp

Zombie.o: Zombie.cpp Zombie.h Creature.h
	g++ -c Zombie.cpp

Hero.o: Hero.cpp Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h
	g++ -c Hero.cpp

Warrior.o: Warrior.cpp Warrior.h Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h
	g++ -c Warrior.cpp

Thief.o: Thief.cpp Thief.h Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h
	g++ -c Thief.cpp

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h
	g++ -c Necromancer.cpp

Heroes.o: Heroes.cpp Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h Warrior.h Thief.h Necromancer.h
	g++ -c Heroes.cpp

clean:
	rm -f *.o






