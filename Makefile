exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system
# luaFlags =  -llua5.3 -ldl -lm -I/usr/include/lua5.3
luaFlags = -llua -ldl -lm
# luaflags = -l-I/usr/include/lua5.3

g = g++ -std=c++17 -c -g

link = target/Imports.o \
target/TextureManager.o \
target/TextManager.o \
target/ScreenManager.o \
target/Animation.o \
target/AnimatedSprite.o \
target/Movement.o \
target/StorageItem.o \
target/Storage.o \
target/Creator.o \
target/Blood.o \
target/Resource.o \
target/Rock.o \
target/Computer.o \
target/ComputerScreen.o \
target/BloodCase.o \
target/HumanPod.o \
target/Constraint.o \
target/BaseScreen.o \
target/InteractionScreen.o \
target/Zone.o \
target/ZoneBase.o \
target/Obstacle.o \
target/Entity.o \
target/Npc.o \
target/BaseState.o \
target/Menu.o \
target/ActiveState.o \
target/State.o \
target/Game.o \
target/Main2.o

all:
	$(g) Lib/Imports.cpp -o target/Imports.o
	$(g) Lib/TextureManager.cpp -o target/TextureManager.o
	$(g) Lib/TextManager.cpp -o target/TextManager.o
	$(g) Lib/ScreenManager.cpp -o target/ScreenManager.o 
	$(g) Lib/Animation.cpp -o target/Animation.o
	$(g) Lib/AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) Entities/Rock.cpp -o target/Rock.o
	$(g) Entities/Movement.cpp -o target/Movement.o
	$(g) Entities/StorageItem.cpp -o target/StorageItem.o
	$(g) Entities/Storage.cpp -o target/Storage.o 
	$(g) Entities/Creator.cpp -o target/Creator.o
	$(g) Entities/resources/Blood.cpp -o target/Blood.o
	$(g) Entities/resources/Resource.cpp -o target/Resource.o
	$(g) Entities/Rock.cpp -o target/Rock.o
	$(g) Entities/Computer.cpp -o target/Computer.o
	$(g) Entities/ComputerScreen.cpp -o target/ComputerScreen.o
	$(g) Entities/BloodCase.cpp -o target/BloodCase.o
	$(g) Entities/HumanPod.cpp -o target/HumanPod.o
	$(g) Entities/BaseScreen.cpp -o target/BaseScreen.o
	$(g) Entities/InteractionScreen.cpp -o target/InteractionScreen.o
	$(g) Zones/constraints/Constraint.cpp -o target/Constraint.o
	$(g) Zones/Zone.cpp -o target/Zone.o
	$(g) Zones/ZoneBase.cpp -o target/ZoneBase.o
	$(g) Entities/Obstacle.cpp -o target/Obstacle.o
	$(g) Entities/Entity.cpp -o target/Entity.o
	$(g) Entities/Npc.cpp -o target/Npc.o
	$(g) States/BaseState.cpp -o target/BaseState.o
	$(g) States/Menu.cpp -o target/Menu.o
	$(g) States/ActiveState.cpp -o target/ActiveState.o
	$(g) States/State.cpp -o target/State.o
	$(g) Game.cpp -o target/Game.o
	$(g) main2.cpp -o target/Main2.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

ent:	
	$(g) Entities/Movement.cpp -o target/Movement.o
	$(g) Entities/StorageItem.cpp -o target/StorageItem.o
	$(g) Entities/Storage.cpp -o target/Storage.o 
	$(g) Entities/Creator.cpp -o target/Creator.o
	$(g) Entities/resources/Blood.cpp -o target/Blood.o
	$(g) Entities/resources/Resource.cpp -o target/Resource.o
	$(g) Entities/Rock.cpp -o target/Rock.o
	$(g) Entities/Obstacle.cpp -o target/Obstacle.o
	$(g) Entities/Computer.cpp -o target/Computer.o
	$(g) Entities/ComputerScreen.cpp -o target/ComputerScreen.o
	$(g) Entities/BloodCase.cpp -o target/BloodCase.o
	$(g) Entities/HumanPod.cpp -o target/HumanPod.o
	$(g) Entities/BaseScreen.cpp -o target/BaseScreen.o
	$(g) Entities/InteractionScreen.cpp -o target/InteractionScreen.o
	$(g) Entities/Entity.cpp -o target/Entity.o 
	$(g) Entities/Npc.cpp -o target/Npc.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

states:
	$(g) States/BaseState.cpp -o target/BaseState.o
	$(g) States/Menu.cpp -o target/Menu.o
	$(g) States/ActiveState.cpp -o target/ActiveState.o
	$(g) States/State.cpp -o target/State.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

zones:
	$(g) Zones/constraints/Constraint.cpp -o target/Constraint.o
	$(g) Zones/Zone.cpp -o target/Zone.o
	$(g) Zones/ZoneBase.cpp -o target/ZoneBase.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;

lib:
	$(g) Lib/TextureManager.cpp -o target/TextureManager.o
	$(g) Lib/TextManager.cpp -o target/TextManager.o
	$(g) Lib/ScreenManager.cpp -o target/ScreenManager.o
	g++ $(link) -o $(execName) $(sfmlFlags) $(luaFlags);

game:
	$(g) Game.cpp -o target/Game.o
	g++ $(link) -o $(exeName) $(sfmlFlags) $(luaFlags) ;



clean:
	rm -rf target/*/