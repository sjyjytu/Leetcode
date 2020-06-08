#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>>sons(n, unordered_set<int>());
        vector<unordered_set<int>>pars(n, unordered_set<int>());
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int par = prerequisites[i][0];
            int son = prerequisites[i][1];
            sons[par].insert(son);
            for (auto it = pars[par].begin(); it != pars[par].end(); it++)
            {
                sons[*it].insert(son);
            }
            for (auto it = sons[son].begin(); it != sons[son].end(); it++)
            {
                sons[par].insert(*it);
                for (auto it2 = pars[par].begin(); it2 != pars[par].end(); it2++)
                {
                    sons[*it2].insert(*it);
                }
            }
            
            pars[son].insert(par);
            for (auto it = sons[son].begin(); it != sons[son].end(); it++)
            {
                pars[*it].insert(par);
            }
            for (auto it = pars[par].begin(); it != pars[par].end(); it++)
            {
                pars[son].insert(*it);
                for (auto it2 = sons[son].begin(); it2 != sons[son].end(); it2++)
                {
                    pars[*it2].insert(*it);
                }
            }
        }
        vector<bool> res;
        for (int i = 0; i < queries.size(); i++)
        {
            if (sons[queries[i][0]].find(queries[i][1])!= sons[queries[i][0]].end())
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};