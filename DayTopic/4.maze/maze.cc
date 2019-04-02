#include <iostream>
#include <vector>

using std::vector;

int N,M;//分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径
vector<vector<int>> path_best;//存储最佳路径

void MazeTrack(int i, int j)
{
    maze[i][j] = 1;//表示当前节点已走，不可再走
    path_temp.push_back({i, j});//直接插入一个一维数组

    if (i == N - 1 && j == M - 1)
    {
        if (path_best.empty() || path_temp.size() < path_best.size())
        {
            path_best = path_temp;
        }
    }

    if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
        MazeTrack(i - 1, j);
    if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
        MazeTrack(i + 1, j);
    if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
        MazeTrack(i, j - 1);
    if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
        MazeTrack(i, j + 1);
    maze[i][j] = 0; //恢复现场，设为未走
    path_temp.pop_back();
}

int main()
{
    while (std::cin >> N >> M)
    {
        maze = vector<vector<int>>(N, vector<int>(M, 0));
        path_temp.clear();
        path_best.clear();
        for (auto& i : maze)
        {
            for (auto& j : i)
            {
                std::cin >> j;
            }
        }
        MazeTrack(0, 0);
        for (auto e : path_best)
        {
            std::cout << "(" << e[0] << "," << e[1] << ")" << std::endl;
        }
    }
    return 0;
}


