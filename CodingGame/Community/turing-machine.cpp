#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

class TuringMachine
{
	struct State
	{
		int sym;
		char dir;
		std::string next_state;
	};

	typedef std::map<std::string, std::vector<State>> states_type;
public:
	typedef std::vector<int> tape_type;

	TuringMachine(const int symbols_number, const int tape_length, const int initial_pos) :
		m_symbols_number(symbols_number), m_tape(tape_length, 0), m_states(), m_current_position(initial_pos), m_current_state()
	{
	}
	void set_current_state(const std::string& state)
	{
		m_current_state = state;
	}
	void add_state(const std::string& state)
	{
		size_t pos = 0;
		std::vector<State> cur_states_cat;
		cur_states_cat.reserve(m_symbols_number);
		string state_name;
		{
			//    Read state name
			for (; state[pos] != ':'; ++pos)
				state_name.push_back(state[pos]);
		}
		for (int i = 0; i < m_symbols_number; ++i)
		{
			State cur_state;
			cur_state.sym = 0;
			{
				//	Reading symbol
				for (++pos; state[pos] == ' '; ++pos)
					;
				for (; state[pos] != ' '; ++pos)
					cur_state.sym = cur_state.sym * 10 + (state[pos] - '0');
			}
			{
				//	Reading direction
				for (++pos; state[pos] == ' '; ++pos)
					;
				cur_state.dir = state[pos];
			}
			{
				cur_state.next_state.clear();
				//	Reading next state
				for (++pos; state[pos] == ' '; ++pos)
					;
				for (; pos < state.size() && state[pos] != ';'; ++pos)
					cur_state.next_state.push_back(state[pos]);
			}
			cur_states_cat.push_back(cur_state);
		}
		m_states.insert(std::make_pair(state_name, cur_states_cat));
	}
	void make_single_turn(void)
	{
		const State& cur_state = m_states[m_current_state][m_tape[m_current_position]];
		m_tape[m_current_position] = cur_state.sym;
		m_current_position += (cur_state.dir == 'L' ? -1 : 1);
		m_current_state = cur_state.next_state;
	}
	bool is_halt(void) const
	{
		return m_current_state == "HALT" ||
			m_current_position < 0 ||
			m_current_position >= static_cast<int>(m_tape.size());
	}
	int current_pos(void) const
	{
		return m_current_position;
	}
	const tape_type& get_tape(void) const
	{
		return m_tape;
	}
private:
	const int m_symbols_number;
	tape_type m_tape;
	states_type m_states;
	int m_current_position;
	std::string m_current_state;
};

int main()
{
	int S;
	int T;
	int X;
	cin >> S >> T >> X; cin.ignore();
	TuringMachine turing_machine(S, T, X);
	string START;
	getline(cin, START);
	turing_machine.set_current_state(START);
	int N;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		string STATEACTIONS;
		getline(cin, STATEACTIONS);
		turing_machine.add_state(STATEACTIONS);
	}
	int steps = 0;
	while (!turing_machine.is_halt())
	{
		turing_machine.make_single_turn();
		++steps;
	}
	std::cout << steps << std::endl;
	std::cout << turing_machine.current_pos() << std::endl;
	for (const auto& c : turing_machine.get_tape())
		std::cout << c;
	std::cout << std::endl;
}
