package com.balazsholczer.genetic;

import java.security.AlgorithmConstraints;

public class App {

	public static void main(String[] args) {
		
		GeneticAlgorithms geneticAlgorithms = new GeneticAlgorithms();
		
		Population population = new Population(100);
		population.initialize();
		
		int generationCounter = 0;
		
		while( population.getFitestIndividual().getFitness() != Constants.MAX_FITNESS ) {
			
			++generationCounter;
			System.out.println("Generation: " + generationCounter + " - fittest is: " + population.getFitestIndividual().getFitness());
			System.out.println(population.getFitestIndividual()+"\n");
			population = geneticAlgorithms.evolvePopulation(population);
		}
		
		System.out.println("Solution found!!!");
		System.out.println(population.getFitestIndividual());
	}
}
