#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<char>> &soduku, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col){
    if (r == 9){
        for (auto it : soduku){
            for (auto i : it){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    if (c == 9){
        helper(r + 1, 0, soduku, mp, row, col);
        return;
    }

    if (soduku[r][c] != '.'){
        helper(r, c + 1, soduku, mp, row, col);
        return;
    }

    for (int i = 1; i <= 9; i++){
        if (!mp[{r / 3, c / 3}][i] && !row[r][i] && !col[c][i]){
            mp[{r / 3, c / 3}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            soduku[r][c] = i + '0';
            helper(r, c + 1, soduku, mp, row, col);
            mp[{r / 3, c / 3}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            soduku[r][c] = '.';
        }
    }
}

void solveSoduku(vector<vector<char>> &soduku){
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (soduku[i][j] != '.'){
                mp[{i / 3, j / 3}][soduku[i][j] - '0'] = 1;
                row[i][soduku[i][j] - '0'] = 1;
                col[j][soduku[i][j] - '0'] = 1;
            }
        }
    }
    helper(0, 0, soduku, mp, row, col);
}

int main(){
    vector<vector<char>> soduku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSoduku(soduku);
    return 0;
}
