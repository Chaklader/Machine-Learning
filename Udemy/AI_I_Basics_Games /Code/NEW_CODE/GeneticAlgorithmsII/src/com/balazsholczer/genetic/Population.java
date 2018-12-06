package com.balazsholczer.genetic;

public class Population {

	private Individual[] individuals;
	
	public Population(int populationSize) {
		individuals = new Individual[populationSize];
	}
	
	public void initialize() {
		for(int i=0;i<individuals.length;++i) {
			Individual newIndividual = new Individual();
			newIndividual.generateIndividual();
			saveIndividual(i, newIndividual);
		}
	}
	
	public Individual getIndividual(int index) {
		return this.individuals[index];
	}
	
	public Individual getFitestIndividual() {
		
		Individual fittest = individuals[0];
		
		for(int i=1;i<individuals.length;++i) {
			if( getIndividual(i).getFitness() < fittest.getFitness() )
				fittest = getIndividual(i);
		}
		
		return fittest;
	}
	
	public int size() {
		return this.individuals.length;
	}
	
	public void saveIndividual(int index, Individual individual) {
		this.individuals[index] = individual;
	}
	
}
