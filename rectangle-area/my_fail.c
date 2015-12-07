int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int ans;
    //x: A,C,E,G
    //y: B,D,F,H
    int xof1, yof1, xof2, yof2, area1 ,area2, coverOfx=0, coverOfy=0,areaC,coverd=0,yofc1,xofc1,yofc2,xofc2;
    int minDst,curDst;
    xof1 = abs(A-C);
    yof1 = abs(D-B);
    xof2 = abs(E-G);
    yof2 = abs(H-F);
    area1 = yof1*xof1;
    area2 = xof2*yof2;
    
    xofc1 = (A+C);
    yofc1 = (D+B);
    
    xofc2 = (E+G);
    yofc2 = (H+F);
    
    minDst = (xof1+xof2)*(xof1+xof2)+(yof1+yof2)*(yof1+yof2);
    curDst = abs(xofc1-xofc2)*abs(xofc1-xofc2)+abs(yofc1-yofc2)*abs(yofc1-yofc2);
    
    if(minDst>curDst)
        coverd=1;
    /*(if(  
        coverd=0;
 
     if(abs(C-E)<(xof1+xof2) || abs(B-H)<(yof1+yof2))
        coverd=1;

    if(abs(A-G)<(xof1+xof2) || abs(D-F)<(yof1+yof2))
        coverd=1;

    if(abs(C-E)<(xof1+xof2) || abs(D-F)<(yof1+yof2))
        coverd=1;
    */
    
    if(coverd){
    if(A<=E && C<G)
      coverOfx= xof1 - (abs(A-E));
    else if(A<=E && C>G)
      coverOfx= xof2;
    else if(A>=E && C>G) 
      coverOfx= xof1 - (abs(C-G));
    else if(A>=E && C<G) 
      coverOfx= xof1;
    else if(A==E && C==G) 
      coverOfx= xof1;

    if(B<=F && D<H)
      coverOfy= yof1 - (abs(F-B));
    else if(B<=F && D>H)
      coverOfy= yof2;
    else if(B>=F && D>H) 
      coverOfy= yof1 - (abs(D-H));
    else if(B>=F && D<H) 
      coverOfy= yof1;
    else if(B==F && D==H) 
      coverOfy= yof1;          
    }

    areaC=coverOfx*coverOfy;
    
    if(area1==0||area2==0){
        areaC=0;
    }
    
    ans= area1+area2-abs(areaC);
    return ans;
}

int abs(int input)
{
    if(input<0){
        return -input;
    }else{
        return input;
    }
}