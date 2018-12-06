import java.util.Random;


public class Game {

	private Board board;
	private Random random;
	
	public Game(){
		initializeGame();
		displayBoard();
		makeFirstMove();
		playGame();
		checkStatus();
	}
	
	private void checkStatus() {
		if (board.isWinning(Player.COMPUTER)) {
	        System.out.println("Computer has won");
	    } else if (board.isWinning(Player.USER)) {
	        System.out.println("Player has won");
	    } else {
	        System.out.println("It's a draw!");
	    }
	}

	private void playGame() {
		
		while ( board.isRunning() ) {
			
	        System.out.println("User move: ");
	        Cell userCell = new Cell(board.getScanner().nextInt(), board.getScanner().nextInt());

	        board.move(userCell, Player.USER); 
	        board.displayBoard();
	        
	        if (!board.isRunning()) {
	            break;
	        }
	        
	        board.callMinimax(0, Player.COMPUTER);
	        
	        for (Cell cell : board.getRootValues()) {
	            System.out.println("Cell values: " + cell + " minimaxValue: " + cell.getMinimaxValue());
	        }
	        
	        board.move(board.getBestMove(), Player.COMPUTER);
	        board.displayBoard();
	    }
	}

	private void makeFirstMove() {
		
		System.out.println("Who starts? 1 - Computer ; 2 - User"); 
	    int choice = board.getScanner().nextInt();
	    
	    if(choice == 1){
	        Cell cell = new Cell(random.nextInt(Constants.BOARD_SIZE), random.nextInt(Constants.BOARD_SIZE));
	        board.move(cell, Player.COMPUTER);
	        board.displayBoard();
	    }
	}

	private void displayBoard() {
		 board.displayBoard();
	}

	private void initializeGame() {
		this.board = new Board();
		this.board.setupBoard();
	    this.random = new Random();
	}
}
