class MyCalendar {
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
    }

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
