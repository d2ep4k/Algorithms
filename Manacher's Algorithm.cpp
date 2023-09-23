#define SIZE 1e6
class manacher {
    public:
    vector<int> maxPalinAt;                                                        //maxPalinAt[i] stores longest palindrome with index 'i' as the center
    string longestPalinSubstr;                                                     //stores longest Palindromic Substring
  
    manacher() {
        maxPalinAt = vector<int>(SIZE);                                            //define SIZE as per requirement{ SIZE >= (2*len(orignalString))+ 1 }
    }; 
  
    void buildManacher(string str){  
  
        string tweakedStr;
        tweakedStr+='*';                                                           //string revamp, original string shouldn't include stuffing char(here '*')
        for(int i=0;i<str.length();i++){
            tweakedStr+=str[i];
            tweakedStr+='*'; 
        }
  
        int mid = min(1ul, str.length()), right = min(1ul, str.length());          //bounding-box parameters
        int longestAt = min(1ul, str.length());
        maxPalinAt[0]=0;
  
        for(int i=1;i<tweakedStr.length();i++)
        {   
            maxPalinAt[i]=max(0,min(maxPalinAt[2*mid-i],right-i));
            int ind = maxPalinAt[i];
            while(i-ind-1>=0&&i+ind+1<tweakedStr.length()&&tweakedStr[i-ind-1]==tweakedStr[i+ind+1]){
                ind++;
            }
            maxPalinAt[i] = ind;
            if(maxPalinAt[i]>maxPalinAt[longestAt]){
                longestAt=i;
            }   
            if( i+ind >= right ){                                                    //bounding-box updation
                right = i+ind;
                mid = i;
            }
        }
        
        longestPalinSubstr.clear();
  
        for(int i=longestAt-maxPalinAt[longestAt];i<=longestAt+maxPalinAt[longestAt];i++){
            if(tweakedStr[i]!='*')
                longestPalinSubstr+=tweakedStr[i];
        }
  
        return ;
    }

    //call after buildMancher()
    bool isPalindrome(int l,int r){                                                 
        return maxPalinAt[((2*l+1)+(2*r+1))/2]>=r-l+1;
    }

    string getmaxPalinAt(){
      return longestPalinSubstr;
    }

};
