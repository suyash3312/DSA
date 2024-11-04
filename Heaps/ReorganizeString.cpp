class Solution {
public:
    class Info{
        public:
        char data;
        int count;

        Info(char ch, int freq){
            this -> data = ch;
            this -> count = freq;
        }
    };

    class compare{
        public:
        bool operator()(Info* a, Info* b){
            return a -> count < b -> count;
        }
    };

    string reorganizeString(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
        }
        priority_queue<Info*, vector<Info*>, compare>pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                Info* temp = new Info(i + 'a', freq[i]);
                pq.push(temp);
            }
        }
        string ans = "";
        while(pq.size() > 1){
            Info* first = pq.top();
            pq.pop();
            Info* second = pq.top();
            pq.pop();

            ans.push_back(first -> data);
            first -> count--;
            ans.push_back(second -> data);
            second -> count--;

            if(first -> count >= 1){
                pq.push(first);
            }
            if(second -> count >= 1){
                pq.push(second);
            }
        }
        if(pq.size() == 1){
            Info* remainingData = pq.top();
            pq.pop();
            ans = ans + remainingData -> data;
            remainingData -> count--;
            if(remainingData -> count != 0){
                return "";
            }
        }
        return ans;
    }
};