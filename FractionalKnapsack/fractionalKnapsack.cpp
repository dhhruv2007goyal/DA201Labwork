//Dhhruv Goyal, 25/DA/021

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {

    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;

    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (Item item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else {
            totalValue +=
                item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int capacity = 50;
    double maximumValue =
        fractionalKnapsack(capacity, items);
    cout << "Maximum value: " << maximumValue;
    return 0;
}