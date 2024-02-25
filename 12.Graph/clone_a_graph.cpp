void dfs(graphNode *node,graphNode*copy,vector<graphNode*>&visited){

    visited[copy->data] = copy;
    for(auto i:node->neighbours){
        if(visited[i->data]==NULL){
            graphNode* newNode = new graphNode(i->data);
            (copy->neighbours).push_back(newNode);
            dfs(i,newNode,visited);
        }
        else{
            (copy->neighbours).push_back(visited[i->data]);
        }
    }
}


graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.

	 if (!node)
    {
        return NULL;
    }

    vector<graphNode*>visited(10000,NULL);
    graphNode*copy = new graphNode(node->data);
    dfs(node,copy,visited);
    return copy;
}