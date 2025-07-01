#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 3, 4, 5};
    float weight = 0;
    float sum = 0;
    float w[] = {0.1, 0.4, 0.6, 0.4};

    for (int i = 0; i < 4; i++) {
        sum += arr[i] * w[i];
        weight += w[i];
    }

    double ans = sum / weight;
    cout << ans;

    return 0;
}