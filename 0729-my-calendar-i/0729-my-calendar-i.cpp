class MyCalendar {
public:
   map<int, int>bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next= bookings.lower_bound(start);
        if(next!=bookings.end() and next->first<end){
            return false;
        }

        if(next!=bookings.begin()){
            auto prev= std::prev(next);
            if(prev->second>start){
                return false;
            }
        }

        bookings[start]=end;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */