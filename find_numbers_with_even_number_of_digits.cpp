class Solution {
public:
    int findNumbers(vector<int>& nums) {
        unsigned int even_counter = 0, number_digits_counter;  

        for(int number: nums){
          number_digits_counter = 0;

          while(nums > 0){
            number_digits_counter++;
            nums[i]/=10;
          }

        if(number_digits_counter%2==0) even_counter++;
        }

        return even_counter;
    }
};
