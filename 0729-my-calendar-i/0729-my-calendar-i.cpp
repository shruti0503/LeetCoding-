class MyCalendar {
public:
    map<int, int> bookings;

    MyCalendar() {}

    bool book(int start, int end) {
        for (const auto& [s, e] : bookings) {
            // Check if the intervals overlap
            if (max(s, start) < min(e, end)) {
                return false; // Overlapping interval found
            }
        }

        // No overlap, insert the interval
        bookings[start] = end;
        return true;
    }
};
