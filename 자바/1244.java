package hw08;

import java.util.Scanner;

/***
 * 1~스위치 0아니면1인 상태
 * 학생들에게 번호 줌
 * 남1 : 스위치번호가 자기 받은 수의 배수이면 상태 체인지
 * 여2 : 자기수 좌우 대칭이면서 가장 많은 스위치를 포함하는 구간 전부 체인지
 * 
 * 스위치 상태 출력 20개씩
 */
public class Main {

	public static int answer;
	public static int[]switch_arr;
	public static int students;
	public static int switchs;
	
	public static int switchChange_m(int state) {
		if(state==1) return 0;
		else return 1;
	}
	
	public static int switchChange_f(int state) {
		if(state==1) return 0;
		else return 1;
	}
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		switchs = sc.nextInt();
		switch_arr = new int[switchs+1];
		
		for(int i=1;i<=switchs;i++) {
			switch_arr[i]=sc.nextInt();
		}
		students=sc.nextInt();
		int sex,switch_index;
		for(int i=0;i<students;i++) {
			sex=sc.nextInt();
			switch_index=sc.nextInt();
		
			if(sex==1 ) {
				int count=1;
				while(true) {
					if(switch_index*count>switchs) break;
					switch_arr[switch_index*count] = switchChange_m(switch_arr[switch_index*count]);		
					count++;
				}
			}
			
			else {
				int dist=1;
				switch_arr[switch_index] = switchChange_m(switch_arr[switch_index]);	
				while(true) {
					if(switch_index-dist<1||switch_index+dist>switchs) break;
					
					if(switch_arr[switch_index+dist]==switch_arr[switch_index-dist]) {
						switch_arr[switch_index+dist] = switchChange_m(switch_arr[switch_index+dist]);	
						switch_arr[switch_index-dist] = switchChange_m(switch_arr[switch_index-dist]);	
					}
					else break;
					dist++;
				}
			}
			
		}
		
		for(int i=1;i<=switchs;i++) {
			if(i>1&&i%20==1)System.out.println();
			System.out.print(switch_arr[i]+" ");
		}
		
		
	}

}
