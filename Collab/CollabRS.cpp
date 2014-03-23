#include "NearestNeighbor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
			userMap->insert(std::make_pair(oldUserId,songMap));
			songMap=new InnerMap();
		}
		
		songMap->insert(std::make_pair(songId,playCount));
		oldUserId=userId;
		if(!(datafile >> userId >> songId >> playCount))
		{	
			eof=1;
		}
	}
	//cout<<"\n The length of the user Map is "<<userMap->size();		
}

int main(int argc, char *argv[])
{
	//Hard-coded Datafile name
	string dataFileName = "train_triplets_reduced.txt";	
	CollabRS *collabRS=new CollabRS(dataFileName);
	collabRS->readDataFile();

	//Hard-coded user for whom prediction is required
	string desiredUserId="15c15cedf3e678239877daa22b45cb8d5e9ed9df";
	NearestNeighbor *nearestNeighbor=new NearestNeighbor();
	vector<string> *predictions=nearestNeighbor->findPredictions(desiredUserId,collabRS);
	
	//Displaying the predictions
	//cout<<"\n \n The predicted songs for "<<desiredUserId<<" are ";
	//for(std::vector<string>::iterator itsongs=predictions->begin();itsongs !=predictions->end();itsongs++)
	//{
	//	string song=itsongs[0];
	//	cout<<song;
	//}
}
