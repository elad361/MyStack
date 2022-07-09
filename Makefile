Server: 
	g++ -o Server Server.cpp StackHandler.cpp Stack.cpp -lpthread

terminal:
	g++ TerminalClient.cpp StackHandler.cpp Stack.cpp -o TerminalStack

all:
	g++ -o Server Server.cpp StackHandler.cpp Stack.cpp -lpthread
	g++ -o Client Client.cpp StackHandler.cpp Stack.cpp