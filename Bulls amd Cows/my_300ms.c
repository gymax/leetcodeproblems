char* getHint(char* secret, char* guess) {
    char* ans;
    char* pguess = guess;  
    char* psecret = secret;  
    char* psecret2 = secret; 
    int countA = 0;
    int countB = 0;
    int i;
    int Bsecret [strlen(secret)];
    int Bcheck [10];
    int breakpoint = 0;
    for(i=0;i<10;i++)
    {
    	Bcheck[i]=0;
    }
    for(i=0;i<strlen(secret);i++)
    {
    	Bsecret[i]=0;
    }
	// check A
    while(pguess - guess < strlen(guess))
    {
    	if(memcmp(pguess,psecret2 ,1)==0)
    	{
    		countA++;
    		Bsecret[psecret2-secret]=1;
    	}   
    	pguess++;
    	psecret2++;
    }	
    pguess=guess;
    psecret2=secret;
    // check B
    while(pguess - guess < strlen(guess))
    {
    	if(memcmp(pguess,psecret2 ,1)==0){
			goto end;
    	}
    		breakpoint = 0;
     		while(psecret - secret < strlen(secret))
    		{
    			if(memcmp(pguess,psecret ,1)==0)
    			{
    				if(Bsecret[psecret-secret]==0){ // if not match B yet
    					Bcheck[*pguess-'0']+=1;
    					Bsecret[psecret-secret]=1;
    					breakpoint = 1;
    				}
    			}
    			if(breakpoint) break;
    			psecret++;
    		}
    		psecret = secret;
 end:  
		psecret2++;
    	pguess++;
    }
    
    for(i=0;i<10;i++)
    {
    	if(Bcheck[i]!=0)
    		countB+=Bcheck[i];
    }
    
    ans = malloc(sizeof(char)*16);
    sprintf(ans,"%dA%dB",countA,countB);
    return ans;
}