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
/* rob[i] ��ܲ�i�Ѯɦp�G��rob���֭p���G
   rest[i] ��ܲ�i�Ѯɦp�G��rest���֭p���G
   rob[i] = max(rob[i-1],rest[i-1]+val), rob[i-1]�o�ɪ�ܫe�@��rob�ҥHi��rob���[val
   rest[i]= max(rest[i-1],rob[i-1]),
   �B rest[i-1] <= rob[i-1], �orest[i]=rob[i-1]
   �N�^ rob[i] = max(rob[i-1],rob[i-2]+val),
/*
/*--------------------------------------------*/