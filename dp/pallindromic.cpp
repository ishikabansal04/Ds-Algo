#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vvs vector<vs>
using namespace std;

vvb isPali(string str){
    vvb ispalindrome(str.length(),vb(str.length(),false));
    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) ispalindrome[i][j]=true;
            else if(str[i]==str[j]){
                if(gap==1) ispalindrome[i][j]=true;
                else if(ispalindrome[i+1][j-1]) ispalindrome[i][j]=true;
            }
        }
    }
    return ispalindrome;
}

//ques 1a. Sustring=======(longest pallindromic substring length)
int lpsubstring(string str){
    vvi dp(str.length(),vi(str.length(),0));
    vvb ispalindrome=isPali(str);

     for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) dp[i][j]=1;
            else if(gap==1 && str[i]==str[j] ){
                 dp[i][j]=2;
            }
            else if(str[i]==str[j] && ispalindrome[i+1][j-1]) 
                 dp[i][j]=dp[i+1][j-1]+2;
            else
                 dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            
        }
    }
return dp[0][str.length()-1];
}

//ques 1b. Sustring=======(longest pallindromic substring)

int largestPsubstring(string str){
    vvi dp(str.length(),vi(str.length(),0));
    vvs answer(str.length(),vs(str.length(),""));
    vvb ispalindrome=isPali(str);

     for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) {
                dp[i][j]=1;
                answer[i][j] += str[i];
                continue;
              //  answer[i][j]=answer[i][j]+str[i];
            }
            else if(gap==1 && str[i]==str[j] ){
                 dp[i][j]=2;
                 answer[i][j]+=str[i]+str[i];
            }
            else if(str[i]==str[j] && ispalindrome[i+1][j-1]){
                 dp[i][j]=dp[i+1][j-1]+2;
                  answer[i][j]+=str[i]+answer[i+1][j-1]+str[i];
            }
            else{
                 dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                 if(max(dp[i][j-1],dp[i+1][j])==dp[i][j-1]){
                      answer[i][j]+=answer[i][j-1];
                 }
                 else{
                     answer[i][j]+=answer[i+1][j];
                 }
            }
        }
    }
    cout<<answer[0][str.length()-1]<<endl;
return dp[0][str.length()-1];
}


//ques 1c. Sustring=======(count of pallindromic substrings)
int countsubstrings(string str){
    vvb ispalindrome=isPali(str);
    int count=0;
      for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(ispalindrome[i][j]) count++;
        }
    }
return count;
}

//ques 2a. Subsequence=================(largest pallindromic subsequence length)
int lpsubsequence(string str){
    vvi dp(str.length(),vi(str.length(),0));

     for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) dp[i][j]=1;
          else if(str[i]==str[j]) 
                 dp[i][j]=dp[i+1][j-1]+2;
            else 
                 dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            
        }
    }
 
return dp[0][str.length()-1];
}

//ques 2b. Subsequence=======(longest pallindromic subsequence)
int largestPsubsequence(string str){
    vvi dp(str.length(),vi(str.length(),0));
    vvs answer(str.length(),vs(str.length(),""));

    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) {
                dp[i][j]=1;
                answer[i][j]+=str[i];
            }
            else if(gap==1 && str[i]==str[j] ){
                 dp[i][j]=2;
                 answer[i][j]+=str[i]+str[i];
            }
            else if(str[i]==str[j]){
                 dp[i][j]=dp[i+1][j-1]+2;
                  answer[i][j]+=str[i]+answer[i+1][j-1]+str[i];
            }
            else{
                 dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                 if(max(dp[i][j-1],dp[i+1][j])==dp[i][j-1]){
                      answer[i][j]+=answer[i][j-1];
                 }
                 else{
                     answer[i][j]+=answer[i+1][j];
                 }
            }
        }
    }
    cout<<answer[0][str.length()-1]<<endl;
return dp[0][str.length()-1];
}

//ques 2c. Subsequences=======(count of pallindromic subsequences)
int countsubsequence(string str){
    vvi dp(str.length(),vi(str.length(),0));

     for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) {
                dp[i][j]=1;
            }
            else if(str[i]==str[j]) 
                 {
                     dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                    
                 }
            else 
                 {
                     dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                     
                 }
        }
    }
return dp[0][str.length()-1];
}

//ques 3a. Largest common Substring===========================

int globalmax=0;
int LCsubstring(string str1,string str2){
   // int localmax=0;
       vvi dp(str1.length()+1,vi(str2.length()+1,0));
       for(int i=str1.length()-1;i>=0;i--){
           for(int j=str2.length()-1;j>=0;j--){
               if(str1[i]==str2[j] ){
                    dp[i][j]=dp[i+1][j+1]+1;
                    //localmax+=1;
               }

               else if(str1[i]!=str2[j]){
                   //globalmax=max(globalmax,localmax);
                   //localmax=0;
                   dp[i][j]=0;
               }
           }
       }

       for(int i=str1.length()-1;i>=0;i--){
           for(int j=str2.length()-1;j>=0;j--){
               if(dp[i][j]>globalmax){
                   globalmax=dp[i][j];
               }
           }
       }
       return globalmax;

}
/*
int globalmax=-1;
int LCsubstring_01(string str1,string str2){
    int localmax=0;
    for(int i=str1.length()-1;i>=0;i--){
        for(int j=str2.length()-1;j>=0;j--){
            if(str1[i]==str2[j]){
                localmax=localmax+1;
            }
            else{
                if(localmax>globalmax){
                    globalmax=localmax;
                }
                localmax=0;
            }
        }
    }
    return globalmax;
}
*/


//ques 3b. Largest common Subsequence====================================
int LCsubsequence(string str1,string str2){
      vvi dp(str1.length()+1,vi(str2.length()+1,0));
      for(int i=str1.length()-1;i>=0;i--){
          for(int j=str2.length()-1;j>=0;j--){
              if(str1[i]==str2[j]){
                  dp[i][j]=dp[i+1][j+1]+1;
              }
              else if(str1[i]!=str2[j]){
                  dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
              }
          }
      }
      return dp[0][0];
}

//ques4. to find no of possible (subsequences) ways in which str2 is found in string 1=====
//int ways=0;
int digstring(string str1,string str2){
     vvi dp(str1.length()+2,vi(str2.length()+2,0));
    
       dp[str1.length()+1][str2.length()+1]=1;
     for(int i=str1.length();i>=0;i--){
         for(int j=str2.length();j>=0;j--){
            
             if(str1[i]==str2[j]){
                 dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
             }
             else if(str1[i]!=str2[j]){
                 dp[i][j]=dp[i+1][j];
             }
         }
     }
     return dp[0][0];
}

int digstring_01(string str1,string str2){
    int m=str1.length();
    int n=str2.length();
    vvi dp(m+1,vi(n+1,0));

    //case when second string is empty. we r basically finding for \0 in string 2
    for(int i=0;i<=m;i++){
        dp[i][0]=1;
    }

    //case when first string is empty. we r basically finding for string 2 in \0
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i]==str2[j]){
                dp[i][j]=dp[i-1][j-1] +dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}

//ques 5. to make two strings equal by performing min no of operations===============
int equistring(string str1,string str2){
      if(str2.length()>str1.length()){
           string str=str1;
          str1=str2;
          str2=str;
      }
      vvi dp(str1.length()+2,vi(str2.length()+2,0));
    //   dp[str1.length()+1][str2.length()+1]=0;

      for(int i=str1.length();i>=0;i--){
          for(int j=str2.length();j>=0;j--){
              
              if(str1[i]==str2[j]){
                  dp[i][j]=dp[i+1][j+1];
              }
              else{
                  dp[i][j]=min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1])+1;
              }
          }
      }
      return dp[0][0];
}

//ques 6. count total no of distinct subsequences===========================
int distinctsubseq(string str){
    vi dp(str.length()+2,0);
    vi lastindex(26,-1);
    dp[0]=1;
    for(int i=0;i<str.length();i++){
        int idx=str[i]-'a';
        if(lastindex[idx]==-1){
            dp[i+1]=2*dp[i];
            lastindex[idx]=i+1;
        }
        else{
            int idx2=lastindex[idx]-1;
            dp[i+1]=(2*dp[i])-dp[idx2];
            lastindex[idx]=i+1;
        }
    }
    return dp[str.length()];
}

//ques7. to print total no of subsequenced ways to make a compressed string of particular order===========
int compressedstr(string str){                  //this code doesnot work for strings starting with c as it should
    vi dp(27,0);                                //return 0 but it doesnt... so cheeck gfg.......
    dp[0]=1;
    int idx;
    for(int i=0;i<str.length();i++){
       idx=str[i]-'a'+1;
       dp[idx]=2*dp[idx]+dp[idx-1];
    }   
    return dp[idx];
}

// ques 8. mwiki(largest increasing subsequenced array)===========================
int max_=-99999;
int mwiki(vector<int>& arr){
    vi dp(arr.size()+1,0);
    dp[0]=1;
    for(int i=1;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i])
                max_=max(max_,dp[i]);
        }
        dp[i]=max_+1;
    }
return max_;
}

//ques 9. minimum pallindromic cuts required(memorisation)============================

int minPallindromic(string &str,int st,int end, vvi &dp,vvb&isPali){
    if(st==end || isPali[st][end]) return 0;
    if(dp[st][end]!=0) return dp[st][end];

    int min_=1e8;
    for(int cut=st;cut<end;cut++){
        int left=minPallindromic(str, st,cut,dp,isPali);
        int right=minPallindromic(str,cut+1,end,dp,isPali);
        int cost=left+right+1;
        min_=min(cost,min_);   
    }
    dp[st][end]=min_;
    return min_;
}

//ques 10. minimum pallindromic cuts required (tabulation)==========================
int minPallindromictab(string &str, vvi &dp,vvb&isPali){
   for(int gap=0;gap<str.length();gap++){
       for(int st=0,end=gap;end<str.length();st++,end++){
            if(st==end || isPali[st][end]) continue;
        
             int min_=1e8;
    for(int cut=st;cut<end;cut++){
        int left=dp[st][cut];
        int right=dp[cut+1][end];
        int cost=left+right+1;
        min_=min(cost,min_);   
    }
    dp[st][end]=min_;
       }
   } 
  
    return dp[0][str.length()-1];
}


int main(){
//  cout<<lpsubstring("babad")<<endl;
//  cout<<countsubstrings("babad");
//   cout<<largestPsubstring("babad");

//  cout<<lpsubsequence("pcbcmp");
//  cout<<largestPsubsequence("pcbcmp");
//  cout<<countsubsequence("babad");

//  cout<<LCsubstring("abcdgh","acdghr");
//  cout<<LCsubstring_01("abcdgh","acdghr");

//  cout<<LCsubsequence("abcdgh","acdghr");

//   cout<<digstring("geeksforgeeks","gks")<<endl;
//   cout<<digstring_01("geeksforgeeks","gks");
//  cout<<equistring("saturday","sunday");
//  cout<<distinctsubseq("ababca");
 cout<<compressedstr("abcc");
/*  vi arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7};
    cout<<mwiki(arr); */
   
/*    
    string str="abccbc";
    vvi dp(str.length(),vi(str.length(),0));
     vvb ispali=isPali(str);
  //  cout<<minPallindromic(str,0,str.length()-1,dp,ispali);  
  cout<<minPallindromictab(str,dp,ispali);  */

    return 0;
}