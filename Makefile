CC = g++
CFLAGS = -g
LDFLAGS = 
DEPS = src/loader/loader.h src/config/config.h src/lexer/lexer.h
OBJ = obj/main.o obj/config/config.o obj/loader/loader.o obj/lexer/lexer.o

obj/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/config/%.o: src/config/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/loader/%.o: src/loader/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/lexer/%.o: src/lexer/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

argon: $(OBJ)
	$(CC) -o $@ $^ $(LDLAGS) 