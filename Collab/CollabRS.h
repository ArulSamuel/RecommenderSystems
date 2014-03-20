
#include <map>
#include <string>

using namespace std;

typedef std::map<string, int> InnerMap;
typedef std::map<string, InnerMap> OuterMap;

class CollabRS 
{

public: 
	OuterMap *userMap;
	string dataFile;

	CollabRS(string dataFileName);
	void readDataFile();
	virtual ~CollabRS();
};

