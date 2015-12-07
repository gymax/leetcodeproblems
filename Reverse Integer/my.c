int reverse(int x) {
    long int ans;
    int negative=0;
    char str[32];
    if(x<0) negative=1;
    abs(x);
 
	sprintf(str,"%d",x);
	strrevs(str);
	ans=atol(str); 

    
    if((ans > INT_MAX || ans < INT_MIN))
    return 0;
    
    if(negative)
    return -ans;
    else
    return ans;
}
void strrevs(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(string);
   begin  = string;
   end    = string;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

int abs(int input)
{
    if(input<0){
        return -input;
    }else{
        return input;
    }
}int reverse(int x) {
    long int ans;
    int negative=0;
    char str[32];
    if(x<0) negative=1;
    abs(x);
 
	sprintf(str,"%d",x);
	strrevs(str);
	ans=atol(str); 

    
    if((ans > INT_MAX || ans < INT_MIN))
    return 0;
    
    if(negative)
    return -ans;
    else
    return ans;
}
void strrevs(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(string);
   begin  = string;
   end    = string;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

int abs(int input)
{
    if(input<0){
        return -input;
    }else{
        return input;
    }
}