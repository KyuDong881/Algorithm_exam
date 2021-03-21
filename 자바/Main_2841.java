import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main_2841 {

	static int N,P;
	static StringTokenizer st;
	static ArrayList<Stack<Integer>> stacklist;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st=new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		P=Integer.parseInt(st.nextToken());
		
		stacklist = new ArrayList<>(N+1);
		for(int i=1;i<=N;i++) {
			stacklist.add(new Stack<Integer>());
		}
		while(true) {
			st = new StringTokenizer(br.readLine());
			int line = Integer.parseInt(st.nextToken());
			int pret = Integer.parseInt(st.nextToken());
			
//			stacklist.get(line).	
			
		}
	}

}
