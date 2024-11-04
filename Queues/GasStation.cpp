class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            balance = balance + (gas[i] - cost[i]);
            if(balance < 0){
                deficit += balance;
                balance = 0;
                start = i + 1;
            }
        }
        if(balance >= abs(deficit)){
            return start ;
        }else{
            return -1;
        }
    }
};