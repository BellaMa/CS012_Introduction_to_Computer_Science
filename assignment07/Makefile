
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic
OBJS = BBoard.o Message.o Topic.o Reply.o User.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

BBoard.o: BBoard.h BBoard.cpp Message.h Topic.h Reply.h User.h 
	$(COMPILE) $(FLAGS) -c BBoard.cpp

Message.o: Message.cpp Message.h 
	$(COMPILE) $(FLAGS) -c Message.cpp

Topic.o: Topic.cpp Topic.h Message.h
	$(COMPILE) $(FLAGS) -c Topic.cpp
	
Reply.o: Reply.h Reply.cpp Message.h
	$(COMPILE) $(FLAGS) -c Reply.cpp

User.o: User.h User.cpp
	$(COMPILE) $(FLAGS) -c User.cpp

BBoard:
	./a.out users1.txt data1.txt

clean:
	rm -rf *~ *.o a.out