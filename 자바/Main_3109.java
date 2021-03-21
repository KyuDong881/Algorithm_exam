import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_3109 {

	static int r,c;
	static char[][] board;
	static StringTokenizer st;
	static int[] dy = {-1,0,1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		r=Integer.parseInt(st.nextToken());
		c=Integer.parseInt(st.nextToken());
		String str;
		board = new char[r][c];
		for(int i=0;i<r;i++) {
			str = br.readLine();
			for(int j=0;j<c;j++) {
				board[i][j] = str.charAt(j);
			}
		}
		
	}

}
