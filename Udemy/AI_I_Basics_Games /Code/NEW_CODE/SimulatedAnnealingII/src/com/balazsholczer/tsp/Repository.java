package com.balazsholczer.tsp;

import java.util.ArrayList;
import java.util.List;

public class Repository {

	private static List<City> cities = new ArrayList<>();
	
	public static void addCity(City city) {
		cities.add(city);
	}
	
	public static City getCity(int index) {
		return cities.get(index);
	}
	
	public static int getNumberOfCities() {
		return cities.size();
	}
}
