import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1149 {

	static StringTokenizer st;
	static int[][] arr,dp;
	static int N;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		arr = new int[N+1][3];
		dp = new int[N+1][3];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<3;j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		System.out.println(dp(N));
	}

	private static int dp(int n) {
		
		dp[1][0]=arr[1][0];
		dp[1][1]=arr[1][1];
		dp[1][2]=arr[1][2];
		
		for(int i=2;i<=n;i++) {
			dp[i][0]=arr[i][0]+Math.min(dp[i-1][1], dp[i-1][2]);
			dp[i][1]=arr[i][1]+Math.min(dp[i-1][0], dp[i-1][2]);
			dp[i][2]=arr[i][2]+Math.min(dp[i-1][1], dp[i-1][0]);
		}
		
		int answer = Math.min(dp[n][0], Math.min(dp[n][1], dp[n][2]));
		
		return answer;
	}

}
