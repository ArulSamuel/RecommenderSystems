all: collab

collab: CollabRS.o NearestNeighbor.o
	g++ CollabRS.o NearestNeighbor.o -o collab

CollabRS.o: CollabRS.cpp CollabRS.h 
	g++ -c CollabRS.cpp

NearestNeighbor.o: NearestNeighbor.cpp NearestNeighbor.h 
	g++ -c NearestNeighbor.cpp

clean:
	rm -f *.o collab
