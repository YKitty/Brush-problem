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
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                //第一个格子已经记录下来，不需要在求最大值
                if (i == 0 && j == 0)
                {
                    continue;
                }
                else if (i == 0) //第一行只能向右边走
                {
                    allPath[i][j] = allPath[i][j - 1] + board[i][j];
                }
                else if (j == 0) //第一列只能向下边走
                {
                    allPath[i][j] = allPath[i - 1][j] + board[i][j];
                }
                else //存在左边和上边
                {
                    allPath[i][j] = std::max(allPath[i - 1][j], allPath[i][j - 1]) + board[i][j];
                }
            }
        }

        return allPath[length - 1][width - 1];
    }
};
