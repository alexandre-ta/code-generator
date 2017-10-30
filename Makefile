all: scc

OBJS =  scc.o  \
        codegen.o \
		semantictree.o  \
        treenode.o  \
		llvmbuild.o  \
        main.o    \
        tokens.o  \
        corefn.o  \

CPPFLAGS = `llvm-config --cppflags`
LDFLAGS = `llvm-config --ldflags`
LIBS = `llvm-config --libs`

clean:
	$(RM) -rf scc.cpp scc.hpp scc tokens.cpp $(OBJS)

scc.cpp: scc.y
	bison -d -o $@ $^
	
scc.hpp: scc.cpp

tokens.cpp: tokens.l scc.hpp
	flex -o $@ $^

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<


scc: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)


