void sortInsert(stack<int> &stack , int n){
   if(stack.empty() || (!stack.empty() && stack.top() < n)){
      stack.push(n);
      return ;
    }
   int num = stack.top();
   stack.pop();
   sortInsert(stack , n);
   stack.push(num);
}
 
void sortStack(stack<int> &stack){
   if(stack.empty() ){
        return ;
    }
   int num = stack.top();
   stack.pop();
   sortStack(stack);
   sortInsert(stack , num);
}