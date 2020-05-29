class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        vector<int> hash(127,-1);
        int ret=INT_MIN;
        int prev=0;
        for(int i=0;i<s.size();i++)
        {
            int x=s[i];
            if(hash[x]==-1)         //check if character has already occured
            {
                if(((i+1)-prev)>ret)    
                    ret=((i+1)-prev);   //updating max 
                hash[x]=(i+1);  //storing "latest" index of character
            }
            else
            {
                if(hash[x]<prev)     // Case when the character is repeated but lies before the last                                           repeated character
                {
                       if(((i+1)-prev)>ret) 
                    ret=((i+1)-prev);
                }
                else
                prev=hash[x];      // if new repeated character shortens the string i.e. lies after                                      the last repeated character , prev variable is set to that index                                       number so when counting max we subtract the current index by this                                     "prev" to get the running window lenght 
                hash[x]=(i+1);
            }
        }
        return ret;
        
        
    }
};
