static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return NULL;
}();

class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {
	

	for (int i = 0; i < board.size(); i++) {

		for (int n = 0; n < board[0].size(); n++) {

			if (board[i][n] == word[0]) {
				
                

			    
                board[i][n] = '#';
                
				if (existHelper(board, word, i, n, 1)) {
					return true;
				}

                board[i][n] = word[0];
                
			
			}

		}
	}
	return false;
}

bool existHelper(vector<vector<char>>& board, string word, int i, int n, int index) {

	if (index == word.size()) {
		return true;
	}

	if (i + 1 < board.size() && board[i + 1][n] == word[index]){
		//check bottom
		
    		
			board[i +1][n] = '#'; 
			
			if (existHelper(board, word, i + 1, n , index + 1)) {
				return true;
			}
            
            board[i + 1][n] = word[index]; 
			
            
	}
	
	if (n + 1 < board[0].size() && board[i][n + 1] == word[index]){
		//check right
		
        board[i][n+1] = '#';
			
        if (existHelper(board, word, i, n +1, index + 1)) {
            return true;
        }

        board[i][n+1] = word[index]; 
			
	}  
	
	if (i - 1 < board.size() && board[i - 1][n] == word[index]){
		//check top
		
		
		board[i -1][n] = '#'; 
				
        if (existHelper(board, word, i-1, n, index + 1)) {
            return true;
        }
        
        board[i -1][n] = word[index]; 
		    

	}
	
	if (n - 1 < board[0].size() && board[i][n - 1] == word[index]){
		//check left
		
		board[i][n -1] = '#'; 
		
        if (existHelper(board, word, i, n-1, index + 1)) {
            return true;
        }
            
        board[i][n-1] = word[index]; 


	}

	return false;

}

};
