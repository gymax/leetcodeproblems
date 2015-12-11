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
    for (i=0;i<strlen(s);++i){
        abc[s[i]-'a']++;
        abc2[t[i]-'a']++;
    }
    for (i=0;i<26;++i){
        if(abc[i]!=abc2[i]) sum++;
    }      
    return !sum;
}