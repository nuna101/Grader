#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> tmp;
    size_t allSize = a.size();
    for(int i = 0; i < allSize; ++i) {
        std::vector<std::queue<int>> &v = a.top();
        for(int j = 0; j < v.size(); ++j) {
            std::queue<int> &q = v[j];
            for(int k = 0; k < q.size(); ++k) {
                if(q.front() == from) q.push(to);
                else q.push(q.front());
                q.pop();
            }
        }
        tmp.push(v);
        a.pop();
    }
    for(int i = 0; i < allSize; ++i) {
        a.push(tmp.top());
        tmp.pop();
    }
    // your code here
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    size_t allSize = a.size();
    for(auto mapIt = a.begin(); mapIt != a.end(); ++mapIt) {
        std::pair<std::priority_queue<int>, int> &p = (*mapIt).second;
        std::priority_queue<int> &pq = p.first;
        std::priority_queue<int> tmp;
        while(!pq.empty()) {
            if(pq.top() == from) tmp.push(to);
            else tmp.push(pq.top());
            pq.pop();
        }
        while(!tmp.empty()) {
            pq.push(tmp.top());
            tmp.pop();
        }
        if(p.second == from) p.second = to;
    }
    // your code here
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{   
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, std::string>>>> updatedSet;
    for(auto s : a) {
        std::pair<std::list<int>, std::map<int, std::pair<int, string>>> p = s;
        std::list<int> &l = p.first; 
        for(auto &listIt : l) {
            if(listIt == from) listIt = to;
        }
        std::map<int, std::pair<int, string>> &m = p.second;
        for(auto &mapIt : m) {
            std::pair<int,string> &mp = mapIt.second;
            if(mp.first == from) mp.first = to;
            if(mapIt.first == from) {
                auto newMp = mp;
                m.erase(from);
                m[to] = newMp;
            }
        }
        updatedSet.insert(p);
    }
    a.swap(updatedSet);
}

#endif
