import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_17779 {

	static int N;
	static int[][] board;
	static boolean[][] visit;
	static StringTokenizer st;
	static int answer;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		answer = 99999;
		board = new int[N+1][N+1];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine()," ");
			for(int j=1;j<=N;j++) {
				board[i][j]=Integer.parseInt(st.nextToken());
			}			
		}
		
		for(int x=1;x<=N;x++) {
			for(int y=1;y<=N;y++) {
				for(int d1=1;d1<N;d1++) {
					for(int d2=1;d2<N;d2++) {
						if(x+d1+d2>N||y-d1<1||y+d2>N) continue;
						cal(x,y,d1,d2);
					}
				}
			}
		}
		System.out.println(answer);
	}
	
	private static void cal(int x, int y, int d1, int d2) {
		int[] count = new int[5];
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if(i<x+d1&& j<=y && !(i>=x && j-y>=-i+x)) {
					count[0] += board[i][j];
				}
				
				else if(i<=x+d2 && j>y&&!(i>=x&&j-y<=i-x)) {
					count[1] += board[i][j];
				}
				else if(i>=x+d1 && j<y-d1+d2&&!(i<=x+d1+d2&&j-(y-d1+d2)>=-(x+d1+d2-i))) {
					count[2] += board[i][j];
				}
				else if(i>x+d2 && j>=y-d1+d2&&!(i<=x+d1+d2&&j-(y-d1+d2)<=x+d1+d2-i)) {
					count[3] += board[i][j];
				}
				else {
					count[4] +=board[i][j];
				}
				
			}
		}
		
		Arrays.sort(count);
		int value = count[4]-count[0];
		answer = Math.min(answer, value);
	}

}
