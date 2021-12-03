#include <bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'bestCombo' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY popularity
 *  2. INTEGER k
 */
 
vector<long> go(vector<int> set){
    ll set_size = set.size(); 
    unsigned long long pow_set_size=pow(2,set_size);
    long counter,j, value;
    vector<long> ans;
    for (counter=0; counter<pow_set_size; counter++) {
            value = 0;
        
        for(j=0;j<set_size;j++) {
            if (counter & (1<<j)){
                value+=set[j];
            }
            // cout << value << endl;
        }
        ans.push_back(value);
    }
    return ans;
}

vector<long> bestCombo(vector<int> popularity, int k) {
    vector<long> s;
    s= go(popularity);
    sort(s.begin(),s.end());
    vector<long> ans(s.rbegin(),s.rbegin()+k);
    // for(long i = s.size()-1;i>=s.size()-k;i--){
    //     ans.push_back(s[i]);
    // }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string popularity_count_temp;
    getline(cin, popularity_count_temp);

    int popularity_count = stoi(ltrim(rtrim(popularity_count_temp)));

    vector<int> popularity(popularity_count);

    for (int i = 0; i < popularity_count; i++) {
        string popularity_item_temp;
        getline(cin, popularity_item_temp);

        int popularity_item = stoi(ltrim(rtrim(popularity_item_temp)));

        popularity[i] = popularity_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<long> result = bestCombo(popularity, k);

    for (size_t i = 0; i < result.size(); i++) {
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