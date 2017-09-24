CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
CPPFLAGS = -I/opt/X11/include
EXEC = quadris
OBJECTS = level0.o level1.o level2.o level3.o level4.o oneBlock.o tDisplay.o level.o zBlock.o tBlock.o sBlock.o lBlock.o iBlock.o oBlock.o jBlock.o main.o board.o block.o cell.o cmdInterp.o game.o #gDisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
