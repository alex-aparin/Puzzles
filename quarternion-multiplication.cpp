#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Vector3D
{
    Vector3D(const int a, const int b, const int c)
    {
        m_nums[0] = a;
        m_nums[1] = b;
        m_nums[2] = c;
    }
    int dot_product(const Vector3D& rhs) const
    {
        int res = 0;
        for (int i = 0; i < 3; ++i)
            res += m_nums[i] * rhs.m_nums[i];
        return res;
    }
    Vector3D factor(const int a) const
    {
        return Vector3D(m_nums[0] * a, m_nums[1] * a, m_nums[2] * a);
    }
    Vector3D vec_product(const Vector3D& rhs) const
    {
        return Vector3D(m_nums[1] * rhs.m_nums[2] - m_nums[2] * rhs.m_nums[1],
                        m_nums[2] * rhs.m_nums[0] - m_nums[0] * rhs.m_nums[2],
                        m_nums[0] * rhs.m_nums[1] - m_nums[1] * rhs.m_nums[0]);
    }
    friend Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
    {
        return Vector3D(lhs.m_nums[0] + rhs.m_nums[0], lhs.m_nums[1] + rhs.m_nums[1], lhs.m_nums[2] + rhs.m_nums[2]);
    }
    int m_nums[3];
};

struct Quatr
{
    Quatr(const int a, const Vector3D unit) : 
        m_a(a), m_unit(unit)
    {
    }
    Quatr product(const Quatr& rhs) const
    {
        return Quatr(m_a * rhs.m_a - m_unit.dot_product(rhs.m_unit), 
                     rhs.m_unit.factor(m_a) + m_unit.factor(rhs.m_a) + m_unit.vec_product(rhs.m_unit));
    }
    void print_component(const int index, bool& print_plus) const
    {
        const int t = m_unit.m_nums[index];
        if (t != 0)
        {
            if (print_plus && t > 0)
                cout << '+';
            if (t * t == 1)
            {
                if (t <0)
                    cout << '-';
            }
            else 
                cout << t;
            const char c = index == 0 ? 'i' : (index == 1 ? 'j' : 'k');
            cout << c;
            print_plus = true;
        }
        
    }
    void print(void) const
    {
        bool print_pos = false;
        for (int i = 0; i < 3; ++i)
            print_component(i, print_pos);
        if (m_a != 0)
        {
            if (print_pos && 0 < m_a)
                cout << '+';
            cout << m_a;
        }
    }
    int m_a;
    Vector3D m_unit;
};

Quatr parse_quatr(const string& str, int& pos)
{
    int nums[4] = {0};
    int* num_ptr = &nums[3];
    int factor = 1;
    int temp = 0;
    for (++pos; str[pos - 1] != ')'; ++pos)
    {
        if (str[pos] == '+' || str[pos] == '-' || str[pos] == ')')
        {
            *num_ptr = factor * temp;
            factor = str[pos] == '-' ? -1 : 1;
            temp = 0;
            continue;
        }
        if ('0' <= str[pos] && str[pos] <= '9')
        {
            num_ptr = &nums[3];
            temp = temp * 10 + str[pos] - '0';
            continue;
        }
        if (str[pos] == 'i')
            num_ptr = &nums[0];
        if (str[pos] == 'j')
            num_ptr = &nums[1];
        if (str[pos] == 'k')
            num_ptr = &nums[2];
        if (str[pos - 1] == '-' || str[pos - 1] == '+' || str[pos - 1] == '(')
            temp = 1;
    }
    return Quatr(nums[3], Vector3D(nums[0], nums[1], nums[2]));
}

int main()
{
    vector<Quatr> quatrs;
    string expr;
    getline(cin, expr);
    for (int i = 0; i < expr.size(); )
        quatrs.push_back(parse_quatr(expr, i));
    Quatr res = quatrs[0];
    for (int i = 1 ;i < quatrs.size(); ++i)
        res = res.product(quatrs[i]);
    res.print();
}
