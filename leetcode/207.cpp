class Solution { // topological sort, using DFS
public:
    vector<int> pos_schd; // possible schedule
    bool flag;

    struct node{ // make courses like a directed graph
        stack<int> next;
        int color = 0; // 0:white, 1:gray 2:black
    };

    void dfs(vector<node> &vec, int index){
        if(!flag)
            return;

        if(vec[index].color == 2) // black: deadend
            return;
        else if(vec[index].color == 1){ // gray: back edge, illegal
            flag = false;
            return;
        }

        while(!vec[index].next.empty()){
            vec[index].color = 1;
            dfs(vec, vec[index].next.top());
            vec[index].next.pop();
            
            if(!flag)
                return;
        }

        if(vec[index].next.empty()){
            vec[index].color = 2;
            pos_schd.push_back(index);
            return;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<node> vec(numCourses);
        flag = true;

        for(int count = 0; count < prerequisites.size(); count++) // make directed graph, [0, 1] == 1->0
            vec[prerequisites[count][1]].next.push(prerequisites[count][0]);
        
        for(int count = 0; count < numCourses; count++){
            dfs(vec, count);
            if(!flag)
                return false;
        }

        if(pos_schd.size() == numCourses)
            return true;
        return false;
    }
};
