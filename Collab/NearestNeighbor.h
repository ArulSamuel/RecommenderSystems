#include "CollabRS.h"
#include<map>
#include<vector>

typedef std::vector<std::pair<string,double> > PairVector;

struct myclass {
	bool operator()(std::pair<string,double> i, std::pair<string,double> j) {
		return (i.second>j.second);
	}
}myobject;

class NearestNeighbor
{
	public: 
	NearestNeighbor();
	double ManhattanDistance(InnerMap *songMap1, InnerMap *songMap2, CollabRS *collabRS);
	double EuclideanDistance(InnerMap *songMap1, InnerMap *songMap2, CollabRS *collabRS);
	double PearsonsCoefficient(InnerMap songMap1, InnerMap songMap2);
	vector<string>* findPredictions(string userId, CollabRS *collabRS);
	~NearestNeighbor();	
};


