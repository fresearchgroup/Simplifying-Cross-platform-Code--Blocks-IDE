# OPTIONS=-I`pwd` -I/usr/include/X11 -L/usr/lib/i386-linux-gnu -L/usr/X11R6/lib -lX11  

# OPTIONS=-I`pwd` -I/usr/include/X11 `pkg-config --libs x11`

OPTIONS=-I`pwd` `pkg-config --libs --cflags x11`

OBJS = canvas.o polygon.o line.o circle.o sprite.o turtle.o rectangle.o text.o turtleSim.o

HDRS =  spriteInterface.h pose.h composite.h common_def.h  sprite.h canvas.h polygon.h turtle.h line.h circle.h rectangle.h text.h turtleSim.h simplecpp

default: $(OBJS) $(HDRS)
	ar rcs libsprite.a $(OBJS)

config: 
	cp -v $(HDRS) ../include
	rm -f ..lib/libsprite.a
	rm -f libsprite.a
	rm -f *.o
	make
	cp libsprite.a ../lib/

canvas.o: canvas.cpp canvas.h sprite.h common_def.h turtle.h
	../makes++ -g -c canvas.cpp -o canvas.o 

polygon.o: polygon.cpp polygon.h sprite.h common_def.h
	../makes++ -g -c polygon.cpp -o polygon.o

line.o: line.cpp line.h sprite.h common_def.h
	../makes++ -g -c line.cpp -o line.o 

rectangle.o: rectangle.cpp rectangle.h sprite.h common_def.h
	../makes++ -g -c rectangle.cpp -o rectangle.o 

circle.o: circle.cpp circle.h sprite.h common_def.h
	../makes++ -g -c circle.cpp -o circle.o 

text.o: text.cpp text.h sprite.h canvas.h common_def.h
	../makes++ -g -c text.cpp -o text.o 

sprite.o: sprite.h sprite.cpp common_def.h pose.h
	../makes++ -g -c sprite.cpp -o sprite.o 

turtle.o: turtle.h turtle.cpp common_def.h
	../makes++ -g -c turtle.cpp -o turtle.o 

turtleSim.o: turtleSim.h turtleSim.cpp
	../makes++ -g -c turtleSim.cpp -o turtleSim.o 

clean:
	rm *.o *.a

exe: 2turtles.cpp $(OBJS)
	g++ 2turtles.cpp $(OBJS) $(OPTIONS)

exe2: tt.cpp libsprite.a
	g++ tt.cpp libsprite.a $(OPTIONS)

exep: tree.cpp $(OBJS)
	g++ tree.cpp $(OBJS) $(OPTIONS)

exet: transformvectors.cpp $(OBJS)
	g++ transformvectors.cpp $(OBJS) $(OPTIONS)

exerect : transformvectors.cpp $(OBJS)
	g++ rectmain.cpp $(OBJS) $(OPTIONS)

exedraw : drawformula.cpp $(OBJS)
	g++ drawformula.cpp $(OBJS) $(OPTIONS)

texttest: texttest.cpp $(OBJS)
	g++ texttest.cpp $(OBJS) $(OPTIONS)

hilbert: hilbert.cpp $(OBJS)
	g++ hilbert.cpp $(OBJS) $(OPTIONS)

OBJS2 = canvas.o sprite.o polygon.o line.o circle.o turtle.o rectangle.o

trtest: trtest.cpp $(OBJS2) pose.h sprite.h canvas.h polygon.h composite.h
	g++ trtest.cpp canvas.cpp sprite.cpp polygon.cpp $(OPTIONS)

colonytest: colonytest.cpp $(OBJS2) pose.h sprite.h canvas.h polygon.h composite.h
	g++ colonytest.cpp canvas.cpp sprite.cpp polygon.cpp $(OPTIONS)

linetest: linetest.cpp pose.h sprite.h canvas.h polygon.h line.h $(OBJS2)
	g++ linetest.cpp line.cpp canvas.cpp sprite.cpp $(OPTIONS)

circletest: circletest.cpp pose.h sprite.h canvas.h polygon.h circle.h $(OBJS2)
	g++ circletest.cpp circle.cpp canvas.cpp sprite.cpp $(OPTIONS)

turtletest: turtletest.cpp $(HDRS) $(OBJS2)
	g++ turtletest.cpp $(OBJS2) $(OPTIONS)

rectangletest: rectangletest.cpp $(HDRS) $(OBJS2)
	g++ rectangletest.cpp $(OBJS2) $(OPTIONS)