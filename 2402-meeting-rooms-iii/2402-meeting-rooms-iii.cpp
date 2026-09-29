class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        set<int> freeRooms;

        // {availableTime, roomNumber}
        set<pair<long long, int>> busyRooms;

        vector<int> count(n, 0);

        // Initially all rooms are free
        for (int i = 0; i < n; i++) {
            freeRooms.insert(i);
        }

        for (auto &meeting : meetings) {

            long long start = meeting[0];
            long long end = meeting[1];

            // Move all rooms that have become free
            while (!busyRooms.empty() &&
                   busyRooms.begin()->first <= start) {

                auto it = busyRooms.begin();

                int room = it->second;

                freeRooms.insert(room);

                busyRooms.erase(it);
            }

            // Case 1: Some room is free
            if (!freeRooms.empty()) {

                // Smallest room number
                int room = *freeRooms.begin();

                freeRooms.erase(freeRooms.begin());

                busyRooms.insert({end, room});

                count[room]++;
            }

            // Case 2: No room is free
            else {

                // Room that becomes free earliest
                auto it = busyRooms.begin();

                long long availableTime = it->first;
                int room = it->second;

                busyRooms.erase(it);

                long long duration = end - start;

                // Meeting waits until this room becomes free
                long long newEnd = availableTime + duration;

                busyRooms.insert({newEnd, room});

                count[room]++;
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};