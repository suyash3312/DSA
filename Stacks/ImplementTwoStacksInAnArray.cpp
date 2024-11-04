class twoStacks {
  public:
    int* arr;
    int size;
    int top1, top2;
    
    twoStacks(int size) {
        int arr=new int[size];
        top1=-1;
        top2=size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top2-top1 == 1){
            return;
        }else{
            arr[++top1]=x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2-top1 == 1){
            return;
        }else{
            arr[--top2]=x;
        }
        
    }

    // Function to remove an element from top of the stack1.
    void pop1() {
        if(top1==-1){
            return -1;
        }else{
            arr[top1]=0;
            top1--;
        }
    }

    // Function to remove an element from top of the stack2.
    void pop2() {
        if(top2==size){
            return -1;
        }else{
            arr[top2]=0;
            top2++;
        }
    }
};