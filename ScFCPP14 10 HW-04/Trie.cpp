#include "Trie.h"


TrieNode* getNewNode() {
	struct TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < A_Z; i++)	pNode->children[i] = nullptr;
	return pNode;
}

void insert(TrieNode* root, string key) {
	TrieNode* node = root;
	for (char c : key) {
		int i = toI(c);
		if (!node->children[i])
			node->children[i] = getNewNode();
		node = node->children[i];
	}
	node->isEndOfWord = true;
}


bool isLeaf(TrieNode* node) {
	return childrenQtty(node) == 0;
}

void fillDictionary(TrieNode* root) {
	string words[] = { "and", "bonfire", "bool", "case", "catch", "char","action", "amorous", "bird", "cherry", "kind", "king", "cat" ,"car", "card", "carrot" };
	for (auto w : words) {
		insert(root, w);
	}
	//you may add more words to the imbedded dictionary this way
	//string words1[] = { "zebra", "dog", "duck", "dove", "dot" };
	//for (auto w : words1) {
	//	insert(root, w);
	//}
}

// list imbedded dictionary started from prefix in alphabetical order
void alphabetPrint(TrieNode* node, string prefix) {
	static char buf[20];
	static int index = 0;
	TrieNode* n = node;
	for (int i = 0; i < A_Z; i++) {
		if (n->children[i]) {
			buf[index++] = toC(i);
			if (n->children[i]->isEndOfWord) {
				cout << endl << prefix;
				for (int j = 0; j < index; j++)
					cout << buf[j];
			}
			alphabetPrint(n->children[i], prefix);
			index--;
		}
	}
}

int toI(char c) {
	if (c >= 'A' && c <= 'Z') return (int)c - (int)'A';
	if (c >= 'a' && c <= 'z') return (int)c - (int)'a';
	return 0;
}

char toC(int n) {
	return (char)'a' + n;
}


int childrenQtty(TrieNode* node) {
	int qtty = 0;
	for (int j = 0; j < A_Z; j++)
		if (node->children[j]) qtty++;
	return qtty;
}


bool isAlphbetical(string str) {
	for (char c : str) {
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
	}
	return true;
}

void showPrompt() {
	cout << "List the whole dictionary: Enter\nStart new search: letters Enter.\nContinue current search: + Enter letters Enter.\nShow prompt: ?\nExit: -\n\n";
}

// add new word from the console if you want
void wannaAddWord(TrieNode* root, string word) {
	cout << "Wanna add this word to dictionary? (yes: +    no: anything else)";
	string c;
	getline(cin, c);
	if (c == "+") {
		insert(root, word);
		cout << "Added\n\n";
	}
	else cout << "Not added\n\n";
}

// list options started with the key and if there is no such word - add it if you want
void showOptions(TrieNode* root, string key) {
	TrieNode* n = root;
	for (char c : key) {
		if (n->children[toI(c)]) {
			n = n->children[toI(c)];
		}
		else {
			cout << "No matching options.\n\n";
			if (isAlphbetical(key)) {
				wannaAddWord(root, key);
				return;
			}
		}
	}
	if (isLeaf(n)) cout << endl << key;
	alphabetPrint(n, key);
	cout << endl << endl;
	if (key != "" && !n->isEndOfWord) {
		wannaAddWord(root, key);
	}
}

