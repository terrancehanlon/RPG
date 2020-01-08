exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system;

g = g++ -std=c++11 -c

link = target/Animation.o \
target/AnimatedSprite.o \
target/Entity.o \
target/ActiveState.o \
target/State.o \
target/Game.o \
target/Main2.o

all:
	$(g) Lib/Animation.cpp -o target/Animation.o
	$(g) Lib/AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) Entities/Entity.cpp -o target/Entity.o
	$(g) States/ActiveState.cpp -o target/ActiveState.o
	$(g) States/State.cpp -o target/State.o
	$(g) Game.cpp -o target/Game.o
	$(g) main2.cpp -o target/Main2.o
	g++ $(link) -o mainp $(sfmlFlags)



clean:
	rm -rf target/*