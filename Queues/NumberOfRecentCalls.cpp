class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        return q.size();
    }
};
// MY SOLUTION
// class RecentCounter {
// public:
//     queue<int>q;
//     RecentCounter() {
        
//     }
    
//     int ping(int t) {
//         int start = t - 3000;
//         int end = t;
//         queue<int> temp;
//         q.push(t);
//         temp=q;
//         int pingCounter=0;
//         while(!temp.empty()){
//             if(temp.front() >= start && temp.front() <= end){
//                 pingCounter++;
//                 temp.pop();
//             }
//             else{
//                 temp.pop();
//             }
//         }
//         return pingCounter;
//     }
// };