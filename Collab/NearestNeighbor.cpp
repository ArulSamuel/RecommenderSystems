#include <iostream>
#include <string>
#include "CollabRS.h"
#include <map>

NearestNeighbor::NearestNeighbor(CollabRS *collabRS)
{
	this->collabRS=collabRS;
}
NearestNeighbor::~NearestNeighbor()
{
	
}


vector<string> NearestNeighbor::NearestNeighbor(string userId)
{
	//1. Write the distance method manhattan, euclidean, pearson's method 
	//2. Find the nearest neighbors
	//3. Find Predictions
}

double NearestNeighbor::ManhattanDistance(InnerMap songMap1, InnerMap songMap2)
{
	double manHanttanDistance=0.0;
	for (std::map<string,int>::iterator it=collabRS->songMap.begin(); it!=songMap.end(); ++it)
	{
		if(key in map)
		{
			manhattanDistance += Math.abs(songMap1[it]-songMap2[it]);
		}
	}
	return manhattanDistance;
}


double NearestNeighbor::EuclideanDistance(InnerMap songMap1, InnerMap songMap2)
{
	double euclideanDistance=0.0;
	for (std::map<string,int>::iterator it=collabRS->songMap.begin(); it!=songMap.end(); ++it)
	{
		if(key in map)
		{
			euclideanDistance += Math.sqrt((songMap1[it]-songMap2[it])^2);
		}
	}
	return euclideanDistance;
}


double NearestNeighbor::PearsonsCoefficient(InnerMap songMap1, InnerMap songMap2)
{
	double pearsonsCoeff=0.0;
	for (std::map<string,int>::iterator it=collabRS->songMap.begin(); it!=songMap.end(); ++it)
	{
		if(key in map)
		{	
			//Implement logic
			pearsonsCoeff = 1.1;
		}
	}
	return pearsonsCoeff;
}

