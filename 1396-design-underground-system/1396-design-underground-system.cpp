class UndergroundSystem {
public:
    map<int,pair<int,string>>mp;
    map<pair<string,string>,vector<int>>mp1;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        mp1[{mp[id].second,stationName}].push_back(t-mp[id].first);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum=0;
        for(auto x:mp1[{startStation,endStation}])sum+=x;
        return sum*1.0/mp1[{startStation,endStation}].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */