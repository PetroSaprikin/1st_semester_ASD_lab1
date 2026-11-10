int main() {

    double a = -12.4;
    double b = 15.6;
    double A[8][4] = {
        {12.5, -3.2, 47.8, 0.0},
        {5.1, 99.9, -12.4, 8.8},
        {-7.7, 15.6, 3.3, -22.5},
        {42.0, 0.5, 11.1, 6.6},
        {18.9, -9.9, 27.4, 33.3},
        {0.4, 88.8, -5.5, 19.2},
        {-13.3, 7.7, 2.2, 55.5},
        {9.9, -44.1, 100.0, -1.1}
    };

    double B[4];
    int n = 4;
    int i = n -1;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (col == i) {
                B[i] = A[row][col];
                i--;
            }
        }
    }

    int answer;

    for (int index = 0; index < n; index++) {
        if (B[index] == a) {
            answer = index;
        }
    }

    int m = 8;

    for (int col = 0; col < n; col++) {
        for (int row = 1; row < m; row++) {
            double key = A[row][col];
            int j = row - 1;
            while (j >= 0 && A[j][col] < key) {
                A[j + 1][col] = A[j][col];
                j--;
            }
            A[j + 1][col] = key;
        }
    }

    int answer_2[2];

    for (int col = 0; col < n; col++) {

        int left = 0;
        int right = m - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (A[mid][col] == b) {
                answer_2[0] = mid;
                answer_2[1] = col;
                break;
            }

            if (A[mid][col] > b) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

    }

    return 0;
}
