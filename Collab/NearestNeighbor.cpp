#include "NearestNeighbor.h"
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

//Constructor and Destructor for initialization and Memory Management
NearestNeighbor::NearestNeighbor()
{
	
}
NearestNeighbor::~NearestNeighbor()
{
	
}


vector<string>* NearestNeighbor::findPredictions(string userId, CollabRS *collabRS)
{
	PairVector *songs=new PairVector();
	vector<string> *predictions=new vector<string>();
	PairVector *neighbors=new PairVector();
	string nearestUserId;
	
	//1. Write the distance method manhattan, euclidean, pearson's method
	OuterMap::iterator it2;
	for(std::map<string,InnerMap*>::iterator it=collabRS->userMap->begin(); it!=collabRS->userMap->end(); ++it)
	{
		double distance=0.0;
		it2=collabRS->userMap->find(userId);
		if(it->first!=userId && it2!=collabRS->userMap->end())
		{
			distance=ManhattanDistance(it->second,it2->second, collabRS);
			distance=EuclideanDistance(it->second,it2->second, collabRS);
			neighbors->push_back(std::make_pair(it->first,distance));
		}
	}

	
	//2. Find the nea0rest neighbors
	std::sort(neighbors->begin(),neighbors->end(), myobject);
	int count=0;
	PairVector::iterator it1=neighbors->begin();
	nearestUserId=it1->first;
	cout<<"nearest USer ID is"<<nearestUserId;
	

	//3. Find Predictions
	InnerMap *mapGivenUser=collabRS->userMap->find(userId)->second;
	InnerMap *mapNearestUser=collabRS->userMap->find(nearestUserId)->second;
	for (std::map<string,int>::iterator it1=mapNearestUser->begin(); it1!=mapNearestUser->end(); ++it1)
	{
		if(mapGivenUser->count(it1->first)==0)
		{	
			songs->push_back(std::make_pair(it1->first,it1->second));
		}	
	}

	//4. Display the predictions
	std::sort(songs->begin(),songs->end(), myobject);
	for (PairVector::iterator it1=songs->begin(); it1!=songs->end(); ++it1)
	{
		cout<<"\n The songs to be seen are "<<it1->first<<" with rating "<<it1->second;
		predictions->push_back(it1->first);
	}
	return predictions;
}

/*
	Manhattan distance measure heuristic
*/
double NearestNeighbor::ManhattanDistance(InnerMap *songMap1, InnerMap *songMap2, CollabRS *collabRS)
{
	double manhattanDistance=0.0;
	InnerMap::iterator it2;
	for (std::map<string,int>::iterator it1=songMap1->begin(); it1!=songMap1->end(); ++it1)
	{	
		it2=songMap2->find(it1->first);
		if(!(it2==songMap2->end()))
		{
			manhattanDistance += abs(it1->second-it2->second);
			//cout<<"\n Manhattan distance for song "<<it1->first<<" is "<<manhattanDistance;
		}
	}
	return manhattanDistance;
}

/*
	Euclidean distance measure heuristic
*/
double NearestNeighbor::EuclideanDistance(InnerMap *songMap1, InnerMap *songMap2, CollabRS *collabRS)
{
	double euclideanDistance=0.0;
	InnerMap::iterator it2;
	for (std::map<string,int>::iterator it1=songMap1->begin(); it1!=songMap1->end(); ++it1)
	{	
		it2=songMap2->find(it1->first);
		if(!(it2==songMap2->end()))
		{
			euclideanDistance += sqrt(pow((it1->second-it2->second),2));
		}
	}
	return euclideanDistance;
}


/*
	Pearson's Coefficient distance measure heuristic
*/
//double NearestNeighbor::PearsonsCoefficient(InnerMap songMap1, InnerMap songMap2)
//{
//	double pearsonsCoeff=0.0;
//	InnerMap::iterator it2;
//	for (std::map<string,int>::iterator it1=collabRS->songMap1.begin(); it1!=songMap1.end(); ++it1)
//	{
//		if(it2=songMap2.find(songMap1[it1]))
//		{	
//			//Implement logic
//			pearsonsCoeff = 1.1;
//		}
//	}
//	return pearsonsCoeff;
//}

/*
	Vector Cosine distance measure heuristic
*/
