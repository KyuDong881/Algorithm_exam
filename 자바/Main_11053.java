import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main_11053 {

	static int N;
	static StringTokenizer st;
	static int[] dp;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		dp = new int[N];
		// 값을 인덱스로하는 배열?
		// 배열의값 => 길이
		int answer=0;
		for(int i=0;i<N;i++) {
			dp[i]=1;
			for(int j=0;j<i;j++) {
				if(arr[j]<arr[i]) {
					dp[i]=Math.max(dp[i], dp[j]+1);
				}
			}
			answer = Math.max(dp[i], answer);
		} //n제곱
		
		System.out.println(answer);
		
	}

}
