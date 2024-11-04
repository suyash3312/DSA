class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Calculate the time to reach the target for each car
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position in descending order
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double lastTime = 0;

        // Process each car, starting from the one closest to the target
        for (auto car : cars) {
            double time = car.second;

            // If the current car takes longer than the last fleet's time, it forms a new fleet
            if (time > lastTime) {
                fleets++;
                lastTime = time;  // Update the time of the last fleet
            }
        }

        return fleets;
    }
};
// stack approach
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>

// using namespace std;

// int carFleet(int target, vector<int>& position, vector<int>& speed) {
//     // Pair of (position, time to reach the target)
//     vector<pair<int, double>> cars;
//     int n = position.size();

//     // Calculate the time each car will take to reach the target
//     for (int i = 0; i < n; ++i) {
//         double time = (double)(target - position[i]) / speed[i];
//         cars.push_back({position[i], time});
//     }

//     // Sort the cars by their position in descending order (from farthest to nearest)
//     sort(cars.rbegin(), cars.rend());

//     stack<double> fleets;

//     // Iterate over each car, from the closest to the farthest
//     for (auto& car : cars) {
//         double time = car.second;

//         // If the current car takes longer than the car in front, it forms a new fleet
//         if (fleets.empty() || time > fleets.top()) {
//             fleets.push(time);
//         }
//         // If the current car can catch up to the fleet, it joins the fleet (do nothing)
//     }

//     // The number of fleets will be the size of the stack
//     return fleets.size();
// }

// int main() {
//     int target = 12;
//     vector<int> position = {10, 8, 0, 5, 3};
//     vector<int> speed = {2, 4, 1, 1, 3};

//     int result = carFleet(target, position, speed);
//     cout << "Number of car fleets: " << result << endl;

//     return 0;
// } 