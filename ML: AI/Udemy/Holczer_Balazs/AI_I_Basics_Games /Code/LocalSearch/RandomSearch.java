package com.balazsholczer.max;

import java.util.Random;

public class RandomSearch {

	public static double f(double x){
		return x*x;
	}
	
	public static void main(String[] args) {
		
		Random random = new Random();
		double startPointX = 0;
		double max = f( startPointX );
		
		for(int i=0;i<10000;i++){
			
			double point = 2*random.nextDouble();
			
			if( f(point) > max ){
				max = f(point);
			}
		}
		
		System.out.println("Maximum is: "+max);
	}
}
