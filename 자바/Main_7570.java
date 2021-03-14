import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_7570 {

	static int[] dp;
	static int N;
	static StringTokenizer st;
	static int max;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		dp = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			int value = Integer.parseInt(st.nextToken());
			dp[value] = dp[value-1]+1;
		}
		Arrays.sort(dp);
		System.out.println(N-dp[N]);
				
	}

}
