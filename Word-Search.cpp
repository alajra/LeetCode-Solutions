/*
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 * https://leetcode.com/problems/word-search/
 */

class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {	
	//iterating through the whole 2D array
	for (int i = 0; i < board.size(); i++) {
		for (int n = 0; n < board[0].size(); n++) {
			//find the instances of the first letter in the work
			if (board[i][n] == word[0]) {
				
				//if found, delete the letter temprorary 
                		board[i][n] = '#';
                			
				//check if the work exist starting from that place
				if (existHelper(board, word, i, n, 1))
					return true;
				
				//if the word was not found, reset the array 	
               	 		board[i][n] = word[0];
			}
		}
	}
	return false;
}
/*
 * This is a recursive method that finds a word in in 2D Char Vector
 * paramaters:
 * borad : 2D char vector to find the word in
 * word  : the string for the word to look for
 * i     : the current row number we're looking at
 * n     : the current column number we're looking at
 * index : the letter index in the word we're looking for
 */
bool existHelper(vector<vector<char>>& board, string word, int i, int n, int index) {
	//if all the letter were found
	if (index == word.size()) {
		return true;
	}
	
	//check if the next letter is below the current one
	if (i + 1 < board.size() && board[i + 1][n] == word[index]){	
		
		//if found, delete the letter temprorary 
		board[i +1][n] = '#'; 
		
		//check if the work exist starting from that place
		if (existHelper(board, word, i + 1, n , index + 1)) {
			return true;
		}
		
		//if the word was not found, reset the array 
		board[i + 1][n] = word[index]; 
			
	}
	
	//check if the next letter is right to the current one
	if (n + 1 < board[0].size() && board[i][n + 1] == word[index]){
		
		//if found, delete the letter temprorary 
		board[i][n+1] = '#';
		
		//check if the work exist starting from that place
		if (existHelper(board, word, i, n +1, index + 1)) {
			return true;
		}
		
		//if the word was not found, reset the array 
		board[i][n+1] = word[index]; 
			
	}
	
	//check if the next letter is above the current one
	if (i - 1 < board.size() && board[i - 1][n] == word[index]){
		
		//if found, delete the letter temprorary 	
		board[i -1][n] = '#'; 
		
		//check if the work exist starting from that place
		if (existHelper(board, word, i-1, n, index + 1)) {
			return true;
		}
		
		//if the word was not found, reset the array 
		board[i -1][n] = word[index]; 
		    
	}
	
	//check if the next letter is left to the current one
	if (n - 1 < board[0].size() && board[i][n - 1] == word[index]){
		
		//if found, delete the letter temprorary 
		board[i][n -1] = '#'; 
		
		//check if the work exist starting from that place
		if (existHelper(board, word, i, n-1, index + 1)) {
			return true;
		}
		
		//if the word was not found, reset the array 
		board[i][n-1] = word[index]; 

	}

	return false;

}

};
