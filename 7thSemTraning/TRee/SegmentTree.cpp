#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class SegmentTree {

public:
    vector<int> Maxtree;
    vector<int> Mintree;
    int n;

    SegmentTree(const vector<int>& stockPrices) {
        buildMaxTree(stockPrices);
        buildMinTree(stockPrices);
    }

    // Function to build the segment tree

     void buildMinTree(const vector<int>& stockPrices) {
        n = stockPrices.size();
            Mintree.resize(2 * n);
            for (int i = 0; i < n; i++) {
                Mintree[i + n] = stockPrices[i];
            }
            for (int i = n - 1; i > 0; --i) {
                Mintree[i] = min(Mintree[2 * i], Mintree[2 * i + 1]);
            }
        }

    void buildMaxTree(const vector<int>& stockPrices) {
        n = stockPrices.size();
            Maxtree.resize(2 * n);
            for (int i = 0; i < n; i++) {
                Maxtree[i + n] = stockPrices[i];
            }
            for (int i = n - 1; i > 0; --i) {
                Maxtree[i] = max(Maxtree[2 * i], Maxtree[2 * i + 1]);
            }
        } 

    int getMaxPrice(int l , int r){
        if(l > r){
            cout << "Invalid range "<< l << " > " << r << endl;
            return -1;
        }

        if(l < 0 || r > n){
            if(l < 0) cout << "Left index out of bounds" << l << " < 0" << endl;
            if(r > n) cout << "Right index out of bounds " << r << " > " << n << endl;
            return -1;
        }
        if(l == r) return Maxtree[l + n];

        l+=n;
        r+=n;
        int maxPrice = INT_MIN;
        while(l <= r){
            if(l % 2 == 1){
                maxPrice = max(maxPrice, Maxtree[l]);
                l++;
            }
            if(r % 2 == 0){
                maxPrice = max(maxPrice, Maxtree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return maxPrice;
    }

    int getMinPrice(int l , int r){
        if(l > r){
            cout << "Invalid range "<< l << " > " << r << endl;
            return -1;
        }

        if(l < 0 || r > n){
            if(l < 0) cout << "Left index out of bounds" << l << " < 0" << endl;
            if(r > n) cout << "Right index out of bounds " << r << " > " << n << endl;
            return -1;
        }
        if(l == r) return Mintree[l + n];


        l+=n;
        r+=n;
        int minPrice = INT_MAX;
        while(l <= r){
            if(l % 2 == 1){
                minPrice = min(minPrice, Mintree[l]);
                l++;
            }
            if(r % 2 == 0){
                minPrice = min(minPrice, Mintree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return minPrice;
    }

};

int main(){

    vector<int> stockPrices = {4,6,1,10,2};
    int n = stockPrices.size();

    SegmentTree tree(stockPrices);

    cout << "Segment MaxTree built successfully." << endl;
    cout << "Max price in range (1, 3): " << tree.getMaxPrice(5,2) << endl;
    cout << "Max price in range (0, 4): " << tree.getMaxPrice(0, 2) << endl;

    cout << "Segment MinTree built successfully." << endl;
    cout << "Min price in range (1, 3): " << tree.getMinPrice(1, 3) << endl;
    cout << "Min price in range (0, 4): " << tree.getMinPrice(0, 4) << endl;
    
}