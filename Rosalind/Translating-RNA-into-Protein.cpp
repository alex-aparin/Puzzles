#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;
const static map<string, char> protein_map =
    {
        {"UUU", 'F'},      {"CUU", 'L'},      {"AUU", 'I'},      {"GUU", 'V'},
        {"UUC", 'F'},      {"CUC", 'L'},      {"AUC", 'I'},      {"GUC", 'V'},
        {"UUA", 'L'},      {"CUA", 'L'},      {"AUA", 'I'},      {"GUA", 'V'},
        {"UUG", 'L'},      {"CUG", 'L'},      {"AUG", 'M'},      {"GUG", 'V'},
        {"UCU", 'S'},      {"CCU", 'P'},      {"ACU", 'T'},      {"GCU", 'A'},
        {"UCC", 'S'},      {"CCC", 'P'},      {"ACC", 'T'},      {"GCC", 'A'},
        {"UCA", 'S'},      {"CCA", 'P'},      {"ACA", 'T'},      {"GCA", 'A'},
        {"UCG", 'S'},      {"CCG", 'P'},      {"ACG", 'T'},      {"GCG", 'A'},
        {"UAU", 'Y'},      {"CAU", 'H'},      {"AAU", 'N'},      {"GAU", 'D'},
        {"UAC", 'Y'},      {"CAC", 'H'},      {"AAC", 'N'},      {"GAC", 'D'},
                           {"CAA", 'Q'},      {"AAA", 'K'},      {"GAA", 'E'},
                           {"CAG", 'Q'},      {"AAG", 'K'},      {"GAG", 'E'},
        {"UGU", 'C'},      {"CGU", 'R'},      {"AGU", 'S'},      {"GGU", 'G'},
        {"UGC", 'C'},      {"CGC", 'R'},      {"AGC", 'S'},      {"GGC", 'G'},
                           {"CGA", 'R'},      {"AGA", 'R'},      {"GGA", 'G'},
        {"UGG", 'W'},      {"CGG", 'R'},      {"AGG", 'R'},      {"GGG", 'G'}
    };

int main()
{
    string rna_str;
    {
        ifstream myfile("./rosalind_prot.txt");
        if (!myfile.is_open())
            return 1;
        getline(myfile, rna_str);
        myfile.close();
    }
    for (size_t i = 0; i < rna_str.size(); i += 3)
    {
        map<string, char>::const_iterator loc = protein_map.find(rna_str.substr(i, 3));
        if (loc != protein_map.end())
            cout << loc->second;
    }

    return 0;
}
