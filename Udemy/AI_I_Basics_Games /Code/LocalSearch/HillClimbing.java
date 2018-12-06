package com.balazsholczer.max;

public class HillClimbing {

	public static double f(double x){
		return -(x-1)*(x-1)+2;
	}
	
	public static void main(String[] args) {
		
		double dx = 0.01;
		double actualPointX = -2;
		double max = f( actualPointX );
		
		while( f(actualPointX+dx) >= max){
			max = f(actualPointX+dx);
			System.out.println("X:"+actualPointX+" y:"+f(actualPointX));
			actualPointX+=dx;
		}
		
		System.out.println("Min with hill climbing: "+max);
	}
}
