#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef double real;

const real MY_PI = 3.1415926535897932384626433832795;

real str_to_float( const string &float_number )
{
    real result = 0;
    real factor = 1.0;
    for ( int i = 0; i < float_number.size(); ++i)
    {
        int num = float_number[i] - '0';
        if ( float_number[i] == ',' )
        {
            factor = 0.1;
            continue;
        }
        if ( factor >= 1.0 )
        {
            result = result * factor + num;
            factor *= 10;
        }
        else
        {
            result = result + factor * num;
            factor /= 10;
        }
    }
    return result;
}

struct Defiblirator
{
    int m_def_id;
    string m_name;
    string m_address;
    string m_phone_number;
    real m_longtitude;
    real m_latitude;
};

struct DefibliratorOrder
{
    real m_longtitude;
    real m_latitude;
    real distance( real longtitude, real latitude ) const
    {
        const real x = ( m_longtitude - longtitude ) * cos( ( m_latitude + latitude) / 2.0 );
        const real y = m_latitude - latitude;
        const real d = sqrt(x*x+y*y)*6371;
        return d;
    }
    bool operator()( const Defiblirator& lhs, const Defiblirator& rhs ) const
    {
        return ( distance(lhs.m_longtitude, lhs.m_latitude) < distance(rhs.m_longtitude, rhs.m_latitude) );
    }
};

Defiblirator parseStringDef( const string& str_def )
{
    Defiblirator result;
    string parse_str;
    int i = 0;
    //  ID PARSING
    for (;(i < str_def.size()) && (str_def[i] != ';'); ++i)
        parse_str.push_back(str_def[i]);
    //cerr << "DEF ID : " << parse_str << endl;
    result.m_def_id = std::stoi( parse_str );
    parse_str.clear();
    //  NAME PARSING
    for (++i;(i < str_def.size()) && (str_def[i] != ';'); ++i)
        parse_str.push_back(str_def[i]);
    //cerr << "DEF NAME : " << parse_str << endl;
    result.m_name = parse_str;
    parse_str.clear();
    //  ADRESS PARSING
    for (++i;i < str_def.size() && str_def[i] != ';'; ++i)
        parse_str.push_back(str_def[i]);
    result.m_address = parse_str;
    parse_str.clear();
    //  CONTACT PHONE PARSING
    for (++i;i < str_def.size() && str_def[i] != ';'; ++i)
        parse_str.push_back(str_def[i]);
    result.m_phone_number = parse_str;
    parse_str.clear();
    //  LONGTITUDE PARSING
    for (++i;i < str_def.size() && str_def[i] != ';'; ++i)
        parse_str.push_back(str_def[i]);
    //cerr << "LON (str): " << parse_str << endl;
    //cerr << "LON : " << str_to_float(parse_str) << endl;
    result.m_longtitude = MY_PI * str_to_float(parse_str) / 180.0;
    parse_str.clear();
    //  LATITUDE PARSING
    for (++i;i < str_def.size() && str_def[i] != ';'; ++i)
        parse_str.push_back(str_def[i]);
    //cerr << "LAT (str): " << parse_str << endl;
    //cerr << "LAT : " << str_to_float(parse_str) << endl;
    result.m_latitude = MY_PI * str_to_float(parse_str) / 180.0;
    parse_str.clear();
    
    return result;
}

typedef std::vector<Defiblirator> def_types;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    def_types defs;
    DefibliratorOrder defs_order;
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    defs_order.m_longtitude = MY_PI * str_to_float(LON) / 180.0;
    defs_order.m_latitude = MY_PI * str_to_float(LAT) / 180.0;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        defs.push_back( parseStringDef( DEFIB ) );
    }
    cout << std::min_element( defs.begin(), defs.end(), defs_order )->m_name << endl;
    /*
    std::sort( defs.begin(), defs.end(), defs_order );
    for ( size_t i = 0; i < defs.size(); ++i)
        cerr << defs[i].m_name << endl;
    real nearest_distance = defs_order.distance( defs[0].m_longtitude, defs[0].m_latitude );
    cerr << "Nearest distance : " << nearest_distance << endl;
    for ( size_t i = 0; i < defs.size(); ++i)
    {
        real distance = defs_order.distance( defs[i].m_longtitude, defs[i].m_latitude );
        //cerr << "distance : " << distance << endl;
        if ( nearest_distance < distance )
            break;
        //cout << defs[i].m_name << endl;
        break;
    }
    */
}
