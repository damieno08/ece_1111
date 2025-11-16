// include file
//
#include "p01.h"

// define macros
//
#define MATCH 0
#define SUB   1
#define DEL   2
#define INS   3

// define our struct
//
typedef struct {
  int total_errors;
  int substitutions;
  int insertions;
  int deletions;
  char** r_line;
  char** h_line;
  bool* r_dynamic;
  bool* h_dynamic;
  int length;
} AlignmentResult;

// function returns uppercase version of string
//
char* str_to_upper_copy(char* s) {
    if (!s) return NULL;
    int len = strlen(s);
    char* copy = new char[len + 1];  // allocate memory
    for (int i = 0; i < len; i++) {
        copy[i] = toupper((unsigned char)s[i]); // convert each character
    }
    copy[len] = '\0';
    return copy;
}
// convert string to uppercase
//
void str_to_upper(char* s) {
    for (; *s; s++) *s = toupper(*s);
}

// convert string to lowercase
//
void str_to_lower(char* s) {
    for (; *s; s++) *s = tolower(*s);
}

// create a string of stars same length as word
//
char* stars_for_word(char* word) {
    int len = strlen(word);
    char* stars = new char[len + 1];
    for (int i = 0; i < len; i++) stars[i] = '*';
    stars[len] = '\0';
    return stars;
}

// free an array of words
//
void cleanUp(char** words, int count) {
    for (int i = 0; i < count; i++) {
        delete[] words[i]; 
    }

    delete[] words;
}

// simple word equality check
//
int words_match(char* a, char* b) {
    char* A = str_to_upper_copy(a); 
    char* B = str_to_upper_copy(b);
    int result = strcmp(A, B) == 0;
    delete[] A; 
    delete[] B;
    return result;
}
// split a string into words
//
char** lineToWords(char* line, int* count) {
    char* copy = new char[strlen(line) + 1];
    strcpy(copy, line);

    int capacity = 10;
    char** words = new char*[capacity];
    int c = 0;
    char* token = strtok(copy, " \t\n");
    while (token) {
        if (c >= capacity) {
            capacity *= 2;
            char** tmp = new char*[capacity];
            for (int i = 0; i < c; i++) tmp[i] = words[i];
            delete[] words;
            words = tmp;
        }
        words[c] = new char[strlen(token) + 1];
        strcpy(words[c], token);
        c++;
        token = strtok(NULL, " \t\n");
    }
    *count = c;
    delete[] copy;
    return words;
}

// print alignment with spacing
//
void print_alignment(FILE* out, AlignmentResult result) {
    int* widths = new int[result.length];
    for (int i = 0; i < result.length; i++) {
        int len_r = strlen(result.r_line[i]);
        int len_h = strlen(result.h_line[i]);
        widths[i] = (len_r > len_h) ? len_r : len_h;
    }

    fprintf(out, "R: ");
    for (int i = 0; i < result.length; i++) fprintf(out, "%-*s ", widths[i], result.r_line[i]);
    fprintf(out, "\nH: ");
    for (int i = 0; i < result.length; i++) fprintf(out, "%-*s ", widths[i], result.h_line[i]);
    fprintf(out, "\nSubs: %d Ins: %d Dels: %d Total Errors: %d\n",
            result.substitutions, result.insertions, result.deletions, result.total_errors);

    delete[] widths;
}


// will create dynamic programming table we can use for cost of
// changing string
//
void compute_dp(char** ref, int m, char** hyp, int n) {

    // allocate DP table and operation table
  //
    int** dp = new int*[m+1];
    int** op = new int*[m+1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n+1];
        op[i] = new int[n+1];
    }

    // initialize base cases
    //
    for (int i = 0; i <= m; i++) { dp[i][0] = i; op[i][0] = DEL; }
    for (int j = 0; j <= n; j++) { dp[0][j] = j; op[0][j] = INS; }
    op[0][0] = MATCH;

    // fill DP table
    //
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (words_match(ref[i-1], hyp[j-1])) {
                dp[i][j] = dp[i-1][j-1];
                op[i][j] = MATCH;
            } else {
                int del = dp[i-1][j] + 1;
                int ins = dp[i][j-1] + 1;
                int sub = dp[i-1][j-1] + 1;
                dp[i][j] = sub; op[i][j] = SUB;
		if (ins < dp[i][j]) { dp[i][j] = ins; op[i][j] = INS; }
                if (del < dp[i][j]) { dp[i][j] = del; op[i][j] = DEL; }
            }
        }
    }

    // backtracking
    //
    int max_len = m + n;
    char** r_line = new char*[max_len];
    char** h_line = new char*[max_len];
    bool* r_dynamic = new bool[max_len];
    bool* h_dynamic = new bool[max_len];
    int idx = max_len - 1;
    int subs = 0, dels = 0, ins_count = 0;

    int i = m, j = n;
    while (i > 0 || j > 0) {
      if (i > 0 && j > 0 && op[i][j] == MATCH) {
	
        // keep original case for matches
	//
	r_line[idx] = ref[i-1];
	r_dynamic[idx] = false;
	h_line[idx] = hyp[j-1];
	h_dynamic[idx] = false;
        i--; j--; idx--;
      } else if (i > 0 && j > 0 && op[i][j] == SUB) {

	// substitution: reference uppercase, hypothesis original
	//
	r_line[idx] = str_to_upper_copy(ref[i-1]);
	r_dynamic[idx] = true;
	h_line[idx] = str_to_upper_copy(hyp[j-1]);
	h_dynamic[idx] = true;
        subs++; i--; j--; idx--;
      }      
      else if (i > 0 && op[i][j] == DEL) {

	// deletion: reference uppercase, hypothesis stars
	//
	r_line[idx] = str_to_upper_copy(ref[i-1]);
	r_dynamic[idx] = true;
	h_line[idx] = stars_for_word(ref[i-1]);
	h_dynamic[idx] = true;
        dels++; i--; idx--;
      } else if (j > 0 && op[i][j] == INS) {

	// insertion: reference stars, hypothesis uppercase
	//
	r_line[idx] = stars_for_word(hyp[j-1]);
	r_dynamic[idx] = true;
	h_line[idx] = str_to_upper_copy(hyp[j-1]);
	h_dynamic[idx] = true;
        ins_count++; j--; idx--;
      }
    }    
    
    // shift arrays to start from index 0
    //
    int length = max_len - idx - 1;
    char** r_final = new char*[length];
    char** h_final = new char*[length];
    bool* r_final_dyn = new bool[length];
    bool* h_final_dyn = new bool[length];


    for (int k = 0; k < length; k++) {
      r_final[k] = r_line[idx + 1 + k];
      r_final_dyn[k] = r_dynamic[idx + 1 + k];
      h_final[k] = h_line[idx + 1 + k];
      h_final_dyn[k] = h_dynamic[idx + 1 + k];
    }

    for (int k = 0; k <= idx; k++) {
      if (r_dynamic[k]) delete[] r_line[k];
      if (h_dynamic[k]) delete[] h_line[k];
    }
    delete[] r_line;
    delete[] h_line;
    
    // free temporary DP tables and arrays
    //
    for (int i = 0; i <= m; i++) { delete[] dp[i]; delete[] op[i]; }
    delete[] dp; delete[] op;
    delete[] r_dynamic; delete[] h_dynamic;

    // prepare the result
    //
    AlignmentResult result;
    result.total_errors = subs + dels + ins_count;
    result.substitutions = subs;
    result.insertions = ins_count;
    result.deletions = dels;
    result.r_line = r_final;
    result.h_line = h_final;
    result.length = length;
    result.r_dynamic = r_final_dyn;
    result.h_dynamic = h_final_dyn;

    // print results
    //
    print_alignment(stdout, result);
    
    // cleanup dynamic flag arrays
    //
    for (int i = 0; i < result.length; i++) {
      if (result.r_dynamic[i]) delete[] result.r_line[i];
      if (result.h_dynamic[i]) delete[] result.h_line[i];
    }
    delete[] result.r_line;
    delete[] result.h_line;
    delete[] result.r_dynamic;
    delete[] result.h_dynamic;
    
}

