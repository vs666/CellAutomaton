#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
typedef unsigned long long ll;

class PRG
{
public:
    PRG(ll key)
    {
        for (int x = 0; x < 64; x++)
        {
            this->seq[x] = vector<ll>(100000, 0);
        }
        p1 = 1000000007;
        p2 = 10201923197;
        mmod -= 1;
        init();
        this->key = (key * p1 + p2) % mmod;
    }
    unsigned long int randomNext()
    {
        unsigned long long int n = 0;
        for (int x = 0; x < 64; x++)
        {
            n += (seq[x][index] << x);
        }
        index++;
        return n;
    }

private:
    ll key;
    int index = 0;
    ll ct, p1, p2;
    unsigned long long mmod;
    ll CODE[8] = {1, 0, 0, 1, 0, 1, 1, 0};
    vector<ll> seq[64];
    void init()
    {
        for (int x = 0; x < 64; x++)
        {
            if (x == 0)
            {
                for (int a = 0; a < 100000; a += 64)
                {
                    for (int y = 0; y < 64; y++)
                    {
                        if (a + y >= 100000)
                        {
                            break;
                        }
                        seq[x][a + y] = ((key >> y) & 1);
                    }
                    key = (key * p1 + p2) % mmod;
                }
            }
            else
            {
                for (int y = 0; y < 100000; y++)
                {
                    seq[x][y] = CODE[seq[x - 1][(y - 1 + 100000) % 100000] + seq[x - 1][y] * 2 + seq[x - 1][(y + 1) % 100000] * 4];
                }
            }
        }
    }
};

int main()
{
    ll k;
    cout << "Enter the key for PRG : ";
    cin >> k;
    cout << "Initializing parameters..." << endl;
    PRG *ob = new PRG(k);
    long int n;
    cout << "Enter the number of random numbers you want to generate : ";
    cin >> n;
    cout << "Generating random numbers..." << endl;
    for (int x = 0; x < n; x++)
    {
        cout << "Number is :: " << ob->randomNext() << endl;
    }
}