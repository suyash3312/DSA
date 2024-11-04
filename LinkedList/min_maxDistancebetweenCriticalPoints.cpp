class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return {-1, -1};
        }
        ListNode* prevNode=head;
        ListNode* currNode=prevNode->next;
        ListNode* nextNode=currNode->next;
        int CriticalPoints=0;
        int minDistance=0;
        int maxDistance=0;
        vector<int>Distances;
        vector<int>DistanceBetweenCriticalPoints;
        int position=2;
        while(nextNode!=NULL){
            if((currNode->val > prevNode->val && currNode->val > nextNode->val) || (currNode->val < prevNode->val && currNode->val < nextNode->val)){
                CriticalPoints++;
                Distances.push_back(position);
                prevNode=currNode;
                currNode=nextNode;
                nextNode=nextNode->next;
                position++;
            }
            else{
                prevNode=currNode;
                currNode=nextNode;
                nextNode=nextNode->next;
                position++;
            }
        }
        if(CriticalPoints<2){
            return {-1,-1};
        }
        else if(CriticalPoints==2){
            minDistance=maxDistance=Distances[Distances.size()-1] - Distances[0];
            DistanceBetweenCriticalPoints.push_back(minDistance);
            DistanceBetweenCriticalPoints.push_back(maxDistance);
        }
        else{
            maxDistance=Distances[Distances.size()-1] - Distances[0];
            minDistance=Distances[1]-Distances[0];
            for(int i=0; i<Distances.size()-1; i++){
                if(minDistance > (Distances[i+1] - Distances[i])){
                    minDistance=Distances[i+1] - Distances[i];
                }
            }
            DistanceBetweenCriticalPoints.push_back(minDistance);
            DistanceBetweenCriticalPoints.push_back(maxDistance);
        }
        return DistanceBetweenCriticalPoints;
    }
};
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return {-1, -1};
//         }

//         ListNode* prevNode = head;
//         ListNode* currNode = head->next;
//         int position = 2;  // Start from the second node
//         int firstCritical = -1;
//         int lastCritical = -1;
//         int minDistance = INT_MAX;

//         while (currNode->next != nullptr) {
//             if ((currNode->val > prevNode->val && currNode->val > currNode->next->val) ||
//                 (currNode->val < prevNode->val && currNode->val < currNode->next->val)) {
                
//                 if (firstCritical == -1) {
//                     firstCritical = position;
//                 } else {
//                     minDistance = min(minDistance, position - lastCritical);
//                 }
//                 lastCritical = position;
//             }
//             prevNode = currNode;
//             currNode = currNode->next;
//             position++;
//         }

//         if (lastCritical == -1 || firstCritical == lastCritical) {
//             return {-1, -1};
//         }

//         int maxDistance = lastCritical - firstCritical;
//         return {minDistance, maxDistance};
//     }
// };
