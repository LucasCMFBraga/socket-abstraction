CPARAMS = -Iclient/include
GCC = g++ $(CPARAMS)
LD = g++

all: client.o commands.o main.o
	$(LD) -o main.o build/client.o build/py_version_command.o build/main.o
	$(info "SUCESS COMPILED")
client.o:
	$(GCC) -c client/src/client.cpp -o build/client.o
commands.o:
	$(GCC) -c client/src/commands/py_version_command.cpp -o build/py_version_command.o
main.o:
	$(GCC) -c client/src/main.cpp -o build/main.o
clean:
	rm -f build/*.o
