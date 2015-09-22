int *twoSum(int numbers[], int n, int target) {
        int * temp = (int *)malloc (sizeof(int)*n);;
	    int result[2];
	    int i;
	    for( i=0;i<n;i++)
            temp[i]=numbers[i];
        sort(temp.begin(),temp.end());
        int p_start = 0;
        int p_end = n-1;
        int a,b,sum;
        while(true){
            int sum = temp[p_start]+temp[p_end];
            if(sum==target){
                a = temp[p_start];
                b = temp[p_end];
                break;
            }
            else if (sum<target){
                p_start ++;
            }
            else if(sum>target){
                p_end --;
            }
            if(p_end<0||p_start>=n)
                break;
        }

        for(i=0;n;i++)
            if(numbers[i]==a){
                a = i;
                break;
            }
        for(i=0;n;i++)
            if(numbers[i]==b&&i!=a){
                b = i;
                break;
            }
        if(a<b){
            result[0]=a+1;
            result[1]=b+1;
        }
        else{
            result[0]=b+1;
            result[1]=a+1;
        }
        return result;
}
