//In The Name Of God
#include<bits/stdc++.h>

using namespace std;
#define inf 1000000000

typedef vector<int> vi;

vector<char> grid(16);
vector<string> words;

vi visited; // must be global or passed to function

int score(int s) {
    if(s < 3) return 0;
    if(s == 3 || s == 4) return 1;
    if(s == 5) return 2;
    if(s == 6) return 3;
    if(s == 7) return 5;
    else return 11;
}

bool dfs(int vertex, string &word, int index) {
    if(index == word.size())
        return true;
    visited[vertex] = true;
    bool found = false;
    if (vertex + 1 < 16 && (vertex + 1) % 4 && !visited[vertex + 1] && word[index] == grid[vertex + 1]) if (dfs(
            vertex + 1, word, index + 1))
        return true;
    if (vertex - 1 >= 0 && vertex % 4 && word[index] == grid[vertex - 1] && !visited[vertex - 1]) if (dfs(vertex - 1,
                                                                                                          word,
                                                                                                          index + 1))
        return true;
    if (vertex - 4 >= 0 && word[index] == grid[vertex - 4] && !visited[vertex - 4]) if (dfs(vertex - 4,
                                                                                            word,
                                                                                            index + 1))
        return true;
    if (vertex + 4 < 16 && word[index] == grid[vertex + 4] && !visited[vertex + 4]) if (dfs(vertex + 4,
                                                                                            word,
                                                                                            index + 1))
        return true;
    if (vertex - 5 >= 0 && vertex % 4 && word[index] == grid[vertex - 5] && !visited[vertex - 5]) if (dfs(vertex - 5,
                                                                                                          word,
                                                                                                          index + 1))
        return true;
    if (vertex - 3 >= 0 && (vertex - 3) % 4 && word[index] == grid[vertex - 3] && !visited[vertex - 3]) if (dfs(
            vertex - 3,
            word,
            index + 1))
        return true;
    if (vertex + 3 < 16 && vertex % 4 && word[index] == grid[vertex + 3] && !visited[vertex + 3]) if (dfs(vertex + 3,
                                                                                                          word,
                                                                                                          index + 1))
        return true;
    if (vertex + 5 < 16 && (vertex + 5) % 4 && word[index] == grid[vertex + 5] && !visited[vertex + 5]) if (dfs(
            vertex + 5,
            word,
            index + 1))
        return true;
    visited[vertex] = false;
    return false;
}

int main() {
    vector<char> &ggrid = grid;
    vector<string> &wwords = words;
    int tc, ttc = 1;
    cin >> tc;
    while (tc--) {
        printf("Score for Boggle game #%d: ", ttc++);
        for (int i = 0; i < 16; i++)
            cin >> grid[i];
        int n;
        cin >> n;
        string tmp;
        while (n--) {
            cin >> tmp;
            words.push_back(tmp);
        }
        int ans = 0;
        for(auto &str : words) {
            for(int i = 0; i < 16; i++)
                if(grid[i] == str[0]) {
                    visited.clear();
                    visited.resize(17, false);
                    if(dfs(i, str, 1)) {
                        ans += score(str.size());
                        break;
                    }
                }
        }

        cout << ans << endl;
        words.clear();
        visited.clear();
    }

    return 0;
}