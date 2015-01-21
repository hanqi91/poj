#include <iostream>
using namespace std;

void setNeighbor(int* grid, int ind, int m, int n, int pocket) {
    int nei_ind[8] = {ind - n - 1, ind - n, ind - n + 1,
                      ind -1, ind + 1,
                      ind + n - 1, ind + n, ind + n + 1};

    for (int i = 0; i < 8; i++) {
        int nei_index = nei_ind[i];
        if (grid[nei_index] > -1 && grid[nei_index] < pocket) {
            grid[nei_index] = pocket;
            setNeighbor(grid, nei_index, m, n, pocket);
        }
    }
}

int main() {
    while (1) {
        int m, n;
        cin >> m >> n;

        if (m == 0)
            break;

        int* grid = new int[(m+2)*(n+2)];
        for (int r = 0; r < m + 2; r++) {
            for (int c = 0; c < n + 2; c++) {
                grid[r*(n+2) + c] = -1;
            }
        }

        int cnt = 0;
        while (cnt < m*n) {
            int row = cnt/n + 1;
            int col = cnt%n + 1;
            char chr;
            cin >> chr;
            if (chr == '@') {
                grid[row*(n+2) + col] = 0;
            }
            cnt++;
        }

        int pocket = 0;
        for (int r = 1; r < m + 1; r++) {
            for (int c = 1; c < n + 1; c++) {
                if (grid[r*(n+2) + c] == 0) {
                    pocket++;
                    grid[r*(n+2) + c] = pocket;
                    int ind = r*(n+2) + c;
                    setNeighbor(grid, ind, m+2, n+2, pocket);
                }
            }
        }
        cout << pocket << endl;
    }
    return 0;
}
