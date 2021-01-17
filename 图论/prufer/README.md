# Prufer序列
## Definition:
对于一棵n个结点的标定树(结点带有编号)，其prufer序列是一个长为n-2,值域为[1,n]的整数序列。  
树和prufer序列是一一对应的双射关系。  
## 建立prufer序列：
### O(nlogn)复杂度:   
**Algorithm:** 使用堆建树。   
1.从树上选择编号最小的**叶子结点**，序列的下一位为其父节点的编号。  
2.删除该叶结点。  
3.重复1和2，直到树上只剩余两个结点，此时序列长度刚好为n-2。 
    
### 线性复杂度:
**Algorithm:**  维护一个指针p，初始时p指向编号最小的叶节点。同时维护每个结点的度数。  
1.删除p指向的结点，然后检查是否会产生新的叶节点。  
2.如果产生新的叶结点，假设编号为x，比较p和x的大小关系。如果x>p，不做操作；否则删除x，检查是否产生新的叶节点，重复操作2。  
3.让指针自增，直到遇到一个编号最小的且未被删除的叶结点为止。

    vector<vector<int>> adj;
    vector <int>parent;

    void dfs(int v){
        for(int u:adj[v]){
            if(u!=parent[v])parent[u]=v,dfs(u);
        }
    }
    vector<int>prufer_code(){
        int n=adj.size();
        parent.resize(n),parent[n-1]=-1;
        dfs(n-1);

        int ptr=-1;
        vector<int>degree(n); //维护每个结点的度
        for(int i=0;i<n;i++){
            degree[i]=adj[i].size();
            if(degree[i]==1&&ptr==-1) ptr=i;
        }
        vector<int>code(n-2);
        int leaf=ptr;
        for(int i=0;i<n-2;i++){
            int next=parent[leaf];
            code[i]=next;
            if(--degree[next]==1&&next<ptr){//若新增叶结点
                leaf=next;
            }else{
                ptr++;
                while(degree[ptr]!=1)ptr++;//寻找编号最小且未被删除的叶子结点
                leaf=ptr;
            }
        }
        return code
    }
**Note:**1.算法在于该树的编号恰好是[1,n]之间的n个整数。 2.若新增叶结点，只可能是被删结点的父节点。3.算法复杂度为O(n)，因为每条边最多被访问一次，且指针最多遍历每个结点一次。  


