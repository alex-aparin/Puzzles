#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long num_type;

typedef map<num_type, num_type> trans_type;
typedef vector<pair<num_type, num_type>> factors_type;

factors_type factorize(num_type number)
{
    factors_type factorization;
    while (number > 1)
    {
        for (num_type den = 2; den <= number; ++den)
        {
            if (number % den == 0)
            {
                if (!factorization.empty() && factorization.back().first == den)
                    factorization.back().second++;
                else
                    factorization.push_back(make_pair(den, 1));
                number /= den;
                break;
            }
        }
    }
    sort(factorization.begin(), factorization.end(), 
        [](pair<num_type, num_type> lhs, pair<num_type, num_type> rhs)
        {
            if (lhs.second == rhs.second)
                return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        });
    return factorization;
}

int main()
{
    trans_type transformation;
    num_type X;
    cin >> X; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    for (int i = 0; i < C; ++i) 
    {
        num_type Ai;
        num_type Bi;
        cin >> Ai >> Bi; cin.ignore();
        factors_type factors1 = factorize(Ai);
        factors_type factors2 = factorize(Bi);
        for (int k = 0; k < factors1.size(); ++k)
        {
            if (transformation.find(factors1[k].first) == transformation.end())
                transformation.insert(make_pair(factors1[k].first, factors2[k].first));    
        }
    }
    factors_type factors = factorize(X);
    transform(factors.begin(), factors.end(), factors.begin(), 
        [&transformation](const pair<num_type, num_type> num)
        {   
            return make_pair(transformation[num.first], num.second);
        ;});
    num_type res = 1;
    for_each(factors.begin(), factors.end(), 
        [&res](pair<num_type, num_type> num)
        { 
            for (num_type index = 1; index <= num.second; ++ index)
                res *= num.first;
        ;});
    cout << res << endl;
}
