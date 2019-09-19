postfix evaluation

20 10 30 + *  ->  20*(10+30) = 800

stateful
stateless

while(c = gettoken()){
    if(isOperator)
        printf...

    else if(isLeftP(c))
        push(c);

    else if(isRightp(c)){
        while((r = pop()) != '('){
            print(c);
        }
    }

    else if(isOpr(c)){
        while(priority(stacktop()) >= priority(c)){
            Y = pop();
            print(Y);
        }
    }
}

1 . string pointer
2 . linked list
3 . stack queue

HTTP : Hyper Text Transfer Protocal
URI  : Uniform Resource Identifier
HTML : Hyper Text Markup Language




