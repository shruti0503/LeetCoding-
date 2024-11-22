class MyCalendar {
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
    }

 //
 //For each book call, you iterate through the list of bookings to check 
 //for overlaps.
 //  If there are  m callsto the book , the worst case time complexity is O(m2).
 
    bool book(int start, int end) {
        for (const pair<int, int>& event : bookings) {
            if (start < event.second && end > event.first) {
                return false; // Overlapping event, cannot book.
            }
        }

        bookings.push_back({start, end});
        return true; // Successfully booked.
    }
};
