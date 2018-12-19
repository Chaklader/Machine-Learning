package com.balazsholczer.sa;

import java.util.Random;

public class SimulatedAnnealing {

	private Random randomGenerator;
	private double currentCoordinateX;
	private double nextCoordinateX;
	private double bestCoordinateX;
	
	public SimulatedAnnealing(){
		this.randomGenerator = new Random();
	}
	
	public void findOptimum(){
		
		double temperature = Constants.START_TEMPERATURE;
		
		while( temperature > Constants.MIN_TEMPERATURE ){
			
			nextCoordinateX = getRandomX();
			
			double currentEnergy = getEnergy(currentCoordinateX);
			double newEnergy = getEnergy(nextCoordinateX);
			
			
			if( acceptanceProbability(currentEnergy, newEnergy, temperature) > Math.random() ){
				currentCoordinateX = nextCoordinateX;
			}
			
			if( f(currentCoordinateX) < f(bestCoordinateX)){
				bestCoordinateX = currentCoordinateX;
			}
			
			temperature *= 1 - Constants.COOLING_RATE;	
		}
		
		System.out.println("Global extremum is: x="+bestCoordinateX +  "f(x) = " + f(bestCoordinateX));
		
	}

	private double getEnergy(double x) {
		return f(x);
	}

	private double getRandomX() {
		return randomGenerator.nextDouble()*(Constants.MAX_COORDINATE - Constants.MIN_COORDINATE) + Constants.MIN_COORDINATE;
	}

	private double f(double x){
		return (x-0.3)*(x-0.3)*(x-0.3)-5*x+x*x-2;
	}
	
	public double acceptanceProbability(double energy, double newEnergy, double temperature) {
		
		// If the new solution is better, accept it
		if (newEnergy < energy) {
			return 1.0;
		}
		
		// If the new solution is worse, calculate an acceptance probability
		// T is small: we accept worse solutions with lower probability !!!
		return Math.exp((energy - newEnergy) / temperature);
	}
}
