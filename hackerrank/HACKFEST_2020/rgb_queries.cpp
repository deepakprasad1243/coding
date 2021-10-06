/*
problem:
https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/rbg/problem
*/

//Solution

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'mixColors' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY colors
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<string> mixColors(vector<vector<int>> colors, vector<vector<int>> queries) {
    vector<string> result;
    unordered_map<int, vector<vector<int>>> r ,b ,g;
    for(vector<int> color : colors){
        vector<vector<int>> temp{color};
        if(r.find(color[0])!= r.end()){
            r[color[0]].push_back(color);
        }else {
            r[color[0]] = temp;
        }
        if(b.find(color[1])!= b.end()){
            b[color[1]].push_back(color);
        }else {
            b[color[1]] = temp;
        }
        if(g.find(color[2])!= g.end()){
            g[color[2]].push_back(color);
        }else {
            g[color[2]] = temp;
        }
    }
    
    for(vector<int> query : queries){
        if(r.find(query[0])!= r.end() && b.find(query[1]) != b.end() && g.find(query[2]) != g.end()){
            bool flag = true, found = false;
            for(vector<int> color : r[query[0]]){
                if(color[1] <= query[1] && color[2] <= query[2]){
                    found = true;break;}
            }
            flag = flag && found; found = false;
            if(flag)
            for(vector<int> color : b[query[1]]){
                if(color[0] <= query[0] && color[2] <= query[2]){
                    found = true; break;}
            }
            flag = flag && found; found = false;
            if(flag)
            for(vector<int> color : g[query[2]]){
                if(color[1] <= query[1] && color[0] <= query[0]){
                    found = true;break;}
            }
            flag = flag && found;
            if(flag) result.push_back("YES");
            else result.push_back("NO");
        }else{
            result.push_back("NO");
        }
    }
    return result;

}



//boilerplate

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    vector<vector<int>> colors(n);

    for (int i = 0; i < n; i++) {
        colors[i].resize(3);

        string colors_row_temp_temp;
        getline(cin, colors_row_temp_temp);

        vector<string> colors_row_temp = split(rtrim(colors_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int colors_row_item = stoi(colors_row_temp[j]);

            colors[i][j] = colors_row_item;
        }
    }

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<string> result = mixColors(colors, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
