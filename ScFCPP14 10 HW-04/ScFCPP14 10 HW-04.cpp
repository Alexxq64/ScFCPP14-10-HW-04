
#include "Trie.h"

int main()
{
	TrieNode* root = new TrieNode();
	fillDictionary(root);
	cout << "\nThe program offers suitable extensions from the imbedded dictonary.\nIf there no such word you may add it.\n\n";
	showPrompt();
	string input;
	string word = "";
	bool extend = false;

	while (true) {
		getline(cin, input);
		if (input == "-") return 0;
		if (input == "+") {
			extend = true;
			cout << "Add more letters to:   " << word;
			continue;
		}
		if (input == "?") {
			showPrompt();
			continue;
		}
		if (isAlphbetical(input)) {
			word = (extend) ? word + input : input;
			extend = false;
			showOptions(root, word);
		}
		else cout << "Wrong input. Try again.\n";
	}


}

