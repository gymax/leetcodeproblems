class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = calIntersection(A, C, E, G);
        int y = calIntersection(B, D, F, H);
        return (C-A)*(D-B)+(G-E)*(H-F)-x*y;
    }
private:
    int calIntersection(int a1, int a2, int b1, int b2){
        int left = max(a1, b1);
        int right = min(a2, b2);
        return (right > left)*(right - left);
    }
};