#define SIZE 1e6
class manacher {
    public:
    vector<int> longestPalindrome;                                                    //longestPalindrome[i] stores longest Palindrome with 'i' as the center
    string longestSubstring;                                                          //stores longest Palindromic Substring
  
    manacher() {
        longestPalindrome = vector<int>(SIZE);                                        //define SIZE as per requirement{ SIZE >= (2*len(orignalString))+ 1 }
    }; 
  
    void buildManacher(string str){  
  
        string tweakedStr;
        tweakedStr+='*';                                                              //string revamp, stuffing char cannot be a part of orignal string, here '*'
        for(int i=0;i<str.length();i++){
            tweakedStr+=str[i];
            tweakedStr+='*'; 
        }
  
        int mid = min(1ul, str.length()), right = min(1ul, str.length());             //bounding-box parameters
        int longestAt = min(1ul, str.length());
        longestPalindrome[0]=0;
  
        for(int i=1;i<tweakedStr.length();i++)
        {   
            longestPalindrome[i]=max(0,min(longestPalindrome[2*mid-i],right-i));
            int ind = longestPalindrome[i];
            while(i-ind-1>=0&&i+ind+1<tweakedStr.length()&&tweakedStr[i-ind-1]==tweakedStr[i+ind+1]){
                ind++;
            }
            longestPalindrome[i] = ind;
            if(longestPalindrome[i]>longestPalindrome[longestAt]){
                longestAt=i;
            }   
            if( i+ind >= right ){                                                    //bounding-box updation
                right = i+ind;
                mid = i;
            }
        }
        
        longestSubstring.clear();
  
        for(int i=longestAt-longestPalindrome[longestAt];i<=longestAt+longestPalindrome[longestAt];i++){
            if(tweakedStr[i]!='*')
                longestSubstring+=tweakedStr[i];
        }
  
        return ;
    }

    //call after buildMancher()
    bool isPalindrome(int l,int r){                                                 
        return longestPalindrome[((2*l+1)+(2*r+1))/2]>=r-l+1;
    }

    string getlongestPalindrome(){
      return longestSubstring;
    }

};
