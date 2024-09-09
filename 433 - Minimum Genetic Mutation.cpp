#include <string>       // For std::string
#include <iostream>     // For std::cout, std::cin, etc. (optional in your current code)
#include <vector>       // For std::vector
#include <queue>        // For std::queue
#include <unordered_map> // For std::unordered_map



class Solution {
public:
    // check if a mutation is possible
    bool canMutate(string startGene, string endGene)
    {
        int count = 0;
        for(int i = 0; i < startGene.length(); i++)
        {
            if(startGene[i] != endGene[i])
            {
                count++;
            }
        }
        if(count == 1)
        {
            return true;
        }
        return false;
    }

    unordered_map<string,bool> set;

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        set[startGene] = true;
        int output = 0; // number of mutations
        while(!q.empty())
        {
            int size = q.size();
            // for-loop is used to know if we visited every node in a level
            for(int i = 0; i < size; i++)
            {
                string current = q.front();
                q.pop();
                if(current == endGene)
                {
                    return output;
                }
                //visit every adjacent node
                for(string item:bank)
                {
                    if(canMutate(current, item) && set.find(item) == set.end())
                    {
                        set[item] = true;
                        q.push(item);
                    }
                }

            }
            output++;
        }
        return -1;
        
    }
};