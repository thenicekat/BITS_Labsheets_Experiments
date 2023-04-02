// we can use sets and then compare
// comparing sets takes O(size of set)
// hm so we can apparently use the strings initially to give each of them a string like number,
// and then we can compare two of them and check the answer
// we have eat/tea and ate -> all of them will end up being the same string
// but the thing is time complexity
// O(mn [for looping through all letters] + nlogn [for adding them into map] + 26n [for building the hash])

#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("Inputs/A.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // We see how mnay number of words we get
        int noOfwords;
        cin >> noOfwords;

        // We hash each word into letters + number and store it in map
        map<string, int> store;

        for (int i = 0; i < noOfwords; i++)
        {
            string word;
            cin >> word;

            // Initialize letters to 0
            int letters[26] = {0};
            // This gives us time complexity of O(m)
            for(char t: word){
                letters[t - 'a']++;
            }

            // This hashes the words -> O(26)
            string key = "";
            for(int i=0; i<26; i++){
                key += ('a' + i);
                key += to_string(letters[i]);
            }

            // Adds into map O(logn)
            if(store.find(key) == store.end()){
                store[key] = 1;
            }else{
                store[key]++;
            }
        }
        // This loop runs n times so, TC = mn + 26n + nlogn

        // This loop goes through all distinct elements only
        int answer = 0;
        for(auto x: store){
            answer += (x.second)*(x.second - 1)/2;
        }
        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}