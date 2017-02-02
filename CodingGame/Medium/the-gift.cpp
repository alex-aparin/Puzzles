#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct OodPresent
{
    
    OodPresent( int i, int budget ) :
        m_i(i), m_budget(budget), m_solution(0)
    {}
    bool operator<(const OodPresent &rhs) const
    {
        return m_budget < rhs.m_budget;
    }
    void printBudget() const
    {
        cout<<m_solution<<endl;
    }
    int m_i;
    int m_budget;
    int m_solution;
};

typedef std::vector<OodPresent> oods_presents_type;

bool fillSolutions(oods_presents_type &oods, int cost_gift )
{
    int cost = cost_gift;
    const int N = oods.size();
    for ( int i = 0; i < N; ++i )
    {
        const int remain_count = N - i;
        const int average = cost / remain_count;
        if ( oods[i].m_budget >= average )
            oods[i].m_solution = average;
        else
            oods[i].m_solution = oods[i].m_budget;
        cost -=  oods[i].m_solution;
    }
    return cost == 0;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    oods_presents_type oods;
    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        cerr << B << endl;
        oods.push_back(OodPresent(i,B));
    }
    cerr << "Computation" << endl;
    sort( oods.begin(), oods.end());
    if ( fillSolutions(oods, C) )
        for ( int i = 0; i < N; ++i )
            oods[i].printBudget();
    else
        cout << "IMPOSSIBLE" << endl;
}
