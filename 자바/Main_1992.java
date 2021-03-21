import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main_1992 {

	static int N;
	static char[][] board;
	static StringTokenizer st;
	static StringBuilder sb;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N= Integer.parseInt(br.readLine());
		sb = new StringBuilder();
		board = new char[N][N];
		
		for(int i=0;i<N;i++) {
			String str = br.readLine();
			for(int j=0;j<N;j++) {
				board[i][j] = str.charAt(j);
			}
		}
		dfs(0,0,N);
		System.out.println(sb.toString());
		
	}

	
	private static void dfs(int srow,int scol,int dist) {
		
		boolean one = true;
		boolean zero = true;
		
		for(int i=srow;i<srow+dist;i++) {
			for(int j=scol;j<scol+dist;j++) {
				if(board[i][j]=='0') one = false;
				if(board[i][j]=='1') zero = false;
			}
		}
		
		if(one) {
			sb.append('1');
			return;
		}
		
		if(zero) {
			sb.append('0');
			return;
		}
		
		sb.append('(');
		dfs(srow,scol,dist/2);
		dfs(srow,scol+dist/2,dist/2);
		dfs(srow+dist/2,scol,dist/2);
		dfs(srow+dist/2,scol+dist/2,dist/2);
		sb.append(')');
	}
	
}
