package DepthFirstSearch;
import java.util.List;
import java.util.Stack;


public class DepthFirstSearch {
	
//	private Stack<Vertex> stack;
//	
//	public DepthFirstSearch(){
//		this.stack=new Stack<>();
//	}
//	
//	public void dfsRecursive(Vertex vertex){
//		
//		System.out.print(vertex+"->");
//		
//		for( Vertex v : vertex.getNeighbourList() ){
//			if( !v.isVisited() ){
//				v.setVisited(true);
//				dfsRecursive(v);
//			}
//		}
//	}
//	
//	public void dfsNormal(Vertex root){
//		
//		stack.add(root);
//		root.setVisited(true);	
//		
//		while( !stack.isEmpty() ){
//			
//			Vertex actualVertex = stack.pop();
//			System.out.print(actualVertex+"->");
//			
//			for( Vertex v : actualVertex.getNeighbourList() ){
//				if( !v.isVisited() ){
//					v.setVisited(true);
//					stack.push(v);
//				}
//			}
//		}	
//	}
	
	private List<Vertex> vertexList;
	private int time = 0;
	
	public DepthFirstSearch(List<Vertex> vertexList){
		this.vertexList = vertexList;
	}
	
	public void runDfs(){
		for( Vertex vertex : vertexList ){
			if( !vertex.isVisited() ){
				dfs(vertex);
			}
		}
	}
	
	public void dfs(Vertex vertex){
		
		System.out.print(vertex.getName()+"-");
		
		time++;
		vertex.setStartingRank(time);
		
		for( Vertex v : vertex.getNeighbourList() ){
			if( !v.isVisited() ){
				v.setVisited(true);
				v.setPredecessor(vertex);
				dfs(v);
			}
		}
		
		time++;
		vertex.setFinishingRank(time);	
	}
	
	public void printVertices(){
		for(Vertex vertex : vertexList){
			System.out.println(vertex+"");
		}
	}
}
