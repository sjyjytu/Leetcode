#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> nums;
        vector<char> alphas;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]>='a'&&s[i]<='z')
            {
                alphas.push_back(s[i]);
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                nums.push_back(s[i]);
            }
        }
        int an = alphas.size() - nums.size();
        if (abs(an)>1)
        {
            return "";
        }
        string result="";
        if (an>=0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                result += alphas[i];
                result += nums[i];
            }
            if (an!=0)
            {
                result += alphas[alphas.size() - 1];
            }
        }
        else
        {
            for (int i = 0; i < alphas.size(); i++)
            {
                result += nums[i];
                result += alphas[i];
            }
            result += nums[nums.size() - 1];
        }
        return result;
    }

    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, vector<int>>tbl2foodNums;
        map<string, int> menu;
        vector<string> dish_names;
        int dishes_num = 0;
        for (int i = 0; i < orders.size(); i++)
        {
            int tbln = stoi(orders[i][1]);
            string dish = orders[i][2];
            if (menu.count(dish)==0)
            {
                menu[dish] = dishes_num++;
                dish_names.push_back(dish);
            }
            auto it = tbl2foodNums.find(tbln);
            int dish_idx = menu[dish];
            if (it==tbl2foodNums.end())
            {
                tbl2foodNums[tbln] = vector<int>(dishes_num, 0);
                tbl2foodNums[tbln][dish_idx]++;
            }
            else
            {
                if (dish_idx>=it->second.size())
                {
                    for (int j = it->second.size(); j < dishes_num; j++)
                    {
                        it->second.push_back(0);
                    }
                }
                it->second[dish_idx]++;
            }
        }
        vector<vector<string>> result;
        vector<string> first_row;
        first_row.push_back("Table");
        for (auto it = menu.begin(); it!=menu.end(); it++)
        {
            first_row.push_back(it->first);
        }
        result.push_back(first_row);
        for (auto it = tbl2foodNums.begin(); it != tbl2foodNums.end(); it++)
        {
            vector<string> row(dishes_num+1,"0");
            stringstream ss;
            ss << it->first;
            string tbln;
            ss >> tbln;
            row[0] = tbln;
            for (int i = 0; i < it->second.size(); i++)
            {
                ss.clear();
                ss << it->second[i];
                string num;
                ss >> num;
                int idx = distance(menu.begin(), menu.find(dish_names[i]));
                row[idx + 1] = num;
            }
            result.push_back(row);
        }
        return result;
    }

    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> frogs(5, 0);  //5种状态的青蛙的数量
        unordered_map<char, int> croak2idx;
        croak2idx['k'] = 0;
        croak2idx['c'] = 1;
        croak2idx['r'] = 2;
        croak2idx['o'] = 3;
        croak2idx['a'] = 4;
        for (int i = 0; i < croakOfFrogs.size(); i++)
        {
            int idx = (croak2idx[croakOfFrogs[i]] - 1 + 5) % 5;
            if (frogs[idx]<=0)
            {
                if (idx==0)
                {
                    frogs[1]++;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                frogs[idx]--;
                frogs[(idx + 1) % 5]++;
            }
        }
        for (int i = 1; i < 5; i++)
        {
            if (frogs[i]!=0)
            {
                return -1;
            }
        }
        return frogs[0];
    }

    int numOfArrays(int n, int m, int k) {
#define modular 1000000007
        // a[k-1]>a[k-2-i], arr[k-1]>=arr[k+i],
        //放了i，那么前k-1位共有(i-1)^k-1种可能，后n-k-1位共有(m-i+1)^(n-k-1)种可能
        long sum = 0;
        for (int i = 1; i <= m; i++)
        {
            long placeitok = long(pow(i - 1, k - 1) * pow(m - i + 1, n - k)) % modular;
            sum += placeitok;
            sum %= modular;
        }
        return sum;
    }
};