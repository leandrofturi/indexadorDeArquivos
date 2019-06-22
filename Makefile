LIX      := lixinhos
COD      := codigos
BIB      := bibliotecas
DEBUG    := -g -Wall -I.
EXE 	 := indexador

main: $(LIX)/encadeada.o $(LIX)/arvore.o $(LIX)/balanceada.o $(LIX)/patricia.o $(LIX)/hash.o $(LIX)/leitura.o $(LIX)/indexador.o
	gcc $(LIX)/*.o -o $(EXE) $(DEBUG)

$(LIX)/encadeada.o: $(COD)/encadeada.c $(BIB)/encadeada.h
	gcc -c $(DEBUG) "$(COD)/encadeada.c" -o "$(LIX)/encadeada.o"

$(LIX)/arvore.o: $(COD)/arvore.c $(BIB)/arvore.h
	gcc -c $(DEBUG) "$(COD)/arvore.c" -o "$(LIX)/arvore.o"

$(LIX)/balanceada.o: $(COD)/balanceada.c $(BIB)/balanceada.h
	gcc -c $(DEBUG) "$(COD)/balanceada.c" -o "$(LIX)/balanceada.o"

$(LIX)/patricia.o: $(COD)/patricia.c $(BIB)/patricia.h
	gcc -c $(DEBUG) "$(COD)/patricia.c" -o "$(LIX)/patricia.o"

$(LIX)/hash.o: $(COD)/hash.c $(BIB)/hash.h
	gcc -c $(DEBUG) "$(COD)/hash.c" -o "$(LIX)/hash.o"

$(LIX)/leitura.o: $(COD)/leitura.c $(BIB)/leitura.h
	gcc -c $(DEBUG) "$(COD)/leitura.c" -o "$(LIX)/leitura.o"

$(LIX)/indexador.o: indexador.c
	gcc -c $(DEBUG) indexador.c -o "$(LIX)/indexador.o"

clean:
	-rm $(LIX)/*.o
	-rm $(EXE)

val:
	valgrind --leak-check=full ./$(EXE) $(DEBUG)
