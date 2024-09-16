CC = g++

Main: Log.o Main.o
	echo $?
	echo $^
	echo "${CC} -o Main $^"

%.o: %.cpp
	${CC} -c $< -o $@

# Main: Log.o Main.o
# 	echo "Creating executable from object files"
# 	${CC} Log.o Main.o -o Main

# %.o: %.cpp
# 	echo "Creating object file from source files"
# 	${CC} -c $< -o $@
