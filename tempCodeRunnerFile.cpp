p->hight = max(getHight(p->lchild),getHight(p->rchild)) + 1;
    // int bf = BalanceFac(p);
    
    // //perform rotation
    // if(BalanceFac(p)==2 && BalanceFac(p->lchild)==1)    LLRotation(p);
    // if(BalanceFac(p)==-2 && BalanceFac(p->lchild)==-1)    RRRotation(p);
    // if(BalanceFac(p)==2 && BalanceFac(p->lchild)==-1)    LRRotation(p);
    // if(BalanceFac(p)==-2 && BalanceFac(p->lchild)==1)    RLRotation(p);