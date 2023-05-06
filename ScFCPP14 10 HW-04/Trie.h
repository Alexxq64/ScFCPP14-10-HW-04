#include <string>
#include <iostream>
const int A_Z = 26;
using namespace std;

struct TrieNode
{
	struct TrieNode* children[A_Z];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
};

TrieNode* getNewNode();
void insert(TrieNode* root, string key);
bool isLeaf(TrieNode* node);

void fillDictionary(TrieNode* root);
void alphabetPrint(TrieNode* root, string prefix);

int childrenQtty(TrieNode* node);

int toI(char c);
char toC(int n);

void showPrompt();
bool isAlphbetical(string str);
void showOptions(TrieNode* root, string key);
