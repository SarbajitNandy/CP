import java.io.*;
import java.util.Scanner;

public class p1 {

	public static int count=0;

	public static int solve(int i,int j, int[][] store, int[][] vis, int m,int n) {
		if (!(i<m && i>=0 && j<n && j>=0)) return 0;

		if (store[i][j]==1) return 0;


		if (store[i][j]==2) p1.count++;
		vis[i][j]=1;
		if (i==m-1 && j==n-1) return 0;

		if (j+1<n && vis[i][j+1]==0) solve(i,j+1,store, vis,m,n);
		if (i+1<m && vis[i+1][j]==0) solve(i+1,j,store, vis,m,n);
		if (j-1>=0 && vis[i][j-1]==0) solve(i,j-1,store, vis,m,n);
		if (i-1>=0 && vis[i-1][j]==0) solve(i-1,j,store, vis,m,n);

		return 1;
	}

	public static void main(String[] args) {
		// System.setIn(new FileInputStream(new File("in.txt")));
		// System.setOut(new PrintStream(new File("out.txt")));
		// System.setErr(new PrintStream(new File("error.txt")));

		Scanner sc = new Scanner(System.in);

		int m = sc.nextInt(),n= sc.nextInt() ;

		int[][] store = new int[m][n] ;
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				store[i][j]=sc.nextInt();
			}
		} 

		int q=sc.nextInt();
		int x,y;
		for(int i=0;i<q;i++) {
			x=sc.nextInt();
			y=sc.nextInt();

			store[x][y]=2;
		}

		int[][] vis = new int[m][n] ;

		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				vis[i][j]=0;
			}
		} 

		solve(0,0,store, vis,m,n);

		System.out.print(p1.count);

	}
}