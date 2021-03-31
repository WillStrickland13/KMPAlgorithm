/*
 * C++ Program to Implement Knuth–Morris–Pratt Algorithm (KMP)
 */
#include <iostream>
using namespace std;
void preKMP(string pattern, int lps[])
{
    int m = pattern.length(), k;
    lps[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = lps[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = lps[k];
        }
        lps[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int lps[m];
    preKMP(pattern, lps);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = lps[k];
    }
    return 0;
}

int main()
{
    string tar = "san and linux training";
    string pat = "lin";
    if (KMP(pat, tar))
        cout<<"'"<<pat<<"' found in string '"<<tar<<"'"<<endl;
    else
        cout<<"'"<<pat<<"' not found in string '"<<tar<<"'"<<endl;
    pat = "sanfoundry";
    if (KMP(pat, tar))
        cout<<"'"<<pat<<"' found in string '"<<tar<<"'"<<endl;
    else
        cout<<"'"<<pat<<"' not found in string '"<<tar<<"'"<<endl;
    return 0;
}