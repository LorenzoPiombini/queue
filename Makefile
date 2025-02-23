TARGET = queue
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
OBJ_PROD = $(patsubst src/%.c, obj/%_prod.o, $(SRC))
OBJlibque = obj/queue.o
OBJlibquePR = obj/queue_prod.o

LIBNAMEque = que
LIBDIR = /usr/local/lib                                                                                           
INCLUDEDIR = /usr/local/include                                                                                   
SHAREDLIBque = lib$(LIBNAMEque).so

default:$(TARGET)

prod:$(TARGET)_prod

library:                                                                                                          
	sudo gcc -Wall -fPIC -shared -o $(SHAREDLIBque) $(OBJlibque)

libraryPR:                                                                                                          
	sudo gcc -Wall -fPIC -shared -o $(SHAREDLIBque) $(OBJlibquePR)

clean:
	rm -r obj/*.o
	rm $(TARGET)
	rm $(SHAREDLIBque)

$(TARGET) : $(OBJ)
	gcc -o $@ $? -fsanitize=address -fpie -pie -z relro -z now -z noexecstack


obj/%.o:src/%.c
	 gcc -Wall -g3 -c $< -o $@ -Iinclude -fstack-protector-strong  -D_FORTIFY_SOURCE=2 -fpie -fPIE -pie -fsanitize=address



$(TARGET)_prod: $(OBJ_PROD)
	sudo gcc -o $@ $? -fpie -pie -z relro -z now -z noexecstack

obj/%_prod.o:src/%.c
	sudo gcc -Wall -c $< -o $@ -Iinclude -fstack-protector-strong  -D_FORTIFY_SOURCE=2 -fpie -fPIE -pie

install:
	install -d $(INCLUDEDIR)                                                                                  
	install -m 644 include/queue.h $(INCLUDEDIR)
	install -m 755 $(SHAREDLIBque) $(LIBDIR)
	ldconfig 
