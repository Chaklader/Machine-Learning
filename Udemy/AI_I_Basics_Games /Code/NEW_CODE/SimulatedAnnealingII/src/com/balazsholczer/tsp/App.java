package com.balazsholczer.tsp;

public class App {

	public static void main(String[] args) {
		
		for(int i=0;i<5;i++) {
			City city = new City();
			Repository.addCity(city);
		}
			
		SimulatedAnnealing annealing = new SimulatedAnnealing();
		annealing.simulation();
		
		System.out.println("Final approximated solution's distance is: " + annealing.getBest().getDistance());
		System.out.println("Tour: " + annealing.getBest());
	}
}
