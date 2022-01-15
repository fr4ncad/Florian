#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int islandPaths(vector<vector<int>> *matrix, int src, vector<bool> *cols, vector<int> *parent, int N)
{
    queue<int> todo;
    todo.push(src);
    int cTask, num = 0;
    cols->at(src) = 1;

    bool loop = 0, dbothWays = 0;

    while (!todo.empty())
    {
        cTask = todo.front();
        todo.pop();
        ++num;
        for (int i = 0; i < N; ++i)
        {
            if (cols->at(i) && i != parent->at(cTask) && matrix->at(cTask)[i] > 0)
            {
                loop = 1;
            }
            if (!cols->at(i) && matrix->at(cTask)[i] > 0)
            {
                if (matrix->at(cTask)[i] == 2)
                    dbothWays = 1;

                todo.push(i);
                parent->at(i) = cTask;
                cols->at(i) = 1;
            }
        }
    }
    if (dbothWays)
        return 1;
    else if (loop)
        return 2;
    else
        return num;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(N));
    vector<int> parent(N, -1);
    vector<bool> cols(N, 0);
    for (int i = 0; i < M; ++i)
    {
        int c, k;
        cin >> c >> k;
        c--;
        k--;
        matrix[c][k]++;
        matrix[k][c]++;
    }

    // run for every island
int AllTheWays=1;

    for (int i=0;i<N;++i)
    {
        if (!cols[i])
        {
            AllTheWays*=islandPaths(&matrix, i, &cols, &parent, N);
        }
    }
    cout<<AllTheWays<<"\n";
    return 0;
}