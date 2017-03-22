CMP = g++
CLASS = C4Col
CLASS2 = C4Board
MAIN = C4main
EXEC = runit
 
$(EXEC): $(CLASS).o $(CLASS2).o $(MAIN).o
	$(CMP) $(CLASS).o $(CLASS2).o $(MAIN).o -o $(EXEC)
 
$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o
 
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o
 
$(MAIN).o: $(MAIN).cpp $(CLASS).h $(CLASS2).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o
 
clean:
	rm *.o
	rm $(EXEC)
