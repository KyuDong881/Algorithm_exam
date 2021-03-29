import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_10942 {

	static int N,M;
	static StringTokenizer st;
	static int[] arr;
	static boolean[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		arr = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		dp = new boolean[N+1][N+1];
		for (int i = 1; i <= N; i++) {
			dp[i][i] = true;
		}
		
		M=Integer.parseInt(br.readLine());
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			if(dp(start,end)) sb.append("1\n");
			else sb.append("0\n");
		}
		System.out.println(sb.toString());

	}

	private static boolean dp(int start, int end) {
		if (dp[start][end] == false) {
			if (start == end) {
				dp[start][end] = true;
			} else if (start + 1 == end) {
				if (arr[start] == arr[end])
					dp[start][end] = true;
			} else if (arr[start] == arr[end]) {
				dp[start][end] = dp(start + 1, end - 1);
			}
		}
		return dp[start][end];
	}

}
