// Yunus Tan Kerestecioglu

#include <string>
#include <vector>
using namespace std;

struct busStop {
	string busStopName;
	busStop *left;
	busStop *right;

	/*
	busStop (const string & s, busStop * prev, busStop * next)
		: busStopName(s), left(prev), right (next)
	{}
	*/
};

struct busLine {
	string busLineName;
	busLine *next;
	busStop *busStops;

	busLine (const string & s, busStop * next, busLine * link)
		: busLineName(s), busStops(next), next (link)
	{}
};

class Bus{
	private:
		busLine * head;
		int size;

	public:
		Bus();
		void AddToEnd(string name, busStop *stop);
		void AddToBeginning(string name, busStop *stop);
		void printLine(string name, busStop * stopHead);
		void printBusLines();
		bool consistencyCheck();
		bool busLineExists(string name);
		bool busStopExists(busStop * stop_head, string stop_name);
		void addBusLine();
		void AddStopToBeginning(busStop * & head, string name);
		void AddStop(busStop*stop_head,string prevStop, string name);
		void addBusStop();
		void DelBusStops(busStop * stopHead);
		void deleteBusLine();
		void DelStop(busStop * stop, busStop * & stopHead);
		void deleteBusStop();
		string FormPath(busLine * lineHead, string stop1, string stop2, int pos1, int pos2);
		bool InTheSameLine(busLine * lineHead, string stop1, string stop2, string & path);
		bool BelongSameLine(string stop1, string stop2, string & path);
		vector<string> TransitionStops();
		bool StopsInTable(string stop1, string stop2);
		void pathfinder();
		void DelList();
};