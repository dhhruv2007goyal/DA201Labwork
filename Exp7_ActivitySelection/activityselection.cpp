//Dhhruv Goyal, 25/DA/021

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(),
         activities.end(),
         compare);
    cout << "\nSelected activities:\n";
    int lastFinish = -1;
    for (int i = 0; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            cout << "("
                 << activities[i].start
                 << ", "
                 << activities[i].finish
                 << ") ";
            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> activities(n);
    cout << "Enter start and finish time:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start
            >> activities[i].finish;
    }
    activitySelection(activities);
    return 0;
}