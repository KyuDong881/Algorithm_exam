import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2563 {

	static int[][]board;
	static int N;
	static StringTokenizer st;
	static int answer;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		int x,y;
		board = new int[100][100];
		for(int paper=0;paper<N;paper++) {
			st = new StringTokenizer(br.readLine()," ");
			x=Integer.parseInt(st.nextToken());
			y=Integer.parseInt(st.nextToken());
			for(int i=y;i<y+10;i++) {
				for(int j=x;j<x+10;j++) {
					board[i][j]++;
				}
			}
			
		}
		
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(board[i][j]>0) answer++; 
			}
		}
		System.out.println(answer);
		
	}

}
