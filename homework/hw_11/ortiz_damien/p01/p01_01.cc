#include "p01.h"

int min3(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

char* stars_for_word(const char* word) {
    int len = strlen(word);
    char* stars = new char[len + 1];
    for (int i = 0; i < len; i++) stars[i] = '*';
    stars[len] = '\0';
    return stars;
}

struct AlignmentResult {
    int total_errors;
    int substitutions;
    int insertions;
    int deletions;
    char** r_line;  // aligned reference words
    char** h_line;  // aligned hypothesis words
    int length;     // length of aligned sequences
};

AlignmentResult compute_dp(char** ref, int m, char** hyp, int n) {
    // Allocate DP table and operation table
    int** dp = new int*[m + 1];
    int** op = new int*[m + 1]; // 0=match/sub, 1=del, 2=ins
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        op[i] = new int[n + 1];
    }

    // Initialize base cases
    for (int i = 0; i <= m; i++) { dp[i][0] = i; op[i][0] = 1; } // delete
    for (int j = 0; j <= n; j++) { dp[0][j] = j; op[0][j] = 2; } // insert
    op[0][0] = 0;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (strcmp(ref[i - 1], hyp[j - 1]) == 0) {
                dp[i][j] = dp[i - 1][j - 1];
                op[i][j] = 0; // match
            } else {
                int del = dp[i - 1][j] + 1;
                int ins = dp[i][j - 1] + 1;
                int sub = dp[i - 1][j - 1] + 1;

                dp[i][j] = min3(del, ins, sub);
                if (dp[i][j] == sub) op[i][j] = 0; // substitution
                else if (dp[i][j] == del) op[i][j] = 1;
                else op[i][j] = 2;
            }
        }
    }

    // Backtrack to create aligned lines
    int max_len = m + n;
    char** r_line = new char*[max_len];
    char** h_line = new char*[max_len];
    int idx = max_len - 1;
    int subs = 0, dels = 0, ins = 0;

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && op[i][j] == 0 && strcmp(ref[i-1], hyp[j-1]) == 0) {
            r_line[idx] = ref[i-1];
            h_line[idx] = hyp[j-1];
            i--; j--; idx--;
        } else if (i > 0 && j > 0 && op[i][j] == 0) { // substitution
            r_line[idx] = ref[i-1];
            h_line[idx] = hyp[j-1];
            subs++; i--; j--; idx--;
        } else if (i > 0 && op[i][j] == 1) { // deletion
            r_line[idx] = ref[i-1];
	    h_line[idx] = stars_for_word(ref[i-1]);
            dels++; i--; idx--;
        } else if (j > 0 && op[i][j] == 2) { // insertion
	    r_line[idx] = stars_for_word(ref[i-1]);
            h_line[idx] = hyp[j-1];
            ins++; j--; idx--;
        }
    }

    // Shift arrays to start from index 0
    int length = max_len - idx - 1;
    char** r_final = new char*[length];
    char** h_final = new char*[length];
    for (int k = 0; k < length; k++) {
        r_final[k] = r_line[idx + 1 + k];
        h_final[k] = h_line[idx + 1 + k];
    }

    // Free DP memory
    for (int i = 0; i <= m; i++) { delete[] dp[i]; delete[] op[i]; }
    delete[] dp; delete[] op;
    delete[] r_line; delete[] h_line;

    return { dp[m][n], subs, ins, dels, r_final, h_final, length };
}

void print_alignment(FILE* out, AlignmentResult result) {
    fprintf(stdout, "R: ");
    for (int i = 0; i < result.length; i++) fprintf(out, "%s ", result.r_line[i]);
    fprintf(stdout, "\nH: ");
    for (int i = 0; i < result.length; i++) fprintf(out, "%s ", result.h_line[i]);
    fprintf(stdout, "\nSubs: %d Ins: %d Dels: %d Total Errors: %d\n",
            result.substitutions, result.insertions, result.deletions, result.total_errors);
}
