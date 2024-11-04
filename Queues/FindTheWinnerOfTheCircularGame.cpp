//Josephus Rule
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i=2; i<=n; i++){
            winner=(winner + k) % i;
        }
        return winner + 1;
    }
};
// Using Queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int>dq;
        for(int i=1; i<=n; i++){
            dq.push_back(i);
        }
        int temp=k;
        while(dq.size() != 1){
            int participant = dq.front();
            dq.pop_front();
            if(temp==1){
                temp=k;
            }else{
                temp--;
                dq.push_back(participant);
            }
        }
        return dq.front();
    }
};
