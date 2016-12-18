#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;

// Classes	
typedef vector<tuple<double, double>> table_type;
typedef vector<tuple<string, function<double(const double)>>> funcs_type;
typedef vector<double> err_types;

constexpr int X = 0;
constexpr int Y = 1;

template <int Axe, int Degree>
double M(const table_type& table)
{
    double res = 0.0;
    for (int i = 0; i < table.size(); ++i)
        res += pow(get<Axe>(table[i]), Degree);
    res /= table.size();
    return res;
}

template <int XDegree, int YDegree>
double MXY(const table_type& table)
{
    double res = 0.0;
    for (int i = 0; i < table.size(); ++i)
        res += pow(get<0>(table[i]), XDegree) * pow(get<1>(table[i]), YDegree);
    res /= table.size();
    return res;
}

template <int XDegree, int LogDegree, int YDegree>
double MXLOGY(const table_type& table)
{
    double res = 0.0;
    for (int i = 0; i < table.size(); ++i)
    {
        const double x = pow(get<0>(table[i]), XDegree);
        const double log_k = pow(log(get<0>(table[i])), LogDegree);
        const double y = pow(get<1>(table[i]), YDegree);
        res +=  x * log_k * y;
    }
    res /= table.size();
    return res;
}

template <int XDegree, int YDegree>
double MPow(const table_type& table)
{
    double res = 0.0;
    for (int i = 0; i < table.size(); ++i)
    {
        const double x = pow(2, XDegree * get<0>(table[i]));
        const double y = pow(get<1>(table[i]), YDegree);
        res +=  x * y;
    }
    res /= table.size();
    return res;
}

vector<double> solve_system(const vector<vector<double>>& system)
{
	double d = system[0][0] * system[1][1] - system[0][1] * system[1][0];
	double d1 = (system[0][2] * system[1][1] - system[1][2] * system[0][1]) / d;
	double d2 = (system[0][0] * system[1][2] - system[1][0] * system[0][2]) / d;
	return {d1, d2};
}

template <int K>
vector<double> poly_coefs(const table_type& table)
{
	return solve_system(
	{
		{M<X, 2 * K>(table), M<X, K>(table), MXY<K, 1>(table)},
		{M<X, K>(table), 	 1, 			 M<Y, 1>(table)}
	});
}

template <int K>
vector<double> log_coefs(const table_type& table)
{
	return solve_system(
	{
		{MXLOGY<2*K,2,0>(table), MXLOGY<K,1,0>(table), MXLOGY<K,1,1>(table)},
		{MXLOGY<K,1,0>(table), 	 1, 			 M<Y, 1>(table)}
	});
}

template <int K>
vector<double> pow_coefs(const table_type& table)
{
	return solve_system(
	{
		{MPow<2*K,0>(table), MPow<K,0>(table), MPow<K,1>(table)},
		{MPow<K,0>(table), 	 1, 			 M<Y, 1>(table)}
	});
}

double compute_error(const table_type& table, const function<double(const double)>& func)
{
	double res = 0.0;
	for (size_t i = 0; i < table.size(); ++i)
		res += pow(func(get<0>(table[i])) - get<1>(table[i]), 2.0);
	return sqrt(res);
}

//	Regression funcs
function<double(const double)> func_1(const table_type& table)
{
    const double aver_y = M<Y, 1>(table);
	return [=](const double){ return aver_y;};
}

function<double(const double)> func_n(const table_type& table)
{
	const vector<double> cs = poly_coefs<1>(table); 		
	return [=](const double x){ return cs[0] * x + cs[1];};
}

function<double(const double)> func_log_n(const table_type& table)
{
	const vector<double> cs = log_coefs<0>(table); 		
	return [=](const double x)
	{ 
	    return cs[0] * log(x)+ cs[1];
    };
}

function<double(const double)> func_n_log_n(const table_type& table)
{
	const vector<double> cs = log_coefs<1>(table); 		
	return [=](const double x)
	{ 
	    return cs[0] * x * log(x)+ cs[1];
    };
}

function<double(const double)> func_n_2(const table_type& table)
{
	const vector<double> cs = poly_coefs<2>(table); 		
	return [=](const double x){ return cs[0] * x * x + cs[1];};
}

function<double(const double)> func_n_2_log_n(const table_type& table)
{
	const vector<double> cs = log_coefs<2>(table); 		
	return [=](const double x)
	{ 
	    return cs[0] * x * x * log(x)+ cs[1];
    };
}

function<double(const double)> func_n_3(const table_type& table)
{
	const vector<double> cs = poly_coefs<3>(table); 		
	return [=](const double x){ return cs[0] * x * x * x + cs[1];};
}

function<double(const double)> func_2_n(const table_type& table)
{
	const vector<double> cs = pow_coefs<1>(table); 		
	return [=](const double x)
	{ 
	    return cs[0] * pow(2, x)+ cs[1];
    };
}

int main()
{	
	table_type table;
	
    int N;
    cin >> N; cin.ignore();
	
	table.reserve(N);
    for (int i = 0; i < N; ++i) 
	{
        double num;
        double t;
        cin >> num >> t; cin.ignore();
		table.push_back(make_tuple(num, t));
    }
	
    const funcs_type& funcs = 
	{
		make_tuple("O(1)", func_1(table)),
		make_tuple("O(n)", func_n(table)),
		make_tuple("O(log n)", func_log_n(table)),
		make_tuple("O(n log n)", func_n_log_n(table)),
		make_tuple("O(n^2)", func_n_2(table)),
		make_tuple("O(n^2 log n)", func_n_2_log_n(table)),
		make_tuple("O(n^3)", func_n_3(table)),
		make_tuple("O(2^n)", func_2_n(table))
	};
	
	err_types errors(funcs.size(), numeric_limits<double>::max());
	for (size_t i = 0; i < errors.size(); ++i)
		errors[i] = compute_error(table, get<1>(funcs[i]));
	
	cout << get<0>(funcs[min_element(errors.begin(), errors.end()) - errors.begin()]) << endl;
	return 0;
}