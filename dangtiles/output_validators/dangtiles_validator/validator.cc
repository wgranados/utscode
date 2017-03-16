#include <utility>
#include <string>
#include <cassert>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include "streamcorr.h"

#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

bool author_messages = false;

/* Wrapper for author message printing so that they are only printed in
 * case the author_messages option was given.  If the validator should
 * always print author messages, you can just call
 * report_feedback(authormessage, ...) directly.
 */
void author_message(const char *s) {
    if (author_messages) {
        report_feedback(authormessage, s);
    }
}

bool check(int p, vi &a, vi &b)
{
    if (a[p] == b[p]) return true;
    if (p > 0 && a[p] == b[p - 1]) return true;
    if (p + 1 < (int)a.size() && a[p] == b[p + 1]) return true;
    return false;
}

int encode(vi &p)
{
    if (p.size() == 1) return 0;
    int pos = find(p.begin(), p.end(), p.size()) - p.begin();
    int sz = p.size();
    p.erase(p.begin() + pos);
    return pos + encode(p) * sz;
}

bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void dfs(int r, int c, int m, bool**v) {
    if(m >= 0){
        v[r][c] = true;
        for(int d = 0;d < 4;d++) {
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(valid(nr, nc)) {
                dfs(nr, nc, m-1, v);
            }
        }
    }
}

pair<int,int> string_to_two_ints(string s) {
    stringstream ss(s);
    int first, second;
    if(!(ss >> first))
       report_error("Wrong input format") ;
    if(!(ss >> second))
       report_error("Wrong input format") ;
    return make_pair(first, second);
}


int manhatten_distance(pair<int,int>X, pair<int,int>Y) {
    return abs(X.first-Y.first) + abs(X.second-Y.second);
}

/* Check one test case. */
void check_case() {
    // gathering test case input
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    /* Check if the author_messages option is given. */
    for (int i = 4; i < argc; ++i)
        if (!strcmp(argv[i], "author_messages"))
            author_messages = true;

    check_case();

    /* Check for trailing output in author file. */
    string trash;
    if (author_out >> trash) {
        author_message("Trailing output after last test case");
        report_error("Trailing output");
    }

    /* Yay! */
    author_message("Thank you for your great code. It was fantastic.");
    accept();
}