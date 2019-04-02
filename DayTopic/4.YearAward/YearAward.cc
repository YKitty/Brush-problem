class Bonus {
public:
    int getMost(vector<vector<int> > board) {
                // write code here
        int length = board.size();
        int width = board[0].size();

        vector<vector<int>> allPath;
        //进行初始化
        for (int i = 0; i < length; i++)
        {
            allPath.push_back(width, 0);
        }
        
        allPath[0][0] = board[0][0];
        for ()
    }

};
