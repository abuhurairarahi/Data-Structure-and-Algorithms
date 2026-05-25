#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    vector<int> takenCoins;
    int totalCoins;
};

info calcCoins (int numberofCoins, int amount, vector<int> &Coins)
{
    vector<info>dpTable(amount + 1);
    dpTable[0].totalCoins = 0;
    for(int index = 1; index <= amount; index++)
    {
        dpTable[index].totalCoins = 1e9;
    }

    for(int indexA = 0; indexA < numberofCoins; indexA++)
    {
        for(int indexB = 1; indexB <= amount; indexB++)
        {
            if(dpTable[indexB].totalCoins > (dpTable[indexB - Coins[indexA]].totalCoins + 1))
            {
                //Basic Logic: min(dpTable[index], dpTable[index - coin[i]] + 1)
                dpTable[indexB].totalCoins = dpTable[indexB - Coins[indexA]].totalCoins + 1;
                
                //taking pre-loaded coins to generate remained amount:
                dpTable[indexB].takenCoins = dpTable[indexB - Coins[indexA]].takenCoins;
                
                //taking the new coin:
                dpTable[indexB].takenCoins.push_back(Coins[indexA]);
            }
        }
    }

    if(dpTable[amount].totalCoins == 1e9)
    {
        cout << "No Combination Found";
        return dpTable[amount];
    }
    else
    {
        return dpTable[amount];
    }

}

int main()
{
    int numberofCoins, amount;
    cin >> numberofCoins >> amount;

    vector<int>Coins(numberofCoins);
    for(int index = 0; index < numberofCoins; index++)
    {
        cin >> Coins[index];
    }

    info checkCoins = calcCoins (numberofCoins, amount, Coins);
    cout << checkCoins.totalCoins << endl;
    for(int x : checkCoins.takenCoins)
    {
        cout << x << " ";
    }

    return 0;
}