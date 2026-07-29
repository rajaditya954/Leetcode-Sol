class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> m;

        // Build map: stop -> routes containing that stop
        for (int i = 0; i < routes.size(); i++) {
            for (int j : routes[i]) {
                m[j].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visStops;
        vector<bool> visRoutes(routes.size(), false);

        q.push(source);
        visStops.insert(source);

        int cnt = 0;

        while (!q.empty()) {
            int sz = q.size();
            cnt++;

            while (sz--) {
                int t = q.front();
                q.pop();

                // All buses available from this stop
                for (int t : m[t]) {

                    if (visRoutes[t])
                        continue;

                    visRoutes[t] = true;

                    // Visit every stop on this bus route
                    for (int u : routes[t]) {

                        if (u == target)
                            return cnt;

                        if (!visStops.count(u)) {
                            visStops.insert(u);
                            q.push(u);
                        }
                    }
                }
            }
        }

        return -1;
    }
};