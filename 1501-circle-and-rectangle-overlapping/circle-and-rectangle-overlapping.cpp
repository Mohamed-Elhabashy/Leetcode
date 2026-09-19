class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestx = max( min(x1,x2) , min( xCenter ,  max(x1,x2) ));
        int closesty = max( min(y1,y2) , min( yCenter ,  max(y1,y2) ));
        int dis = (abs(xCenter-closestx) * abs(xCenter-closestx) ) + (abs(yCenter-closesty) * abs(yCenter-closesty) );
        return dis<= (radius*radius);
    }
};