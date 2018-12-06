package com.balazsholczer.max;



public class BasicSearch {

	public static double f(double x){
		return -(x*x);
	}
	
	public static void main(String[] args) {
		
		double startPointX = -2;
		double max = f( startPointX );
		
		for(double i = startPointX ; i < 2 ; i+=0.1){
			
			if( f(i) > max ){
				max = f(i);
			}
		}
		
		System.out.println("Maximum is: "+max);
	}
}
