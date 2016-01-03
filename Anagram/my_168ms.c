bool isAnagram(char* s, char* t) {
    int i,sum=0;
    int abc[26];
    int abc2[26];
    int lens=strlen(s);
    int lent=strlen(t);
    
    if(lens!=lent) return false;
    
    for (i=0;i<26;++i){
        abc[i]=0;
        abc2[i]=0;
    }
    for (i=0;i<strlen(s);++i){ //keep strlen() here will add many compute cast
        abc[s[i]-'a']++;
        abc2[t[i]-'a']++;
    }
    for (i=0;i<26;++i){
        if(abc[i]!=abc2[i]) return false;
    }      
    return true;
}
2.

bool isAnagram(char* s, char* t) {
        int flag[26][2]={0};
    int lens=strlen(s);
    int lent=strlen(t);
    
    if(lens!=lent) return false;
        for(int i=0;i<lens;i++)
        {
            flag[s[i]-'a'][0]++;
            flag[t[i]-'a'][1]++;
        }
        for(int i=0;i<26;i++)
        {
            if(flag[i][0]!=flag[i][1])
                return false;
        }
        return true;
}

3. bit map
#define BITSPERWORD 32  
#define SHIFT 5  
#define MASK 0x1F  
#define N 10000000  
int a[1 + N/BITSPERWORD]; 
void set_(int i) {        a[i>>SHIFT] |=  (1<<(i & MASK)); }  
void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }   //SHIFT and MASK are for negative value
int  test(int i){ return a[i>>SHIFT] &   (1<<(i & MASK)); }  


class Solution {

public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)return false;
        int i;  
        for (i = 0; i < nums.size(); i++)  
            clr(nums[i]);    
        for (i = 0; i < nums.size(); i++)  
        {
            if(test(nums[i]))return true;
            else set_(nums[i]);  
        }
        return false;
    }