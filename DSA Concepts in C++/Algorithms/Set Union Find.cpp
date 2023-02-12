class Solution {
public:
    unordered_map<int, int> parent;
    
    void make_set(int val) {
        parent[val] = val;       
    }
    
    void union_set(int val1, int val2) {
        int x = find_set(val1);
        int y = find_set(val2);
        if(x != y) {
            parent[y] = x; 
        }
    }
    
    int find_set(int val) {
        if(parent[val] == val)
            return val;
        return parent[val] = find_set(parent[val]);
    }

    bool equationsPossible(vector<string>& equations) {
        for(auto i=0;i<26;i++) {
            make_set(i);
        }
        // call union_set function
        // call find_set function
        return true;
    }
};