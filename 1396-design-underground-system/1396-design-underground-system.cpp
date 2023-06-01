class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> departure; // {id, {str, t}}
    unordered_map<string, pair<int, int>> route; // {str1->str2, {t, n}}

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        departure[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int depTime = departure[id].second;
        string startStn = departure[id].first;
        string routeStr = startStn + "_" + stationName;
        int totalTime = t-depTime;

        route[routeStr].first += totalTime;
        route[routeStr].second += 1;

        departure.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeStr = startStation + "_" + endStation;
        int totalTime = route[routeStr].first;
        int n = route[routeStr].second;

        return (double)totalTime/(double)n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */