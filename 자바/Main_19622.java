import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_19622 {
	
	static int N,maxval;
	static StringTokenizer st;
	static int[] dp,arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N=Integer.parseInt(br.readLine());
		arr = new int[N+1];
		dp = new int[N+1];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			st.nextToken();
			st.nextToken();
			arr[i] = Integer.parseInt(st.nextToken());
		}
		if(N==1) {
			System.out.println(arr[1]);
		}
		else if(N==2) {
			System.out.println(Math.max(arr[1], arr[2]));
		}
		else {
			dp[1]=arr[1];
			dp[2]=Math.max(arr[1], arr[2]);
			for(int i=3;i<=N;i++) {
				dp[i] = Math.max(dp[i-2]+arr[i], dp[i-1]);
				maxval = Math.max(dp[i], maxval);
			}
			System.out.println(maxval);
		}	
	}
}