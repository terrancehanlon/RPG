exeName = mainp

sfmlFlags = -lsfml-graphics -lsfml-window -lsfml-system;

g = g++ -std=c++11 -c

test_link = target/Animation.o \
target/AnimatedSprite.o \
target/Entity.o \
target/ActiveState.o \
target/State.o \
target/Game.o \
target/Main2.o

test:
	$(g) Animation.cpp -o target/Animation.o
	$(g) AnimatedSprite.cpp -o target/AnimatedSprite.o
	$(g) Entity.cpp -o target/Entity.o
	$(g) ActiveState.cpp -o target/ActiveState.o
	$(g) State.cpp -o target/State.o
	$(g) Game.cpp -o target/Game.o
	$(g) main2.cpp -o target/Main2.o
	g++ $(test_link) -o testp $(sfmlFlags)



clean:
	rm -rf target/*