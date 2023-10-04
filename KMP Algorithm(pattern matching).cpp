#include <iostream>
#include <vector>
using namespace std;

class kmp{
public:

    vector<int>lps;
    
    void pi(string word){
        lps.resize(int(word.length()));
        for(int i = 0; i<lps.size(); i++){
            lps[i] = -1;
        }
        for(int i=1; i<lps.size(); i++){            //skipping index 0 to avoid improper lps
            int ind = lps[i-1]+1;                   //potential match
            while(ind > 0 && word[ind] != word[i]){
                ind =  lps[ind - 1]+1;
            }
            if(word[ind] == word[i]){
                lps[i] = ind;
            }
        }
        return;
    }
    
    vector<int> matching(string text, string word){
        vector<int> indices;
        int wptr = 0;
        for(int i = 0; i<int(text.length()); i++){
            while(wptr>0 && word[wptr] != text[i]){
                wptr = lps[wptr-1]+1;    
            }
            if(word[wptr] == text[i]){
                wptr = wptr+1;
            }
            if(wptr == int(word.length())){
                indices.push_back(i-word.length()+1);
                if(wptr > 0)
                    wptr = lps[wptr-1] + 1;
                else
                    wptr = -1;
            }
        }
        return indices;
    }
    
    vector<int> patternMatching(string text, string word){
        pi(word);
        return matching(text, word);
    }
};


int main()
{
    kmp k;
    vector<int> arr =  k.patternMatching("eeleeleee", "elee");
    for(auto i:arr)cout<<i<<" "; 

    return 0;
}
