package com.balazsholczer.geneticalgorithms;


public class Population {

    private Individual[] individuals;
    
    public Population(int populationSize) {
        individuals = new Individual[populationSize];
    }
    
    public void initialize(){
    	for (int i = 0; i < size(); i++) {
            Individual newIndividual = new Individual();
            newIndividual.generateIndividual();
            saveIndividual(i, newIndividual);
        }
    }

    public Individual getIndividual(int index) {
        return this.individuals[index];
    }

    // O(N) 
    public Individual getFittest() {
        
    	Individual fittestIndividual = individuals[0];
       
        for (int i = 0; i < size(); ++i) {
            if ( fittestIndividual.getFitness() <= getIndividual(i).getFitness()) {
                fittestIndividual = getIndividual(i);
            }
        }
        
        return fittestIndividual;
    }

    public int size() {
        return this.individuals.length;
    }

    public void saveIndividual(int index, Individual individual) {
        this.individuals[index] = individual;
    }
}
