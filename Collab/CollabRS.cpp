

#include "CollabRS.h"
#include <iostream>
#include <string.h>
#include <fstream>

//Constructor
CollabRS::CollabRS(string dataFileName)
{
	dataFile=dataFileName;
	userMap=new OuterMap();
}
//Destructor
CollabRS::~CollabRS() {
	userMap->clear();
}

void CollabRS::readDataFile()
{
	ifstream datafile(this->dataFile.c_str());
	int eof=0,playCount=0;
	string userId,songId,oldUserId;

	if(!(datafile >> userId >> songId >> playCount))
	{	
		eof=1;
	}
	oldUserId=userId;
	InnerMap *songMap=new InnerMap();
	while(eof!=1)
	{	
		if(userId!=oldUserId)
		{
			songMap->clear();
		}
		songMap[songId]=playCount;
		userMap[userId]=songMap;
		oldUserId=userId;
		if(!(datafile >> userId >> songId >> playCount))
		{	
			eof=1;
		}
	}
	cout<<"The length of the Map is "<<userMap->size();
	
}

int main(int argc, char *argv[])
{
	string dataFileName = "tasteData.txt";	
	CollabRS *collabRS=new CollabRS(dataFileName);
	collabRS->readDataFile();

	desiredUserId="";
	NearestNeighbor *nearestNeighbor=new NearestNeighbor();
	nearestNeighbor->findPredictions(desiredUserId);

		
}
