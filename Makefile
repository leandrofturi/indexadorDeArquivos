LIX      := lixinhos
COD      := codigos
BIB      := bibliotecas
DEBUG   := -g -Wall -I.
EXE 	 := indexador


# Cria LIXetos de todos os arquivos de código-fonte para então linká-los no programa final
main: $(LIX)/leituraArquivo.o $(LIX)/indexador.o
	gcc $(LIX)/*.o -o $(EXE) $(DEBUG)

$(LIX)/leituraArquivo.o: $(COD)/leituraArquivo.c $(BIB)/leituraArquivo.h
	gcc -c $(DEBUG) "$(COD)/leituraArquivo.c" -o "$(LIX)/leituraArquivo.o"

$(LIX)/indexador.o: indexador.c
	gcc -c $(DEBUG) indexador.c -o "$(LIX)/indexador.o"

clean:
	-rm $(LIX)/*.o
	-rm $(EXE)

val:
	valgrind --leak-check=full ./$(SAIDA)
