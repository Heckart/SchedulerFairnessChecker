program: main.o AnalysisAlgos.o DynamicArray.o SchedulingAlgos.o
	gcc main.o AnalysisAlgos.o DynamicArray.o SchedulingAlgos.o -o program

main.o: main.c DynamicArray.h SchedulingAlgos.h AnalysisAlgos.h
	gcc -c main.c

DynamicArray.o: DynamicArray.c DynamicArray.h
	gcc -c DynamicArray.c

AnalysisAlgos.o: AnalysisAlgos.c AnalysisAlgos.h SchedulingAlgos.h DynamicArray.h SchedulingAlgos.c DynamicArray.c
	gcc -c AnalysisAlgos.c

SchedulingAlgos.o: SchedulingAlgos.c SchedulingAlgos.h
	gcc -c SchedulingAlgos.c

.PHONY: clean

clean:
	-@rm -f program
	-@rm -f *.o