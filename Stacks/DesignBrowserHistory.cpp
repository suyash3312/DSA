class BrowserHistory {
public:
    stack<string>BrowserStack, fwdStack;
    BrowserHistory(string homepage) {
        BrowserStack.push(homepage);
    }
    
    void visit(string url) {
        while(!fwdStack.empty()){
            fwdStack.pop();
        }
        BrowserStack.push(url);
    }
    
    string back(int steps) {
        while(steps--){
            if(BrowserStack.size() > 1){
                fwdStack.push(BrowserStack.top());
                BrowserStack.pop();
            }
            else{
                break;
            }
        }
        return BrowserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(fwdStack.size() > 0){
                BrowserStack.push(fwdStack.top());
                fwdStack.pop();
            }
            else{
                break;
            }
        }
        return BrowserStack.top();
    }
};