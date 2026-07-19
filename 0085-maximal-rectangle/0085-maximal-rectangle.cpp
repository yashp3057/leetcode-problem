class Solution {
public:
int largestrectanglearea(vector<int>& arr) {

    int n = arr.size();
    int maxarea = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] > arr[i]) {

            int ele = arr[st.top()];
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea, ele * (nse - pse - 1));
        }

        st.push(i);
    }

    while (!st.empty()) {

        int ele = arr[st.top()];
        st.pop();

        int nse = n;
        int pse = st.empty() ? -1 : st.top();

        maxarea = max(maxarea, ele * (nse - pse - 1));
    }

    return maxarea;
}

   int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    if (matrix.empty()) return 0;

      vector<int>height(m,0);
    int maxarea=0;  

      for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){

            if(matrix[i][j]=='1'){
                height[j]=1+height[j];
            }
            else{
                height[j]=0;
            }

        }
     int area=largestrectanglearea(height);
    maxarea=max(maxarea,area);

      }

return maxarea;
    }
};