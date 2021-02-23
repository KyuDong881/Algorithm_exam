import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1166 {

	static long N,L,W,H;
	static double answer;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		L=Integer.parseInt(st.nextToken());
		W=Integer.parseInt(st.nextToken());
		H=Integer.parseInt(st.nextToken());

		binary_search();
		System.out.println(answer);

	}

	private static void binary_search() {
		double left=0;
		double right=Math.max(L, Math.max(W, H));
		
		for(int i=0;i<10000;i++) {
			double mid = (left+right)/2;
			if((long)(L/mid)*(long)(W/mid)*(long)(H/mid)>=N) {
				left=mid;
			}
			
			else right=mid;
		}
		answer = left;
	}

}
