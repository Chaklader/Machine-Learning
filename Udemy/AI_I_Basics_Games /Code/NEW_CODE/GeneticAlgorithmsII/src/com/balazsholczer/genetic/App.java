package com.balazsholczer.genetic;


public class App {

	public static void main(String[] args) {
		
		GeneticAlgorithms geneticAlgorithms = new GeneticAlgorithms();
		
		Population population = new Population(100);
		population.initialize();
		
		int generationCounter = 0;
		
		while( generationCounter != Constants.SIMULATION_LENGTH ) {
			
			++generationCounter;
			System.out.println("Generation: " + generationCounter + " - fittest is: " + population.getFitestIndividual().getFitness());
			System.out.println(population.getFitestIndividual()+"\n");
			population = geneticAlgorithms.evolvePopulation(population);
		}
		
		System.out.println("Solution found!!!");
		System.out.println(population.getFitestIndividual());
	}
}
