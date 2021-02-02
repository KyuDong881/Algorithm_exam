package algo;

import java.util.Scanner;

public class Swea_1954 {

	public static int[][] board;
	public static int[]dx = {1,0,-1,0};
	public static int[]dy = {0,1,0,-1};
	public static int num;
	public static void main(String args[]) throws Exception
	{
		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			num = sc.nextInt();
			board = new int[num][num];
			recur(0,0,1,0);
			
			System.out.printf("#%d\n",test_case);
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					System.out.print(board[i][j]+" ");
				}
				System.out.println("");
			}

		}
		
	}
	
	public static void recur(int cx,int cy,int idx,int dir)
	{
		if(idx>num*num) {
			return;
		}
		
		board[cy][cx]=idx;
		int ny=cy+dy[dir];
		int nx=cx+dx[dir];
		if(ny<0||nx<0||ny>=num||nx>=num||board[ny][nx]!=0) {
			dir++;
			if(dir==4) dir=0;
			ny=cy+dy[dir];
			nx=cx+dx[dir];
		}
		
		recur(nx,ny,idx+1,dir);
		
	}
	
}
