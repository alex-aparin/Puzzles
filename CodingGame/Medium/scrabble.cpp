#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const static int max_letter_cost = 10;
static int max_word_length = 0;

class Letter
{
public:
	Letter() {}
	Letter(const int cost) : 
		letter_cost(cost), occurence(0), query_id(0), current_occurence(0)
	{
	}
	void reached()
	{
		++occurence;
	}
	int get_cost(const int qr_id)
	{
		if (qr_id != query_id)
		{
			query_id = qr_id;
			current_occurence = occurence;
		}
		if (current_occurence == 0)
			return -max_letter_cost * max_word_length;
		--current_occurence;
		return letter_cost;
	}

private:
	int letter_cost;
	int occurence;

	int query_id;
	int current_occurence;
};

typedef array<Letter, 26> pattern_type;

static pattern_type pattern = 
{
	Letter(1),	//	a
	Letter(3),	//	b
	Letter(3),	//	c
	Letter(2),	//	d
	Letter(1),	//	e
	Letter(4),	//	f
	Letter(2),	//	g
	Letter(4),	//	h
	Letter(1),	//	i
	Letter(8),	//	j
	Letter(5),	//	k
	Letter(1),	//	l
	Letter(3),	//	m
	Letter(1),	//	n
	Letter(1),	//	o
	Letter(3),	//	p
	Letter(10),	//	q
	Letter(1),	//	r
	Letter(1),	//	s
	Letter(1),	//	t
	Letter(1),	//	u
	Letter(4),	//	v
	Letter(4),	//	w
	Letter(8),	//	x
	Letter(4),	//	y
	Letter(10),	//	z
};

int main()
{
	int N;
	cin >> N; cin.ignore();
	int index = 0;
	int max_cost = -10;
	vector<string> words(N, string());
	for (int i = 0; i < N; ++i)
	{
		getline(cin, words[i]);
		max_word_length = max<int>(max_word_length, words[i].size());
	}
	string LETTERS;
	getline(cin, LETTERS);
	for (int i = 0; i < LETTERS.size(); ++i)
		pattern[LETTERS[i] - 'a'].reached();

	for (int i = 0, query_id = 1; i < words.size(); ++i, ++query_id)
	{
		int current_cost = 0;
		for (int j = 0; 0 <= current_cost && j < words[i].size(); ++j)
			current_cost += pattern[words[i][j] - 'a'].get_cost(query_id);
		if (max_cost < current_cost)
		{
			index = i;
			max_cost = current_cost;
		}
	}
	cout << words[index] << endl;
}
