#include<map>

class NearestNeighbor
{
public: 

	CollabRS *collabRS;
	NearestNeighbor::NearestNeighbor();
	NearestNeighbor::~NearestNeighbor();
	double NearestNeighbor::ManhattanDistance(InnerMap songMap1, InnerMap songMap2);
	double NearestNeighbor::EuclideanDistance(InnerMap songMap1, InnerMap songMap2);
	double NearestNeighbor::PearsonsCoefficient(InnerMap songMap1, InnerMap songMap2);
	

}


