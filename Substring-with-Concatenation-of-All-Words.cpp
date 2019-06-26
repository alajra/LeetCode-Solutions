/*
 * You are given a string, s, and a list of words, words, 
 * that are all of the same length. 
 * Find all starting indices of substring(s) in s 
 * that is a concatenation of each word in 
 * words exactly once and without any intervening characters.
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 */

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
  vector<int> result;

	if (words.size() == 0)
		return result;

	int length = words[0].length();
	int i = 0;
	int numOfWords = words.size();

	vector<string> found(words);
	int tempStart = 0;
	
	for (int i = 0; i + (numOfWords * length) <= s.length();i ++) {
		string temp = s.substr(i, numOfWords * length);
		for (int k = 0; (k + length) <= temp.length(); k += length) {
			string word = temp.substr(k, length);

			vector<string>::iterator it = find(words.begin(), words.end(), word);
			vector<string>::iterator it2 = find(found.begin(), found.end(), word);
			
			if (it != words.end() && it2 != found.end()) {
				found.erase(it2);
			}
			else {
				break;
			}
		}

		if (found.size() == 0)
			result.push_back(i);

		found.clear();
		copy(words.begin(), words.end(), back_inserter(found));

	}
	
	return result;
    }
};
