#emuna002@gmail.com
# Makefile עבור פרויקט גרף ואלגוריתמים

CXX = g++            # המהדר שישתמשו בו
CXXFLAGS = -std=c++11 -Wall -g  # דגלי המהדר (כוללים מידע על דיבוג)

# קבצים מקוריים
SRC = Graph.cpp Algorithms.cpp Point.cpp Queue.cpp QueueNode.cpp
OBJ = $(SRC:.cpp=.o)

# קבצי הפלט
EXEC_MAIN = main
EXEC_TEST = test_algorithms

# יעד ברירת מחדל
all: $(EXEC_MAIN) $(EXEC_TEST)

# בניית קובץ הפלט הראשי
$(EXEC_MAIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC_MAIN) $(OBJ)

# בניית קובץ הפלט של הבדיקות (לבדיקות יחידה עם doctest)
$(EXEC_TEST): test_algorithms.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC_TEST) test_algorithms.cpp $(OBJ)

# בניית התוכנית הראשית
main: $(OBJ) main.cpp
	$(CXX) $(CXXFLAGS) -o $(EXEC_MAIN) $(OBJ) main.cpp

# הרצת בדיקות יחידה
test: $(EXEC_TEST)
	./$(EXEC_TEST)

# בדיקת זליגת זיכרון עם Valgrind
valgrind: $(EXEC_MAIN)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC_MAIN)

# ניקוי קבצים מיותרים וקבצי הפלט
clean:
	rm -f $(OBJ) $(EXEC_MAIN) $(EXEC_TEST)

# כלל לבניית קבצי .o מקבצי .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
