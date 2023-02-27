/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(int i,int j,int len,vector<vector<int>>& grid){
        if(IsSame(i,j,len,grid)){
            return new Node(grid[i][j],1);
        }
        Node* root=new Node(grid[i][j],0);
        len/=2;
        root->topLeft=solve(i,j,len,grid);
        root->topRight=solve(i,j+len,len,grid);
        root->bottomLeft=solve(i+len,j,len,grid); 
        root->bottomRight=solve(i+len,j+len,len,grid);   
        return root;
    }
    bool IsSame(int i,int j,int len,vector<vector<int>>& grid){
        for(int x=i;x<i+len;x++){
            for(int y=j;y<j+len;y++){
                if(grid[i][j]!=grid[x][y])return 0;
            }
        }
        return 1;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(0,0,grid.size(),grid);
    }
};