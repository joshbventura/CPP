CXX = g++
CXXFLAGS = -Wall 

proj4: Game.o Ship.o Item.o Armor.o Weapon.o Planet.o Engine.o Gas.o Enemy.o Mining.o proj4.cpp
	$(CXX) $(CXXFLAGS) Game.o Ship.o Item.o Armor.o Weapon.o Planet.o Engine.o Gas.o Enemy.o Mining.o proj4.cpp -o proj4

Game.o: Ship.o Planet.o Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Ship.o: Item.o Armor.o Weapon.o Ship.h Ship.cpp
	$(CXX) $(CXXFLAGS) -c Ship.cpp

Item.o: Item.h Item.cpp
	$(CXX) $(CXXFLAGS) -c Item.cpp

Armor.o: Item.o Armor.h Armor.cpp
	$(CXX) $(CXXFLAGS) -c Armor.cpp

Weapon.o: Item.o Weapon.h Weapon.cpp
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Planet.o: Planet.h Planet.cpp
	$(CXX) $(CXXFLAGS) -c Planet.cpp

Engine.o: Engine.h Engine.cpp
	$(CXX) $(CXXFLAGS) -c Engine.cpp

Gas.o: Gas.h Gas.cpp
	$(CXX) $(CXXFLAGS) -c Gas.cpp

Enemy.o: Enemy.h Enemy.cpp
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Mining.o: Mining.h Mining.cpp
	$(CXX) $(CXXFLAGS) -c Mining.cpp


run:
	./proj4 proj4_items.txt proj4_planets.txt

val:
	valgrind ./proj4 proj4_items.txt proj4_planets.txt

clean:
	rm -f *.o
	rm -f *~
	


