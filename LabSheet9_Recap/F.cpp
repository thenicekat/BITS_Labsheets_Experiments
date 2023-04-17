// Maybe we can use upper bound and lower bound?

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen, remK;
        cin >> inLen >> remK;

        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            // Take input
            cin >> input[i];
        }

        sort(input, input + inLen);

        int answer = 0;
        int left = 0, right = inLen/2;
        while(left < inLen/2 && right < inLen){
            if(input[right] - input[left] >= remK){
                cout << input[left] << "-" << input[right] << endl;
                right++;
                left++;
                answer++;
            }else{
                right++;
            }
        }
        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}