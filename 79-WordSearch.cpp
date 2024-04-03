class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rowSize = board.size();
        const int columnSize = board[0].size();

        function<bool(int, int, int)> backtrack = [&](const int i, const int j, const int currentIndex) {
          
            // Si l'index est égale à la longueur du mot, on a trouvé !
            if (currentIndex == word.length()) {
                return true;
            }

            // Si les i ou j est en dehors de la matrice ou si la lettre actuelle n'est pas bonne, on arrête
            if (i < 0 || i >= rowSize || j < 0 || j >= columnSize || board[i][j] != word[currentIndex]) {
                return false;
            }

            // Si la lettre est OK, on la passe à une valeur nulle pour ne pas la re-vérifier plus tard
            // On conserve la valeur dans une variable temporaire, pour la remettre en place plus tard
            const char temp = board[i][j];
            board[i][j] = '\0';

            // On relance cette fonction sur l'index suivant, dans tous les cas de coordonnées suivantes possibles
            if (backtrack(i + 1, j, currentIndex + 1) || backtrack(i - 1, j, currentIndex + 1) || backtrack(i, j + 1, currentIndex + 1) || backtrack(i, j - 1, currentIndex + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };

        // On parcours la matrice en entier, et on commence le check en [0][0]
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;       

    }
};
