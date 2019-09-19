enqueue(tp);
while(Queue not empty){
    x = dequeue(Queue);
    print(x);
    if(x->left)
        enqueue(Queue, x->left);
    if(x->right)
        enqueue(Queue, x->right);

}







