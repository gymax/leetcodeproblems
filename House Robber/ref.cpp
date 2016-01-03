class Solution {
public:
    int rob(vector<int>& nums) {
    int total(0),pre_total(0);
    for(int val : nums){
        int ptotal = total;
        total = max(ptotal, pre_total+val);  // rob[i] = max(rob[i-1],rob[i-2]+val)
        pre_total = ptotal;
    }
    return total;
    }
};

/*--------------------------------------------*/
/* rob[i] 表示第i天時如果選rob的累計結果
   rest[i] 表示第i天時如果選rest的累計結果
   rob[i] = max(rob[i-1],rest[i-1]+val), rob[i-1]這時表示前一天rob所以i選rob不加val
   rest[i]= max(rest[i-1],rob[i-1]),
   且 rest[i-1] <= rob[i-1], 得rest[i]=rob[i-1]
   代回 rob[i] = max(rob[i-1],rob[i-2]+val),
/*
/*--------------------------------------------*/