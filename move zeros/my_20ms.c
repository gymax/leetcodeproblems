void moveZeroes(int* nums, int numsSize) {
    int head = 0;
    int tail = 0;
    int temp;
    
    while(tail<numsSize && head<(numsSize-1)){
        if(nums[head]==0){
            tail=head;
            while (tail<numsSize && head<(numsSize-1)){
                if(nums[tail]!=0){
                    temp=nums[tail];
                    nums[tail]=0;
                    nums[head]=temp;
                    break;
                }
                tail++;
            }    
        }
        head ++;
    }
    
}