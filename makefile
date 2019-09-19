CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
OBJS = main.o controller.o room.o entryRoom.o goblinRoom.o waterRoom.o mazeRoom.o bossRoom.o princessRoom.o mapObjects.o player.o goblin.o warlock.o wall.o blood.o key.o water.o lever.o throwingStar.o bow.o archerX.o princess.o
SRCS = main.cpp controller.cpp room.cpp entryRoom.cpp goblinRoom.cpp waterRoom.cpp mazeRoom.cpp bossRoom.cpp princessRoom.cpp mapObjects.cpp player.cpp goblin.cpp warlock.cpp wall.cpp blood.cpp key.cpp lever.cpp throwingStar.cpp bow.cpp archerX.cpp princess.cpp
HEADERS = controller.hpp room.hpp entryRoom.hpp goblinRoom.hpp waterRoom.hpp mazeRoom.hpp bossRoom.hpp princessRoom.hpp mapObjects.hpp player.hpp goblin.hpp warlock.hpp wall.hpp blood.hpp key.hpp lever.hpp throwingStar.hpp bow.hpp archerX.hpp princess.hpp

shopping: ${OBJS} ${HEADER}
	${CXX} ${OBJS} -o final

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f final *.o 