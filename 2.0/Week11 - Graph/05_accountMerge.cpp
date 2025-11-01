#include <bits/stdc++.h>
using namespace std;

// DFS function to explore connected emails
void dfs(const string &email, unordered_map<string, vector<string>> &graph,
         unordered_set<string> &visited, vector<string> &component)
{
    visited.insert(email);
    component.push_back(email);
    for (auto &neighbor : graph[email])
    {
        if (!visited.count(neighbor))
        {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main()
{
    // Hardcoded input for accounts
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};

    unordered_map<string, string> emailToName;
    unordered_map<string, vector<string>> graph;

    // Step 1: Build the graph
    for (auto &acc : accounts)
    {
        string name = acc[0];
        for (int i = 1; i < acc.size(); i++)
        {
            emailToName[acc[i]] = name;
            if (i == 1) // no previous email to connect to, so we skip connecting it.
                continue;
            // Connect current email with previous email making Graph
            graph[acc[i]].push_back(acc[i - 1]);
            graph[acc[i - 1]].push_back(acc[i]);
        }
    }

    // Step 2: DFS to find connected components
    unordered_set<string> visited;
    vector<vector<string>> mergedAccounts;

    for (auto it = emailToName.begin(); it != emailToName.end(); ++it)
    {
        string email = it->first;
        string name = it->second;

        if (!visited.count(email))
        {
            vector<string> component;
            dfs(email, graph, visited, component);
            sort(component.begin(), component.end());
            component.insert(component.begin(), name);
            mergedAccounts.push_back(component);
        }
    }

    // Print the merged accounts
    for (auto &acc : mergedAccounts)
    {
        for (auto &s : acc)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
