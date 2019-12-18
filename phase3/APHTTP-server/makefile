CC=g++
STD=-std=c++11 -Wall -pedantic -g
CF=$(STD)
BUILD_DIR=build
JEEKJEEK_DIR=server/jeekjeek

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: server/handlers.cpp server/handlers.hpp
	$(CC) $(CF) -c server/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/server_main.o: server/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/server_main.o

server.out: $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/server_main.o $(JEEKJEEK_DIR)/jeekjeek.o $(JEEKJEEK_DIR)/jeek.o $(JEEKJEEK_DIR)/user.o $(JEEKJEEK_DIR)/reply.o $(JEEKJEEK_DIR)/user_session.o 
	$(CC) $(CF) $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/jeekjeek.o $(BUILD_DIR)/jeek.o $(BUILD_DIR)/user.o $(BUILD_DIR)/reply.o $(BUILD_DIR)/user_session.o -o server.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null




$(JEEKJEEK_DIR)/jeekjeek.o: $(JEEKJEEK_DIR)/jeekjeek.cpp $(JEEKJEEK_DIR)/jeekjeek.hpp
	$(CC) $(CF) -c -g $(JEEKJEEK_DIR)/jeekjeek.cpp -o $(BUILD_DIR)/jeekjeek.o
$(JEEKJEEK_DIR)/jeek.o: $(JEEKJEEK_DIR)/jeek.cpp $(JEEKJEEK_DIR)/jeek.hpp
	$(CC) $(CF) -c -g $(JEEKJEEK_DIR)/jeek.cpp -o $(BUILD_DIR)/jeek.o
$(JEEKJEEK_DIR)/user.o: $(JEEKJEEK_DIR)/user.cpp $(JEEKJEEK_DIR)/user.hpp
	$(CC) $(CF) -c -g $(JEEKJEEK_DIR)/user.cpp -o $(BUILD_DIR)/user.o
$(JEEKJEEK_DIR)/reply.o: $(JEEKJEEK_DIR)/reply.cpp $(JEEKJEEK_DIR)/reply.hpp
	$(CC) $(CF) -c -g $(JEEKJEEK_DIR)/reply.cpp -o $(BUILD_DIR)/reply.o

$(JEEKJEEK_DIR)/user_session.o: $(JEEKJEEK_DIR)/user_session.cpp $(JEEKJEEK_DIR)/user_session.hpp
	$(CC) $(CF) -c -g $(JEEKJEEK_DIR)/user_session.cpp -o $(BUILD_DIR)/user_session.o







