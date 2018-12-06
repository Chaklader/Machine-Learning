package com.balazsholczer.sa;

import java.util.Random;

public class SimulatedAnnealing {

	private Random randomGenerator;
	private double currentCoordinateX;
	private double nextCoordinateX;
	private double bestCoordinateX;
	
	public void findOptimum() {
		
		double temperature = Constants.MAX_TEMPERATURE;
		
		while( temperature > Constants.MIN_TEMPERATURE ) {
			
			nextCoordinateX = getRandomX();
			
			double actualEnergy = getEnergy(currentCoordinateX);
			double newEnergy = getEnergy(nextCoordinateX);
			
			if( acceptanceProbability(actualEnergy, newEnergy, temperature) > Math.random() ) {
				currentCoordinateX = nextCoordinateX;
			}
			
			if( f(currentCoordinateX) > f(bestCoordinateX) )
				bestCoordinateX = currentCoordinateX;
			
			temperature *= 1 - Constants.COOLING_RATE;
		}
		
		System.out.println("Global extremum guess: x="+bestCoordinateX+" f(x)="+f(bestCoordinateX));
	}
	
	private double getRandomX() {
		return randomGenerator.nextDouble()*(Constants.MAX_COORDINATE - Constants.MIN_COORDINATE) + Constants.MIN_COORDINATE;
	}

	public SimulatedAnnealing() {
		this.randomGenerator = new Random();
	}
	
	public double getEnergy(double x) {
		return f(x);
	}
	
	public double f(double x) {
		return (x-0.3)*(x-0.3)*(x-0.3)-5*x+x*x-2;
	}
	
	public double acceptanceProbability(double energy, double newEnergy, double temperature) {
		
		if( newEnergy > energy ) {
			return 1;
		}
		
		return Math.exp((energy-newEnergy)/temperature);
	}
}
