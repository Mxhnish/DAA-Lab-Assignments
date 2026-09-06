// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (remainingCapacity >= items[i].weight)
        {
            maxValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }
        else
        {
            double fraction = (double)remainingCapacity / items[i].weight;
            maxValue += items[i].value * fraction;
            break;
        }
    }

    cout << "\nMaximum value = " << maxValue << endl;

    return 0;
}