#include<iostream>
#include<vector>
using namespace std;

class Hash
{
    int bucket;
    vector<int> *table;

public:
    Hash(int a)
    {
        bucket = a;
        table = new vector<int>[bucket];
    }
    int HashF(int x)
    {
        return (x % bucket);
    }
    void inserth(int n)
    {
        int index = HashF(n);

        table[index].push_back(n);
    }
    void deleteh(int n)
    {
        int index = HashF(n);
        vector<int>::iterator it;
        it = find(table[index].begin(), table[index].end(), n);
        table[index].erase(it);
    }
    void displayh()
    {
        for (int i = 0; i < bucket; i++)
        {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash h(7); // 7 is count of buckets in
               // hash table
    for (int i = 0; i < n; i++)
        h.inserth(a[i]);

    h.deleteh(12);
    h.displayh();

    return 0;
}