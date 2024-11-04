class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle cases where the head itself is part of a zero-sum sublist
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        std::unordered_map<int, ListNode*> prefixSumMap;
        ListNode* curr = dummy;
        int prefixSum = 0;

        // Traverse the list and use a prefix sum hash map
        while (curr != nullptr) {
            prefixSum += curr->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                // If the current prefix sum has been seen before,
                // then there's a zero-sum sublist between the last occurrence and here.
                ListNode* start = prefixSumMap[prefixSum]->next;
                int sum = prefixSum;
                // Remove nodes in the zero-sum sublist from the hash map
                while (start != curr) {
                    sum += start->val;
                    prefixSumMap.erase(sum);
                    start = start->next;
                }
                // Remove the zero-sum sublist
                prefixSumMap[prefixSum]->next = curr->next;
            } else {
                // Add the current prefix sum to the map
                prefixSumMap[prefixSum] = curr;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};