exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system
luaFlags =  -llua -ldl


g = g++ -std=c++11 -c

link = target/Imports.o \
target/Animation.o \
target/AnimatedSprite.o \
target/Movement.o \
target/Blood.o \
target/Resource.o \
target/Computer.o \
target/ComputerScreen.o \
target/Zone.o \
target/Entity.o \
target/ActiveState.o \
target/State.o \
target/Game.o \
target/Main2.o

all:
	$(g) Lib/Imports.cpp -o target/Imports.o
	$(g) Lib/Animation.cpp -o target/Animation.o
	$(g) Lib/AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) Entities/Movement.cpp -o target/Movement.o
	$(g) Entities/resources/Blood.cpp -o target/Blood.o
	$(g) Entities/resources/Resource.cpp -o target/Resource.o
	$(g) Entities/Computer.cpp -o target/Computer.o
	$(g) Entities/ComputerScreen.cpp -o target/ComputerScreen.o
	$(g) Zones/Zone.cpp -o target/Zone.o
	$(g) Entities/Entity.cpp -o target/Entity.o
	$(g) States/ActiveState.cpp -o target/ActiveState.o
	$(g) States/State.cpp -o target/State.o
	$(g) Game.cpp -o target/Game.o
	$(g) main2.cpp -o target/Main2.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

ent:	
	$(g) Entities/Movement.cpp -o target/Movement.o
	$(g) Entities/resources/Blood.cpp -o target/Blood.o
	$(g) Entities/resources/Resource.cpp -o target/Resource.o
	$(g) Entities/Computer.cpp -o target/Computer.o
	$(g) Entities/ComputerScreen.cpp -o target/ComputerScreen.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

states:
	$(g) States/ActiveState.cpp -o target/ActiveState.o
	$(g) States/State.cpp -o target/State.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

game:
	$(g) Game.cpp -o target/Game.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;



clean:
	rm -rf target/*