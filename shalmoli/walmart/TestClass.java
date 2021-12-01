import java.io.*;
import java.util.*;


public class TestClass {
    public static int count=0;

    public static int solve(int i,int j, int[][] store, int[][] vis, int m,int n) {
      if (!(i<m && i>=0 && j<n && j>=0)) return 0;

      if (store[i][j]==1) return 0;

      if (store[i][j]==2) TestClass.count++;
      vis[i][j]=1;
  if (i==m-1 && j==n-1) return 0;
      if (j+1<n && vis[i][j+1]==0) solve(i,j+1,store, vis,m,n);
      if (i+1<m && vis[i+1][j]==0) solve(i+1,j,store, vis,m,n);
      if (j-1>=0 && vis[i][j-1]==0) solve(i,j-1,store, vis,m,n);
      if (i-1>=0 && vis[i-1][j]==0) solve(i-1,j,store, vis,m,n);

      return 1;
  }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
         String[] x = br.readLine().split(" ");
         int m = Integer.parseInt(x[0]);
         int n = Integer.parseInt(x[1]);
         int[][] A = new int[m][n];
         for(int i_A = 0; i_A < m; i_A++)
         {
           String[] arr_A = br.readLine().split(" ");
           for(int j_A = 0; j_A < arr_A.length; j_A++)
           {
             A[i_A][j_A] = Integer.parseInt(arr_A[j_A]);
           }
         }
         int t = Integer.parseInt(br.readLine().trim());
         int[][] C = new int[t][2];
         for(int i_C = 0; i_C < t; i_C++)
         {
           String[] arr_C = br.readLine().split(" ");
           for(int j_C = 0; j_C < arr_C.length; j_C++)
           {
             C[i_C][j_C] = Integer.parseInt(arr_C[j_C]);
           }
         }

         int out_ = solve_main(m, n, A, t, C);
         System.out.println(out_);

         wr.close();
         br.close();
    }
    static int solve_main(int m, int n, int[][] A, int t, int[][] C){
       // Write your code here
        for(int i=0;i<t;i++) {
          int x = C[i][0];
          int y = C[i][1];
          A[x][y]=2;
        }

        int[][] vis = new int[m][n] ;

        for(int i=0;i<m;i++) {
          for(int j=0;j<n;j++) {
            vis[i][j]=0;
          }
        } 

        solve(0,0,A,vis,m,n);



        return TestClass.count;
    
    }
}