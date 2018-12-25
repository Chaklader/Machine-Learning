package com.udemy.bruteforce;

public class BruteForce {

	private static final double START_X = -1;
	private static final double END_X = 2;
	// interval is [START_X, END_X] !!!
	
	public double f(double x) {
		return (x-1)*(x-1);
	}
	
	public void bruteForceSearch() {
		
		double startingPointX = START_X;
		double min = f( startingPointX );
		double dx = 0.01;
		double minX = START_X;
		
		for(double i=startingPointX;i<END_X;i+=dx) {
			
			if( f(i) < min ) {
				min = f(i);
				minX = i;
			}
				
		}
		
		System.out.println("The minimum value is f(x) = "+min+" and x = "+minX);
	}
}
