import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_14889 {

	static int N;
	static int[][] info;
	static int answer;
	static StringTokenizer st;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		info = new int[N][N];
		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				info[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		answer = Integer.MAX_VALUE;
		comb(0,0,0);
		
		System.out.println(answer);

	}

	private static void comb(int idx, int cnt,int flag) {
		if(cnt==N/2) {
			maketeam(flag);
			return;
		}
		for(int i=idx;i<N;i++) {
			if((flag&1<<i)!=0) continue;
			comb(i,cnt+1,flag|1<<i);
		}
	}

	private static void maketeam(int flag) {
		
		ArrayList<Integer> start = new ArrayList<>();
		ArrayList<Integer> link = new ArrayList<>();
		
		for(int i=0;i<N;i++) {
			if((flag&1<<i)!=0) {
				start.add(i);
			}else {
				link.add(i);
			}
		}
		int startsum=0;
		int linksum=0;
		
		for(int i=0;i<start.size();i++) {
			for(int j=0;j<start.size();j++) {
				int p1=start.get(i);
				int p2=start.get(j);
				startsum+=info[p1][p2];
			}
		}
		
		for(int i=0;i<link.size();i++) {
			for(int j=0;j<link.size();j++) {
				int p1=link.get(i);
				int p2=link.get(j);
				linksum+=info[p1][p2];
			}
		}
		
		answer = Math.min(answer, Math.abs(startsum-linksum));
		
		
	}

}
