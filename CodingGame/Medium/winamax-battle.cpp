#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Card
{
    enum CardValue
    {
        CARD_VALUE_2,
        CARD_VALUE_3, 
        CARD_VALUE_4,
        CARD_VALUE_5, 
        CARD_VALUE_6,
        CARD_VALUE_7,
        CARD_VALUE_8, 
        CARD_VALUE_9,
        CARD_VALUE_10, 
        CARD_VALUE_J,
        CARD_VALUE_Q,
        CARD_VALUE_K, 
        CARD_VALUE_A 
    };
    Card(const string& serialized_card)
    {
        switch (serialized_card[0])
        {
            case '2':
                m_card_value = CARD_VALUE_2;
            break;
            case '3':
                m_card_value = CARD_VALUE_3;
            break;
            case '4':
                m_card_value = CARD_VALUE_4;
            break;
            case '5':
                m_card_value = CARD_VALUE_5;
            break;
            case '6':
                m_card_value = CARD_VALUE_6;
            break;
            case '7':
                m_card_value = CARD_VALUE_7;
            break;
            case '8':
                m_card_value = CARD_VALUE_8;
            break;
            case '9':
                m_card_value = CARD_VALUE_9;
            break;
            case '1':
                m_card_value = CARD_VALUE_10;
            break;
            case 'J':
                m_card_value = CARD_VALUE_J;
            break;
            case 'Q':
                m_card_value = CARD_VALUE_Q;
            break;
            case 'K':
                m_card_value = CARD_VALUE_K;
            break;
            case 'A':
                m_card_value = CARD_VALUE_A;
            break;
            default:
                throw "Unexpected character";
        }
    }
    CardValue m_card_value;
    bool operator<(const Card& other) const
    {
        return m_card_value < other.m_card_value;
    }
    bool operator==(const Card& other) const
    {
        return m_card_value == other.m_card_value;
    }
};

typedef list<Card> cards_type;

bool move_cards(const int cards_count, cards_type& player_deck, cards_type& player_fight_deck)
{
    for (int i = 0; i < cards_count; ++i)
    {
        if (player_deck.empty())
            return false;
        player_fight_deck.push_back(player_deck.front());
		player_deck.pop_front();
    }
    return true;
}

void move_decks(cards_type& player_deck, cards_type& player1_fight_deck,
cards_type& player2_fight_deck)
{
    player1_fight_deck.splice(player1_fight_deck.end(), player2_fight_deck);
    player_deck.splice(player_deck.end(), player1_fight_deck);
}

enum GAME_STATE
{
    FIGHT,
    WAR
};

enum GAME_RESULT
{
    IDLE,
    ONE, 
    SECOND,
    PAT
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	cards_type player1_deck;
	cards_type player2_deck;

    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        player1_deck.push_back(Card(cardp1));
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        player2_deck.push_back(Card(cardp2));
    }
    int rounds_count = 0;
    GAME_STATE game_state = GAME_STATE::FIGHT;
    GAME_RESULT game_result = GAME_RESULT::IDLE;
    cards_type player1_fight_deck;
    cards_type player2_fight_deck;
    for (;game_result == GAME_RESULT::IDLE;)
    {
		if (move_cards(1, player1_deck, player1_fight_deck) == false)
		{
			game_result = GAME_RESULT::SECOND;
			break;
		}
		if (move_cards(1, player2_deck, player2_fight_deck) == false)
		{
			game_result = GAME_RESULT::ONE;
			break;
		}	
        if (player1_fight_deck.back() == player2_fight_deck.back())
        {
            game_state = GAME_STATE::WAR;
            if (move_cards(3, player1_deck, player1_fight_deck) == false || 
				move_cards(3, player2_deck, player2_fight_deck) == false)
			{
				game_result = GAME_RESULT::PAT;
				break;
			}
            continue;
        }
        game_state = GAME_STATE::FIGHT;
        ++rounds_count;
		if (player1_fight_deck.back() < player2_fight_deck.back())
			move_decks(player2_deck, player1_fight_deck, player2_fight_deck);
		else
			move_decks(player1_deck, player1_fight_deck, player2_fight_deck);
    }
    switch (game_result)
    {
        case GAME_RESULT::IDLE:
            cout << "IMPOSSIBLE CASE:))" << endl;
        break;
        case GAME_RESULT::ONE:
            cout << "1 " << rounds_count << endl;
        break;
        case GAME_RESULT::SECOND:
            cout << "2 " << rounds_count << endl;
        break;
        case GAME_RESULT::PAT:
            cout << "PAT" << endl;
        break;
    }
	cin >> rounds_count;
}
