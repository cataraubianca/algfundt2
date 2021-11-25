#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>


using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

#define nmax 50001
const int oo = (1<<30);

class graf{
private:
    int n, m,nod_curent;
    vector<int>distanta;
    vector <bool> InCoada;
    vector <int> vizitate;
    priority_queue<int, vector <int>, compara > pq;
public:
    graf(int n, int m);
    void dijkstra(int nod, vector <pair<int, int>>G[nmax]);
    void afiseaza_dijkstra();
};
};
graf::graf(int n, int m)
{
    this->n=n;
    this->m=m;
}
void graf::dijkstra(int s, vector <pair<int, int>>G[nmax])
{

    for(int i=1;i<=n;i++)
        {distanta[i] = oo;
        vizitate[i]=false;}

    distanta[s] = 0;
    pq.push(s);
    vizitate[s] = true;

    while(!pq.empty()){
        nod_curent=pq.top();
        vizitate[nod_curent]=false;
        pq.pop();

    for(size_t i = 0; i < G[nod_curent].size(); i++)
    {
        int vecin = G[nod_curent][i].first;
        int cost = G[nod_curent][i].second;
        if(distanta[nod_curent] + cost < distanta[vecin])
        {
            distanta[vecin] = distanta[nod_curent] + cost;
            if(!vizitate[vecin])
            {
                pq.push(vecin);
                vizitate[vecin] = true;
            }


        }
    }

}}
void graf::afiseaza_dijkstra(){
    for(int i = 2; i <= n; i++)
        if(distanta[i] != oo)
            g << distanta[i] << " ";
        else
            g <<" 0 "<<" ";
}
int main(){

    int n,m;
    f >> n >> m;
    int start_edge, end_edge, cost;
    vector <pair<int, int>>G[nmax];

    for(int i = 1; i <= m; i++)
    {
        f >> start_edge >> end_edge >> cost;
        G[start_edge].push_back(make_pair(end_edge, cost));
    }

    graf g(n,m);
    g.dijkstra(1, G);
    g.afiseaza_dijkstra();
    return 0;
}
