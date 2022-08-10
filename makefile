CPARAMS = -Iinter_proc_client/include
GCC = g++ $(CPARAMS)
LD = g++

all: client.o commands.o main.o
	$(LD) -o main.o build/client.o build/py_version_command.o build/plot_command.o build/main_caller.o
	$(info "SUCESS COMPILED")
client.o:
	$(GCC) -c inter_proc_client/src/client.cpp -o build/client.o
commands.o:
	$(GCC) -c inter_proc_client/src/commands/py_version_command.cpp -o build/py_version_command.o
	$(GCC) -c inter_proc_client/src/commands/plot_command.cpp -o build/plot_command.o
main.o:
	$(GCC) -c inter_proc_client/src/main.cpp -o build/main_caller.o
clean:
	rm -f build/*.o
