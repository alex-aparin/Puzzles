#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    typedef int key_type;
    key_type m_key;
    vector<Node*> m_children;
    Node() :
        m_key( 0 ), m_children()
    {}
    void insertNumber( const vector<key_type>& number, const size_t current_index )
    {
        if ( current_index == number.size() )
            return;
        for ( size_t i = 0; i < m_children.size(); ++i )
            if ( m_children[i]->m_key == number[current_index] )
            {
                m_children[i]->insertNumber( number, current_index + 1);
                return;
            }
        Node* child = new Node();
        child->m_key = number[current_index];
        m_children.push_back( child );
        child->insertNumber( number, current_index + 1);
    }
    void setNumberOfChildren( size_t& size_children )
    {
        ++size_children;
        for ( size_t i = 0; i < m_children.size(); ++i )
            m_children[i]->setNumberOfChildren( size_children );
    }
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    Node root;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        vector<Node::key_type> number;
        for ( size_t j = 0; j < telephone.size(); ++j )
            number.push_back( telephone[j] - '0' );
        root.insertNumber( number, 0 );
    }
    size_t count_numbers = 0;
    root.setNumberOfChildren( count_numbers );
    --count_numbers;
    cout << count_numbers << endl; // The number of elements (referencing a number) stored in the structure.
}
