class Solution {
public:
    int combi(int r, int n){
        int p = 1;
        int i;
        for(i = 1; i <= n; i++) {
            p = p * (r - i + 1) / i;
        }
        return p;
    }    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1);
            for(int j=0;j<i+1;j++){
                row[j]=combi(i,j);
            }
            ans.push_back(row);
        }    
        return ans;
    }
};