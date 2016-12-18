#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

struct Registers
{	
public: 
	Registers(int a, int b, int c, int d):
		m_registers({a, b, c, d})
	{
	}
	int get_register(const int index) const
	{
	    return m_registers[index];
	}
	void set_register(const int index, const int val)
	{
	    m_registers[index] = val;
	}
private:
    vector<int> m_registers;
};

typedef vector<function<int(void)>> instructions_type;
typedef function<int(void)> getter_type;
typedef function<void(const int)> setter_type;

getter_type build_get(Registers& regs, const string& param)
{
    if (param.find_first_of("abcd") != string::npos)
        return bind(&Registers::get_register, &regs, param[0] - 'a');
    int num = stoi(param);
	return [=](){return num;};
}

setter_type build_set(Registers& regs, const string& param)
{
    if (param.find_first_of("abcd") != string::npos)
        return bind(&Registers::set_register, &regs, param[0] - 'a', placeholders::_1);
	throw runtime_error("unknown set");
}

instructions_type intr_builder(Registers& regs, const vector<vector<string>>& text_instrs)
{
	instructions_type instrs;
	instrs.reserve(text_instrs.size());
	for (size_t i = 0; i < text_instrs.size(); ++i)
	{
		const vector<string>& params = text_instrs[i];
		if (params[0] == "MOV")
		{
			setter_type setter = build_set(regs, params[1]);
			getter_type getter = build_get(regs, params[2]);
			instrs.push_back(
				[=]()
				{
					setter(getter());
					return 1;
				});
		}
		if (params[0] == "ADD")
		{
			setter_type setter = build_set(regs, params[1]);
			getter_type getter = build_get(regs, params[2]);
			getter_type getter2 = build_get(regs, params[3]);
			instrs.push_back(
				[=]()
				{
					setter(getter() + getter2());
					return 1;
				});
		}
		if (params[0] == "SUB")
		{
			setter_type setter = build_set(regs, params[1]);
			getter_type getter = build_get(regs, params[2]);
			getter_type getter2 = build_get(regs, params[3]);
			instrs.push_back(
				[=]()
				{
					setter(getter() - getter2());
					return 1;
				});
		}
		if (params[0] == "JNE")
		{
			getter_type getter = build_get(regs, params[1]);
			getter_type getter2 = build_get(regs, params[2]);
			getter_type getter3 = build_get(regs, params[3]);
			instrs.push_back(
				[=]()
				{
					return getter2() == getter3() ? 1 : getter() - i;
				});
		}
	}
	return instrs;
}

vector<string> split(const string& s, char delim) 
{ 
    stringstream ss;
    ss.str(s);
    vector<string> elems;
    string item;
    while (getline(ss, item, delim)) 
        elems.push_back(item);
    return elems;
}


int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d; cin.ignore();
    int n;
    cin >> n; cin.ignore();
	vector<vector<string>> text_commands;
	text_commands.reserve(n);
    for (int i = 0; i < n; i++) 
    {
        string instruction;
        getline(cin, instruction);
		text_commands.push_back(split(instruction, ' '));
    }
    Registers regs(a, b, c, d);
	const instructions_type& instrs = intr_builder(regs, text_commands);
	for (int instr_ = 0; instr_ < instrs.size(); instr_ += instrs[instr_]())
		;
	for (int i = 0; i < 4; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << regs.get_register(i);
    }      
}