#include <iostream>
#include <vector>
using namespace std;

int main()
{
        // your code goes here
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
                int value;
                cin >> value;
                arr.push_back(value);
        }

        vector<int> res;

        for (int i = 0; i < n - 1; i++)
        {
                int max_ele = arr[i];
                //     int x = 1;

                for (int j = i + 1; j < n; j++)
                {
                        if (arr[j] > max_ele)
                        {
                                max_ele = arr[j];
                                // res.push_back(max_ele);
                                break;
                        }
                }

                if (max_ele != arr[i])
                {
                        res.push_back(max_ele);
                }
                else
                {
                        res.push_back(-1);
                }
        }
        res.push_back(-1);

        for (int x : res)
        {
                cout << x << " ";
        }
        return 0;
}
